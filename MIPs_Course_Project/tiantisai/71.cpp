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
    int n,m; cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        string s; cin>>s;
        int ans = 0;

        for(int i=0;i<s.size();i++)
        {
            int t = ((s[i]=='y') ? 0 : 1);
            ans = ans * 2 + t; 
        }
        cout<<ans+1<<endl;
    }
    return 0;
}