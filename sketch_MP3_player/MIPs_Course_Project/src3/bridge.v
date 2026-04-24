module bridge (
    input  wire [31:0] praddr,     // CPU访问地址
    input  wire [31:0] prwd,       // CPU写入数据

    input  wire [31:0] indevice_rd,    // 输入设备读数据

    input  wire        wen,        // 写使能

    input  wire        irq,        // Timer中断请求

    output wire [31:0] prrd,       // 最终返回给CPU的数据

    output wire [31:0] out_wd,     // 给外设的数据

    output wire        timer_we,    // Timer写使能

    output wire        outdevice_we,    // 输出设备写使能

    output wire [7:2]  hwint   ,    // 将设备中断传给cp0

    output wire [1:0] timer_addr,

    input wire [31:0] outdevice_rd 
);

    // 外设地址匹配
    wire hittimer = (praddr == 32'h00007f00 || praddr == 32'h00007f04 || praddr == 32'h00007f08); // 定时器
    
    wire hitoutdevice = (praddr == 32'h00007f24);  // 输出设备

    // 写使能信号
    assign timer_we = hittimer && wen;
    assign outdevice_we = hitoutdevice && wen;

    // 写数据直接转发
    assign out_wd = prwd;

    // 读取返回值选择(从输入设备读取或者输出设备读取)
    assign prrd =  (hitoutdevice==1'b1) ? outdevice_rd: indevice_rd;

    // 中断信号打包给 CP0，只使用 HWInt[2]
    assign hwint = {5'b00000, irq};  // 只用 HWInt[2]

    // 写给timer的选择喜好
    assign timer_addr = praddr[3:2];

endmodule
