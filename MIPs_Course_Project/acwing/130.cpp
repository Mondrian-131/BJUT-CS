#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e6+10;

ll a[N];
ll c[N];
int n;
int q;

int lowbit(int x) { return x&-x;}

ll getsum(int x)
{
    ll ans = 0;
    while(x>0)
    {
        ans += c[x];
        x-=lowbit(x);
    }
    return ans;
}

void add(int x,int k)
{
    while(x<=n)
    {
        c[x] = c[x] + k;
        x += lowbit(x);
    }
}

int main()
{
    cin>>n>>q; 
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) add(i,a[i]);

    while(q--)
    {
        int op;cin>>op;
        int l,r;
        if(op==1)
        {
            int x,k; cin>>x>>k;
            add(x,k);
        }
        else{
            cin>>l>>r;
            cout<<getsum(r)-getsum(l-1)<<endl;
        }
    }
    return 0;
}