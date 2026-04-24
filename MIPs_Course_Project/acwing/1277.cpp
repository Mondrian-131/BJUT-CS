#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

int n,p,m;
int a[N];

struct node{
    int l,r;
    ll sum; 
    ll add,mul;
}tr[N*4];

void push_up(int u)
{
    auto & root = tr[u],& left = tr[u<<1], & right=tr[u<<1|1];
    root.sum = (left.sum + right.sum ) % p;
}

void build(int u,int l,int r)
{
    if(l==r) tr[u]={l,r,a[l],0,1};
    else{
        tr[u] = {l,r};
        tr[u].mul = 1;
        tr[u].add = 0;
        int mid = l+r>>1;
        build(u<<1,l,mid); build(u<<1|1,mid+1,r);
        push_up(u);
    }
}


void push_down(int u)
{
    auto & root = tr[u], & left = tr[u<<1], & right = tr[u<<1|1];

    left.sum = (left.sum * root.mul %p + (left.l-left.r+1)*root.add % p )% p;
    left.add = left.add * root.mul % p;
    left.mul = left.mul * root.mul % p;
    left.add = (left.add + root.add) % p;

    right.sum = (right.sum * root.mul %p + (right.l-right.r+1)*root.add %p ) %p;
    right.add = right.add * root.mul % p;
    right.mul = right.mul * root.mul % p;
    right.add = (right.add + root.add) %p;

    root.add = 0;
    root.mul = 1;
}

void update(int u,int l,int r,int mul,int add)
{
    if(tr[u].l>=l && tr[u].r <=r) {

        tr[u].sum = (tr[u].sum * mul % p + add) % p; 
        tr[u].add = (tr[u].add*mul)%p ;
        tr[u].mul = (tr[u].mul * mul) %p;
        tr[u].add = (tr[u].add + add) % p;
    }
    else{
        push_down(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l<=mid) update(u<<1,l,r,mul,add);
        if(r>mid) update(u<<1|1,l,r,mul,add);
        push_up(u);
    }
}

ll query(int u,int l,int r)
{
    if(tr[u].l>=l && tr[u].r<=r) {
        return tr[u].sum;
    }
    else{
        push_down(u);
        int mid = tr[u].l + tr[u].r >> 1;
        ll s = 0;
        if(l<=mid) s = (s+query(u<<1,l,r))%p;
        if(r>mid) s= (s+query(u<<1|1,l,r))%p;
        return s;
    }
}

int main()
{
    cin>>n>>p;
    
    for(int i=1;i<=n;i++) cin>>a[i];

    build(1,1,n);

    cin>>m;

    while(m--)
    {
        int op,t,g,c;
        cin>>op;
        if(op==1)
        {
            cin>>t>>g>>c;
            update(1,t,g,c,0);
        }
        else if(op==2)
        {
            update(1,t,g,1,c);
        }
        else{
            cout<<query(1,t,g)<<endl;
        }
    }

    return 0;
}