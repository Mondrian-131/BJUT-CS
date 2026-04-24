#define BLINKER_WIFI
#define BLINKER_WITHOUT_SSL
#include <Blinker.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <XPT2046_Touchscreen.h>
#include <RTClib.h>
#include <EEPROM.h>
#include "WT2003S_Player.h"
#include <cstring>


// ================= 1. 引脚与硬件参数定义 =================
#define TFT_DC 10
#define TFT_CS 7
#define TOUCH_CS 0
#define TFT_BL 19

// MP3 串口引脚定义
// 按照你给的示例程序，ESP32-C3 使用 Serial1，RX=GPIO3，TX=GPIO2。
#define MP3_RX_PIN 3
#define MP3_TX_PIN 2

// 按照示例程序，启动后切换到 J2/J3（耳机/扬声器）输出模式。
#define MP3_USE_SPK_OUTPUT 1

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
XPT2046_Touchscreen ts(TOUCH_CS);
RTC_DS1307 rtc;
WT2003S<HardwareSerial> Mp3Player;

char auth[] = "55f944916ec7";
char ssid[] = "vivomd";
char pswd[] = "sunqizhe";

BlinkerButton btnPlay("btn-play");
BlinkerButton btnPrev("btn-prev");
BlinkerButton btnNext("btn-next");
BlinkerButton btnMode("btn-mode");

enum AppState { STATE_NORMAL_PLAY, STATE_SONG_LIST };
AppState currentState = STATE_NORMAL_PLAY;

struct SongInfo {
    uint16_t index;
    char name[32];
};

bool mp3Ready = false;
bool isPlaying = false;
int currentVolume = 1;
int currentSongIndex = 1;
int totalSongs = 0;
unsigned long lastTouchTime = 0;
SongInfo* sdSongs = nullptr;


// 播放模式类型
enum PlayMode {
    MODE_ORDER,
    MODE_LOOP,
    MODE_RANDOM
};

// 当前播放模式
PlayMode currentPlayMode = MODE_ORDER;

// 当前播放状态
uint8_t lastMp3Status = 0x02;   // 0x01播放中 0x02停止 0x03暂停

// 歌曲播放列表相关
const int SONGS_PER_PAGE = 5;
int currentSongListPage = 0;


// ================= 2. 前置声明 =================
void drawUI();
void saveStateToEEPROM();
void loadStateFromEEPROM();
void playSpecificSong();
void togglePlayPause();
void nextMusic();
void prevMusic();
void setVolume(int vol);
void readSDCardSongs();
void readSongNames();
void syncPlayState();
void switchAudioOutputIfNeeded();
const char* getCurrentSongName();

// ================= 3. MP3 相关功能 =================


#include <string.h>




int getRandomSongIndex() {
    if (totalSongs <= 1) return 1;

    int nextIndex = currentSongIndex;
    while (nextIndex == currentSongIndex) {
        nextIndex = random(1, totalSongs + 1);
    }
    return nextIndex;
}

void playCurrentSong() {
    if (totalSongs <= 0) return;

    Mp3Player.playSDRootSong(currentSongIndex);
    saveStateToEEPROM();
    isPlaying = true;
    delay(100);
    lastMp3Status = Mp3Player.getStatus();
    drawUI();
}

void handleSongFinished() {
    if (currentPlayMode == MODE_LOOP) {
        playCurrentSong();
    }
    else if (currentPlayMode == MODE_RANDOM) {
        currentSongIndex = getRandomSongIndex();
        playCurrentSong();
    }
    else {  // MODE_ORDER
        if (currentSongIndex < totalSongs) {
            currentSongIndex++;
            playCurrentSong();
        } else {
            isPlaying = false;
            lastMp3Status = 0x02;
            drawUI();
        }
    }
}


int getTotalSongListPages() {
    if (totalSongs <= 0) return 1;
    return (totalSongs + SONGS_PER_PAGE - 1) / SONGS_PER_PAGE;
}

