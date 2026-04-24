#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

int sum[15];

int main()
{
    string s;
    cin>>s;

    for(int i=0;i<s.size();i++)
    {
        sum[s[i]-'0'] ++;
    }

    for(int i=0;i<10;i++)
    {
        if(sum[i]) cout<<i<<":"<<sum[i]<<endl;
    }


    return 0;
}