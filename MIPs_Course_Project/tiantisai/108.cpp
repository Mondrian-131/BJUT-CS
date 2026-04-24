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
    ll ans = 1;
    int n; cin>>n;
    for(int i=1;i<=31;i++)
    {
        if(ans<=n && ans*2>n) 
        {
            cout<<ans<<endl;
            break;
        }
        ans = ans * 2;
    }
    return 0;
}