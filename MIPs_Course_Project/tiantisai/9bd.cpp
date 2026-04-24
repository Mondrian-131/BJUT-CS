#include<bits/stdc++.h>
using namespace std;
typedef long long ll;//题目中没有看到有理数的范围大小，所以优先考虑大范围的情况
int main(){
    ll n, n1, n2, s1 = 0, s2 = 1;//n是一共有多少个分数，n1,n2分别是新输入的分子与分母， s1, s2分别是目前计算结果的分子和分母
    scanf("%lld", &n); //输入有多少个分数
    while(n -- ){
        scanf("%lld/%lld", &n1, &n2);//我们可以发现，题目给出的输入是格式输入，格式输入通常考虑用scanf来处理
        //对每次输入的新分数与原有结果进行通分运算
         s1 = s1 * n2 + n1 * s2; //分子交叉相乘  注意，分子的计算需要在分母之前
        s2 *= n2; //分母相乘
        ll t = __gcd(s1, s2); //求出计算后分子分母的最大公约数
        s1 /= t, s2 /= t; //分数化简
    }
    ll s = s1 / s2; //s记录分数的整数部分
    s1 = s1 % s2; //s1记录分数的剩余分子， s2记录分数的分母
    // cout << s << ' ' << s1;
    //按照情况划分输出
    if(s == 0){ //如果没有整数
        if(s1 == 0){//并且也没有分数部分
            printf("0");
            return 0; //程序结束
        }else {//没有整数部分，但是分数部分不为0
            printf("%lld/%lld", s1, s2);
            return 0;
        }
    }else {//整数部分不为0
        if(s1 == 0) {//
            printf("%lld", s);
            return 0;
        }
        else {
            printf("%lld %lld/%lld", s, s1, s2);
            return 0;
        }
    }
}