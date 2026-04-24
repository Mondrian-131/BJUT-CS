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
        string s; cin>>s;
        int sum1=0,sum2=0;
        for(int i=0;i<3;i++) sum1+=s[i]-'0';
        for(int i=3;i<6;i++) sum2+=s[i]-'0';
        if(sum1==sum2) cout<<"You are lucky!"<<endl;
        else cout<<"Wish you good luck."<<endl;
    }
    return 0;
}