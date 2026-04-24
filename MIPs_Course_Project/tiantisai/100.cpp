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
    int sum = 0;
    for(int i=1;i<=m;i++)
    {
        int x; cin>>x;
        sum+=x;
    }

    int t = sum/n;
    if(t>=m) cout<<n<<endl;
    else{
        int delta = sum-t*n;        
        int p = m-t-1;
        p = p*n;
        if(delta-p>0) cout<<delta-p<<endl;
        else cout<<0<<endl;
    }
    return 0;
}