void openSongListAtCurrentSong() {
    if (currentSongIndex <= 0) currentSongIndex = 1;
    currentSongListPage = (currentSongIndex - 1) / SONGS_PER_PAGE;
}

void selectSongFromList(int songIndex) {
    if (songIndex < 1 || songIndex > totalSongs) return;

    currentSongIndex = songIndex;
    currentState = STATE_NORMAL_PLAY;
    playCurrentSong();   // 如果你这里实际函数名还是 playSpecificSong，就改成那个
}

void updatePlayerState() {
    static unsigned long lastCheckTime = 0;
    if (millis() - lastCheckTime < 200) return;
    lastCheckTime = millis();

    uint8_t status = Mp3Player.getStatus();

    if (lastMp3Status == 0x01 && status == 0x02) {
        handleSongFinished();
        return;
    }

    if (status == 0x01) isPlaying = true;
    else if (status == 0x02 || status == 0x03) isPlaying = false;

    lastMp3Status = status;
}


const char* getPlayModeName() {
    switch (currentPlayMode) {
        case MODE_ORDER:  return "Order";
        case MODE_LOOP:   return "Loop";
        case MODE_RANDOM: return "Random";
        default:          return "Order";
    }
}

void nextPlayMode() {
    if (currentPlayMode == MODE_ORDER) currentPlayMode = MODE_LOOP;
    else if (currentPlayMode == MODE_LOOP) currentPlayMode = MODE_RANDOM;
    else currentPlayMode = MODE_ORDER;
}

void cleanSongName(char *name)
{
    if (name == NULL) return;

    int i;
    for (i = 0; name[i] != '\0'; i++) {
        if (name[i] == '\r' || name[i] == '\n') {
            name[i] = '\0';
            break;
        }
    }

    char *p = strchr(name, '.');
    if (p != NULL) {
        *p = '\0';
    }
}

void switchAudioOutputIfNeeded() {
#if MP3_USE_SPK_OUTPUT
    // 按照示例程序发送切换帧，把输出切到 J2/J3。
    uint8_t switchToSPK[] = {0x7E, 0x04, 0xB6, 0x00, 0xBA, 0xEF};
    Serial1.write(switchToSPK, 6);
    delay(200);
#endif
}

void syncPlayState() {
    if (!mp3Ready) return;
    uint8_t status = Mp3Player.getStatus();
    isPlaying = (status == 0x01);
}

const char* getCurrentSongName() {
    if (sdSongs && currentSongIndex >= 1 && currentSongIndex <= totalSongs) {
        if (sdSongs[currentSongIndex - 1].name[0] != '\0') {
            return sdSongs[currentSongIndex - 1].name;
        }
    }
    return "Unknown";
}

void setVolume(int vol) {
    if (!mp3Ready) return;
    if (vol < 0) vol = 0;
    if (vol > 31) vol = 31;
    currentVolume = vol;
    Mp3Player.volume(currentVolume);
}

void readSDCardSongs() {
    if (!mp3Ready) return;

    uint8_t diskstatus = Mp3Player.getDiskStatus();
    Serial.print("Disk Status Code: ");
    Serial.println(diskstatus);

    if (diskstatus & 0x02) {
        totalSongs = Mp3Player.getSDMp3FileNumber();
        Serial.print("SD Card Song Count: ");
        Serial.println(totalSongs);
    } else {
        totalSongs = 0;
        Serial.println("未检测到 SD 卡或 SD 卡中没有可播放文件");
    }
}

