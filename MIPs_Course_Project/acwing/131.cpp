#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e6+10;

ll a[N];
ll t[N];
int n,q; 

int lowbit(int x)
{
    return x&(-x);
}

ll getsum(int x)
{
    ll ans = 0;
    while(x>0)
    {
        ans += t[x];
        x-=lowbit(x);
    }
    return ans;
}
void add(int x,ll k)
{
    while(x<=n)
    {
        t[x]+=k;
        x+=lowbit(x);
    }
}

void add1(int l,int r,ll v)
{
    add(l,v);
    add(r+1,-v);
}

int main()
{
    cin>>n>>q; 
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=n;i>=1;i--) a[i]=a[i]-a[i-1];
    for(int i=1;i<=n;i++) add(i,a[i]);
    while(q--)
    {
        int op ; cin>>op;
        int l,r,x; 
        if(op==1)
        {
            cin>>l>>r>>x;
            add1(l,r,x) ;
        }
        else{
            cin>>x;
            cout<<getsum(x)<<endl;
        }
    }
    return 0;
}