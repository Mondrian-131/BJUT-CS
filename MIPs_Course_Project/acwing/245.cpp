#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 5e5+10;
int n,m;
int a[N];

struct node{
    int l,r;
    int max_v,sum;
    int lmax,rmax;
}tr[N*4];

void push_up(node & root,node &left,node& right)
{
    root.max_v = max(left.rmax + right.lmax,max(left.max_v,right.max_v));
    root.lmax = max(left.lmax,left.sum + right.lmax) ;
    root.rmax = max(right.rmax,right.sum + left.rmax);
    root.sum = left.sum + right.sum;
}


void build(int u,int l,int r)
{
    if(l==r) tr[u]={l,l,a[l],a[l],a[l],a[l]};
    else{
        tr[u] = {l,r};
        int mid = l + r>>1;
        build(u<<1,l,mid); build(u<<1|1,mid+1,r);
        push_up(tr[u],tr[u<<1],tr[u<<1|1]);
    }
}

node query(int u,int l,int r)
{
    if(tr[u].l>=l && tr[u].r <=r ) return tr[u]; 
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(l>mid) return query(u<<1|1,l,r);
        else if(r<=mid) return query(u<<1,l,r);
        else{
            node root; 
            node left = query(u<<1,l,r);
            node right = query(u<<1|1,l,r);
            push_up(root,left,right);
            return root;
        }
    }
}

void update(int u,int x,int k)
{
    if(tr[u].l==tr[u].r) {
        tr[u].lmax = tr[u].rmax = tr[u].sum = tr[u].max_v = k;
    }
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(x<=mid) update(u<<1,x,k);
        else update(u<<1|1,x,k);
        push_up(tr[u],tr[u<<1],tr[u<<1|1]);
    }
}

int main()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++) cin>>a[i];

    build(1,1,n);

    while(m--)
    {
        int k,x,y; cin>>k>>x>>y;
        if(k==1)
        {
            if(x>y) swap(x,y);
            node ans = query(1,x,y);
            cout<<ans.max_v<<endl;
        }
        else{
            update(1,x,y);
        }
    }


    return 0;
}