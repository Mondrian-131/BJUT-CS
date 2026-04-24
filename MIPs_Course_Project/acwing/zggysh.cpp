#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 5e5+10;
int n,m;

ll a[N];
struct node{
    int l,r;
    ll sum ;
    ll d;
}tr[N<<2];

void push_up(int u)
{
    auto & rt = tr[u], &l=tr[u<<1],&r=tr[u<<1|1];
    rt.d  = __gcd(l.d,r.d);
    rt.sum = l.sum + r.sum;
}

void update(int u,int x,ll k)
{
    if(tr[u].l==tr[u].r) {
        tr[u].d += k; 
        tr[u].sum += k;
    }
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(x<=mid) update(u<<1,x,k);
        else update(u<<1|1,x,k);
        push_up(u);
    }
}

void build(int u,int l,int r)
{
    if(l==r) tr[u] = {l,l,a[l],a[l]};
    else{
        tr[u]={l,r};
        int mid = l+r>>1;
        build(u<<1,l,mid); build(u<<1|1,mid+1,r);
        push_up(u);
    }
}
 
// 维护多个值 
node query(int u,int l,int r)
{
    if(tr[u].l>=l && tr[u].r<=r) return tr[u];

    int mid = tr[u].l + tr[u].r >>1;

    if(l>mid) return query(u<<1|1,l,r);
    if(r<=mid) return query(u<<1,l,r);
    
    node left = query(u<<1,l,r);
    node right = query(u<<1|1,l,r);
    node res;
    
    res.sum = left.sum + right.sum;
    res.d = __gcd(left.d,right.d);
    return res;
}


int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        a[i]=a[i]-a[i-1];
    }
    
    build(1,1,n);

    while(m--)
    {
        char op ;cin>>op;
        if(op=='C'){
            int l,r;
            ll d;
            cin>>l>>r>>d;
            update(1,l,d);
            update(1,r+1,-d);
        }
        else{
            int l,r ;cin>>l>>r;
            node left = query(1,1,l);
            node right = {0,0,0,0};
            if(l+1<=n)  right = query(1,l+1,r);
            cout<<abs(__gcd(left.sum,right.d));
        }
    }

    return 0;
}