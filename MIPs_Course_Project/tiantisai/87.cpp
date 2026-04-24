#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

bool row[N];
bool col[N];

int main()
{
    int n,m,q; cin>>n>>m>>q;

    ll total = (ll)n*m;

    ll sum = 0;

    for(int i=1;i<=q;i++)
    {
        int t,c; cin>>t>>c;
        if(!t) row[c]=1;
        else col[c]=1;
    }

    ll s_r = 0;
    ll s_c =0;

    for(int i=1;i<=n;i++)
    {
        if(row[i]) s_r++;
    }

    for(int i=1;i<=m;i++)
    {
        if(col[i]) s_c++;
    }

    sum = s_r*m + s_c*n - s_r*s_c;

    cout<<total-sum<<endl;
    return 0;
}