#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// 生成一个分数 a/b，b > 0，a ≠ 0，格式为 "a/b"，负号只出现在 a 上
string gen_fraction() {
    int a = rand() % 201 - 100; // [-100, 100]
    while (a == 0) a = rand() % 201 - 100;

    int b = rand() % 100 + 1; // [1, 100]
    return to_string(a) + "/" + to_string(b);
}

int main() {
    srand(time(0)); // 初始化随机种子

    int n = rand() % 10 + 1; // [1, 100]
    cout << n << endl;

    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << " ";
        cout << gen_fraction();
    }
    cout << endl;

    return 0;
}