void readSongNames() {
    if (!mp3Ready || totalSongs <= 0) return;

    if (sdSongs) {
        free(sdSongs);
        sdSongs = nullptr;
    }

    sdSongs = (SongInfo*)malloc(sizeof(SongInfo) * totalSongs);
    if (!sdSongs) {
        Serial.println("歌曲名缓存分配失败，跳过歌曲名扫描");
        return;
    }

    for (int i = 0; i < totalSongs; ++i) {
        sdSongs[i].index = i + 1;
        memset(sdSongs[i].name, 0, sizeof(sdSongs[i].name));
    }

    int restoreSong = currentSongIndex;
    int restoreVol = currentVolume;

    Mp3Player.volume(0);
    delay(100);
    Mp3Player.playSDRootSong(1);
    delay(300);

    for (int i = 0; i < totalSongs; ++i) {
        delay(250);
        sdSongs[i].index = Mp3Player.getTracks();
        Mp3Player.getSongName(sdSongs[i].name);
        cleanSongName(sdSongs[i].name); // 去除mp3后面的乱码
        Serial.print("Song ");
        Serial.print(sdSongs[i].index);
        Serial.print(": ");
        Serial.println(sdSongs[i].name);

        if (i != totalSongs - 1) {
            Mp3Player.next();
        }
    }

    // 扫描完成后暂停掉扫描播放
    Mp3Player.pause_or_play();
    delay(100);

    // 恢复原音量
    Mp3Player.volume(restoreVol);
    delay(100);

    // 启动后默认停在记忆曲目，但不自动播放
    if (restoreSong < 1 || restoreSong > totalSongs) restoreSong = 1;
    currentSongIndex = restoreSong;
    Mp3Player.playSDRootSong(currentSongIndex);
    delay(200);
    Mp3Player.pause_or_play();
    delay(100);
    isPlaying = false;
}

void playSpecificSong() {
    if (!mp3Ready || totalSongs <= 0) return;

    if (currentSongIndex < 1) currentSongIndex = 1;
    if (currentSongIndex > totalSongs) currentSongIndex = totalSongs;

    Mp3Player.playSDRootSong(currentSongIndex);
    delay(120);
    isPlaying = true;
    saveStateToEEPROM();
    drawUI();
}

void togglePlayPause() {
    if (!mp3Ready || totalSongs <= 0) return;
    uint8_t status = Mp3Player.getStatus();

    if (status == 0x01 || status == 0x03) {
        Mp3Player.pause_or_play();
        delay(80);

        status = Mp3Player.getStatus();
        isPlaying = (status == 0x01);
        lastMp3Status = status;
    } else {
        playCurrentSong();
        return;
    }

    drawUI();
}

void nextMusic() {
    if (!mp3Ready || totalSongs <= 0) return;
    if (totalSongs <= 0) return;

    if (currentPlayMode == MODE_RANDOM) {
        currentSongIndex = getRandomSongIndex();
    } else {
        currentSongIndex++;
        if (currentSongIndex > totalSongs) currentSongIndex = 1;
    }

    playCurrentSong();
}

void prevMusic() {
    if (!mp3Ready || totalSongs <= 0) return;
    if (totalSongs <= 0) return;

    if (currentPlayMode == MODE_RANDOM) {
        currentSongIndex = getRandomSongIndex();
    } else {
        currentSongIndex--;
        if (currentSongIndex < 1) currentSongIndex = totalSongs;
    }

    playCurrentSong();
}

// ================= 4. EEPROM 掉电记忆功能 =================
void saveStateToEEPROM() {
    EEPROM.write(0, currentSongIndex);
    EEPROM.commit();
}

void loadStateFromEEPROM() {
    currentSongIndex = EEPROM.read(0);
    if (currentSongIndex == 255 || currentSongIndex <= 0) {
        currentSongIndex = 1;
    }
}


void drawClock() {
    if (currentState != STATE_NORMAL_PLAY) return;

    DateTime now = rtc.now();

    // 右上角时间区域，按你现在界面布局预留
    tft.fillRect(185, 8, 125, 20, ILI9341_BLACK);
    tft.setCursor(188, 10);
    tft.setTextSize(2);
    tft.setTextColor(ILI9341_WHITE);
    tft.printf("%02d:%02d:%02d", now.hour(), now.minute(), now.second());
}

