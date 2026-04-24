#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e6+10;

ll a[N],t1[N],t2[N];
int n,q;

ll lowbit(ll x)
{
    return x&(-x);
}
void add(ll x,ll k)
{
    for(ll i=x;i<=n;i+=lowbit(i))
    {
        t1[i]+=k;
        t2[i]+=(x*k);
    }
}
ll getsum(ll x)
{
    ll ans = 0 ;
    for(ll i=x;i>0;i-=lowbit(i))
    {
        ans+= (x+1ll)*t1[i]-t2[i];
    }
    return ans;
}

int main()
{
    cin>>n>>q;

    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=n;i>=1;i--) {
        add(i,a[i]-a[i-1]);
    }

    while(q--)
    {
        int op ;cin>>op;
        ll l,r,x;
        if(op==1)
        {
            cin>>l>>r>>x;
            add(l,x);
            add(r+1,-x);
        }
        else{
            cin>>l>>r;
            cout<<getsum(r)-getsum(l-1)<<endl;
        }
    }

    return 0;
}