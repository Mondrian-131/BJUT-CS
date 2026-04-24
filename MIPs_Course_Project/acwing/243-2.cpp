#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

ll a[N];

struct node{
    int l,r;
    ll sum,tag;
}tr[N*4];


void build(int u,int l,int r)
{
    if(l==r) tr[u]={l,l,a[l],0};
    else{
        tr[u] = {l,r};
        int mid = l+ r>>1;
        build(u<<1,l,mid); build(u<<1|1,mid+1,r);
        tr[u].sum = tr[u<<1].sum + tr[u<<1|1].sum;
    }
}

void push_down(int u)
{
    auto & root = tr[u], &left = tr[u<<1], &right=tr[u<<1|1];
    if(root.tag)
    {
        left.sum += (left.r-left.l+1ll)*root.tag;
        left.tag += root.tag;
        right.sum += (right.r-right.l+1ll)* root.tag;
        right.tag+= root.tag;
        root.tag=0;
    }
}

void update(int u,int l,int r,int k)
{
    if(tr[u].l>=l && tr[u].r <= r) {
        tr[u].sum += 1ll* k* (tr[u].r- tr[u].l + 1);
        tr[u].tag += k;
    }
    else{
        push_down(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l<=mid) update(u<<1,l,r,k);
        if(r>mid) update(u<<1|1,mid+1,r,k);
        tr[u].sum = tr[u<<1].sum + tr[u<<1|1].sum;
    }
}

ll query(int u,int l,int r)
{
    if(tr[u].l>=l && tr[u].r<=r){
        return tr[u].sum;
    }
    else{
        push_down(u);
        int mid = tr[u].l + tr[u].r >> 1;
        ll sum = 0;
        if(l<=mid) sum+=query(u<<1,l,r);
        if(r>mid) sum+=query(u<<1|1,l,r);
        return sum;
    }
}

int n,m;
int main()
{
    cin>>n>>m;
    
    for(int i=1;i<=n;i++) cin>>a[i];

    build(1,1,n);

    while(m--)
    {
        char op; cin>>op;
        if(op=='C') {
            int l,r,d; cin>>l>>r>>d;
            update(1,l,r,d);
        }
        else{
            int l,r; cin>>l>>r;
            cout<<query(1,l,r)<<endl;
        }
    }
    return 0;
}