// ================= 5. UI 绘制系统 =================
void drawUI() {
    tft.fillScreen(ILI9341_BLACK);
    tft.setTextColor(ILI9341_WHITE);

    if (currentState == STATE_NORMAL_PLAY) {
        tft.setCursor(10, 10);
        tft.setTextSize(2);
        tft.print("MP3 Player");

        tft.setCursor(10, 45);
        tft.setTextSize(2);
        tft.print("Song: ");
        tft.print(currentSongIndex);
        tft.print("/");
        tft.print(totalSongs);

        tft.setCursor(10, 75);
        tft.setTextSize(2);
        tft.print("Status: ");
        tft.print(isPlaying ? "Playing" : "Paused");

        tft.setCursor(80, 105);
        tft.setTextSize(2);
        tft.print("Vol:");
        tft.print(currentVolume);

        tft.fillRect(10, 135, 300, 28, ILI9341_BLACK);
        tft.drawRect(10, 135, 300, 28, ILI9341_DARKCYAN);
        
        // 歌曲名
        tft.setCursor(14, 142);
        tft.setTextSize(2);
        tft.print(getCurrentSongName());

        //播放模式
        tft.fillRect(220, 136, 85, 26, ILI9341_BLACK);
        tft.setCursor(228, 142);
        tft.print(getPlayModeName());

        // 上一首
        tft.drawRect(20, 175, 60, 40, ILI9341_WHITE);
        tft.setCursor(30, 187);
        tft.print("|<");

        // 播放按钮
        tft.drawRect(110, 175, 100, 40, ILI9341_WHITE);
        tft.setCursor(130, 187);
        tft.print(isPlaying ? "PAUSE" : "PLAY");

        // 下一首
        tft.drawRect(240, 175, 60, 40, ILI9341_WHITE);
        tft.setCursor(250, 187);
        tft.print(">|");

        //播放模式按钮
        tft.drawRect(150, 95, 80, 30, ILI9341_CYAN);
        tft.setCursor(162, 102);
        tft.setTextSize(2);
        tft.print("Mode");

        // 音量降低
        tft.drawRect(20, 95, 40, 30, ILI9341_GREEN);
        tft.setCursor(32, 102);
        tft.setTextSize(2);
        tft.print("-");

        // 音量升高
        tft.drawRect(260, 95, 40, 30, ILI9341_GREEN);
        tft.setCursor(272, 102);
        tft.print("+");

        drawClock();
    }
    else if (currentState == STATE_SONG_LIST) {
        tft.setCursor(10, 10);
        tft.setTextSize(2);
        tft.print("Song List");

        tft.setCursor(220, 10);
        tft.print(currentSongListPage + 1);
        tft.print("/");
        tft.print(getTotalSongListPages());

        int startIndex = currentSongListPage * SONGS_PER_PAGE + 1;
        int endIndex = startIndex + SONGS_PER_PAGE - 1;
        if (endIndex > totalSongs) endIndex = totalSongs;

        for (int i = startIndex; i <= endIndex; i++) {
            int row = i - startIndex;
            int y = 35 + row * 30;

            uint16_t boxColor = (i == currentSongIndex) ? ILI9341_YELLOW : ILI9341_WHITE;
            tft.drawRect(10, y, 300, 24, boxColor);

            tft.setCursor(16, y + 5);
            tft.setTextSize(2);
            tft.print(i);
            tft.print(". ");
            tft.print(sdSongs[i - 1].name);
        }

        // 底部按钮
        tft.drawRect(10, 200, 80, 30, ILI9341_RED);
        tft.setCursor(22, 207);
        tft.setTextSize(2);
        tft.print("BACK");

        tft.drawRect(110, 200, 80, 30, ILI9341_GREEN);
        tft.setCursor(126, 207);
        tft.print("PREV");

        tft.drawRect(220, 200, 80, 30, ILI9341_GREEN);
        tft.setCursor(236, 207);
        tft.print("NEXT");
    }
}

