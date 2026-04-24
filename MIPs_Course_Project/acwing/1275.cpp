#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 2e5+10;

int m,p; 
int cnt;
struct node{
    int l,r;
    int maxv;
}tr[N*4];

void build(int u,int l,int r)
{
    if(l==r) tr[u]={l,r};
    else{
        tr[u]={l,r};
        int mid = l+r>>1;
        build(u<<1,l,mid); build(u<<1|1,mid+1,r);
    }
}

int query(int u,int l,int r)
{
    if(tr[u].l>=l && tr[u].r<=r) return tr[u].maxv;
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        int v = 0;
        if(l<=mid) v = max(v,query(u<<1,l,r));
        if(r>mid) v= max(v,query(u<<1|1,l,r));
        return v;
    }
}

void update(int u,int x,int k)
{
    if(tr[u].l == tr[u].r) tr[u].maxv = k;
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(x<=mid) update(u<<1,x,k);
        else update(u<<1|1,x,k);
        tr[u].maxv = max(tr[u<<1].maxv,tr[u<<1|1].maxv);
    }
}

int main()
{
    cin>>m>>p;
    build(1,1,N-1);
    int q = 0;
    while(m--)
    {
        char op; cin>>op;
        if(op=='Q')
        {
            int l; cin>>l;
            cout<<(q=query(1,cnt-l+1,cnt))<<endl;
        }
        else{
            int t; cin>>t;
            cnt++;  
            t=((ll)t+q)%p;
            update(1,cnt,t);
        }
    }
    return 0;
}