#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;
int n,m;

ll a[N];

struct node{
    int l,r; 
    ll v;
    ll tag;
}tr[N*4];

void push_down(int u)
{
    auto & rt = tr[u], &left=tr[u<<1],&right=tr[u<<1|1];
    if(rt.tag)
    {
        left.tag += rt.tag,left.v += rt.tag*(left.r-left.l+1);
        right.tag += rt.tag,right.v += rt.tag*(right.r-right.l+1);
        rt.tag = 0;
    }
}

ll query(int u,int l,int r)
{
    if(tr[u].l>=l && tr[u].r<=r) return tr[u].v;
    push_down(u);   
    int mid = tr[u].l + tr[u].r >> 1;
    ll sum = 0;
    if(l<=mid) sum +=  query(u<<1,l,r);
    if(r>mid) sum += query(u<<1|1,l,r);
    return sum;
}

void update(int u,int l,int r,ll k)
{
    if(l<=tr[u].l && r>=tr[u].r)    
    {
        tr[u].v += (tr[u].r-tr[u].l+1)*k;
        tr[u].tag += k;
    }
    else{
        push_down(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l<=mid) update(u<<1,l,r,k);
        if(r>mid) update(u<<1|1,l,r,k);
        tr[u].v = tr[u<<1].v + tr[u<<1|1].v ;
    }
}

void build(int u,int l,int r)
{
    if(l==r) tr[u]={l,l,a[l],0};
    else{
        tr[u]={l,r};
        tr[u].tag = 0;
        int mid = l+r>>1;
        build(u<<1,l,mid); build(u<<1|1,mid+1,r);
        tr[u].v = tr[u<<1].v + tr[u<<1|1].v ; 
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;

    for(int i=1;i<=n;i++) cin>>a[i];

    build(1,1,n);

    while(m--)
    {
        int op;cin>>op;
        if(op==1){
            int l,r;ll k; cin>>l>>r>>k;
            update(1,l,r,k);
        }
        else{
            int l,r;cin>>l>>r;
            cout<<query(1,l,r)<<endl;
        }
    }

    return 0;
}