// ================= 6. 触摸屏交互逻辑 =================
void handleTouch(int tx, int ty) {
    if (millis() - lastTouchTime < 300) return;
    lastTouchTime = millis();

    if (currentState == STATE_NORMAL_PLAY) {
        if (ty >= 175 && ty <= 225) {
            if (tx < 90) prevMusic();
            else if (tx > 110 && tx < 220) togglePlayPause();
            else if (tx > 235) nextMusic();
        }
        else if (ty >= 90 && ty <= 130) {
            if (tx < 80) {
                setVolume(currentVolume - 1);
                drawUI();
            }
            else if (tx >= 150 && tx <= 230) {
                nextPlayMode();
                drawUI();
            }
            else if (tx > 250) {
                setVolume(currentVolume + 1);
                drawUI();
            }
        }
        else if (ty < 60) {
            currentState = STATE_SONG_LIST;
            drawUI();
        }
    }
    else if (currentState == STATE_SONG_LIST) {
    // 选中当前页某首歌
        if (ty >= 35 && ty < 185) {
            int row = (ty - 35) / 30;
            int songIndex = currentSongListPage * SONGS_PER_PAGE + row + 1;
            if (songIndex <= totalSongs) {
                selectSongFromList(songIndex);
            }
        }
        // BACK
        else if (ty >= 200 && ty <= 230 && tx >= 10 && tx <= 90) {
            currentState = STATE_NORMAL_PLAY;
            drawUI();
        }
        // PREV PAGE
        else if (ty >= 200 && ty <= 230 && tx >= 110 && tx <= 190) {
            if (currentSongListPage > 0) {
                currentSongListPage--;
                drawUI();
            }
        }
        // NEXT PAGE
        else if (ty >= 200 && ty <= 230 && tx >= 220 && tx <= 300) {
            if (currentSongListPage < getTotalSongListPages() - 1) {
                currentSongListPage++;
                drawUI();
            }
        }
    }
}

// ================= 7. Blinker APP 回调响应 =================
void blinkerPlayTap(const String & state) { togglePlayPause(); }
void blinkerPrevTap(const String & state) { prevMusic(); }
void blinkerNextTap(const String & state) { nextMusic(); }
void blinkerModeTap(const String &state) {
    nextPlayMode();
    drawUI();
}



// ================= 8. 初始化设置 =================
void setup() {
    Serial.begin(115200);
    Serial1.begin(9600, SERIAL_8N1, MP3_RX_PIN, MP3_TX_PIN);

    // 初始化 Blinker (如需手机控制可取消注释)
    Blinker.begin(auth, ssid, pswd);
    btnPlay.attach(blinkerPlayTap);
    btnPrev.attach(blinkerPrevTap);
    btnNext.attach(blinkerNextTap);
    btnMode.attach(blinkerModeTap);

    SPI.begin();

    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, HIGH);
    tft.begin();
    tft.setRotation(1);

    ts.begin();
    ts.setRotation(1);

    Wire.begin();

    if (!rtc.begin()) {
        Serial.println("Couldn't find RTC");
        // 不要死循环，否则 MP3 播放器其他功能也不能用了
    } else {
        if (!rtc.isrunning()) {
            Serial.println("RTC is NOT running, set compile time");
            rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
        }

        // 第一次调试时可以临时取消下面这行注释，强制写入编译时间
        // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }

    EEPROM.begin(512);

    delay(1000);

    Mp3Player.init(Serial1);
    delay(200);
    switchAudioOutputIfNeeded();

    mp3Ready = true;

    loadStateFromEEPROM();
    setVolume(currentVolume);
    readSDCardSongs();

    if (totalSongs > 0) {
        if (currentSongIndex > totalSongs) currentSongIndex = 1;
        readSongNames();
    }

    drawUI();
    Serial.println("--- MP3播放器启动完成 ---");

    randomSeed(micros());
}

// ================= 9. 主循环 =================
void loop() {
    Blinker.run();

    if (ts.touched()) {
        TS_Point p = ts.getPoint();
        int mappedX = constrain(map(p.x, 400, 3800, 0, 320), 0, 320);
        int mappedY = constrain(map(p.y, 400, 3600, 240, 0), 0, 240);
        handleTouch(mappedX, mappedY);
    }

    static int lastSecond = -1;
    if (currentState == STATE_NORMAL_PLAY) {
        DateTime now = rtc.now();
        if (now.second() != lastSecond) {
            lastSecond = now.second();
            drawClock();
        }
    }

    updatePlayerState();
}
