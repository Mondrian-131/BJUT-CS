#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

int main()
{   
    int n; cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b,c; cin>>a>>b>>c;
        if(c==a*b) cout<<"Lv Yan"<<endl;
        else if(c==a+b) cout<<"Tu Dou"<<endl;
        else cout<<"zhe du shi sha ya!"<<endl;
    }
    return 0;
}