#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

int n;

struct node{
    int l,r ;
    ll len,cnt;
}tr[8*N];

struct line{
    int l,r;
    int y,tag;
};

vector<line> l;
vector<int> X;

bool cmp(line& a,line&b)
{
    return a.y<b.y; 
}


void build(int u,int l,int r)
{
    tr[u]={l,r,0,0};
    if(l==r) return ;
    int mid = l+r>>1;
    build(u<<1,l,mid); build(u<<1|1,mid+1,r);
}

void push_up(int u)
{
    if(tr[u].cnt) tr[u].len = X[tr[u].r+1]-X[tr[u].l];
    else{
        if(tr[u].l==tr[u].r) tr[u].len = 0;
        else tr[u].len = tr[u<<1].len + tr[u<<1|1].len;
    }
}

void update(int u,int l,int r,int tag)
{
    if(tr[u].l>=l && tr[u].r<=r) tr[u].cnt+=tag;
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(l<=mid) update(u<<1,l,r,tag);
        if(r>mid) update(u<<1|1,l,r,tag);
    }
    push_up(u);
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
        X.push_back(x1);
        X.push_back(x2); 
        l.push_back({x1,x2,y1,1});
        l.push_back({x1,x2,y2,-1});
    }

    sort(X.begin(),X.end());
    X.erase(unique(X.begin(),X.end()),X.end());

    sort(l.begin(),l.end(),cmp);

    build(1,0,X.size()-2);

    ll ans = 0;

    for(int i=0;i+1<l.size();i++)
    {
        int lv = lower_bound(X.begin(),X.end(),l[i].l)-X.begin();
        int rv = lower_bound(X.begin(),X.end(),l[i].r)-X.begin();
        update(1,lv,rv-1,l[i].tag);
        ans+= (l[i+1].y-l[i].y) * tr[1].len;
    }

    cout<<ans<<endl;

    return 0;
}