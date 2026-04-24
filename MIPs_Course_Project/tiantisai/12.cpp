#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

int qmi(int a,int k)
{
    int res = 1;
    while(k)
    {
        if(k&1) res=res*a;
        a = a*a;
        k>>=1;
    }
    return res;
}

int main()
{
    int n; cin>>n;
    
    printf("2^%d = %d",n,qmi(2,n));
    return 0;
}