#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 30+10;

int n; 
int in[N];
int pre[N];

int idx;

struct node{
    int l,r;
    int key;
}tr[N];

int build(int li,int ri,int lp,int rp)
{
    if(li > ri || lp > rp) return -1;

    int val = pre[lp];
    int root = idx++;
    tr[root].key = val;
    int p = li;
    while(in[p]!=val) p++;

    int cnt = p - li;
    tr[root].l = build(li,p-1,lp+1,lp+cnt);
    tr[root].r = build(p+1,ri,lp+cnt+1,rp);

    return root;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>in[i];
    for(int i=1;i<=n;i++) cin>>pre[i];

    int root = build(1,n,1,n);

    queue<int> q;
    vector<int> ans;
    q.push(root);

    while(q.size())
    {
        int t = q.front();
        q.pop();
        ans.push_back(tr[t].key);

        if(~tr[t].r) q.push(tr[t].r);
        if(~tr[t].l) q.push(tr[t].l);
    }

    for(int i=0;i<ans.size();i++)
    {
        if(i) cout<<" ";
        cout<<ans[i];
    }
    return 0;
}