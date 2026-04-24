#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 50+10;

int post[N];
int in[N];
int idx;
int lt[N],rt[N];
int v[N];

int build(int ia,int ib,int pa,int pb)
{
    if(ia > ib || pa > pb) return -1;

    int root = idx++;

    v[root]=  post[pb];

    int p = ia;
    while(in[p]!=v[root]) p++;
    
    int cnt = p - ia;

    lt[root] = build(ia,p-1,pa,pa+cnt-1);
    rt[root] = build(p+1,ib,pa+cnt,pb-1);
    
    return root;
}

int main()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>post[i];
    for(int i=1;i<=n;i++) cin>>in[i];    

    int root = build(1,n,1,n);

    vector<int> ans;
    queue<int> q;
    q.push(root);

    while(q.size())
    {
        int t = q.front();
        q.pop();

        ans.push_back(v[t]);
        if(lt[t]!=-1) q.push(lt[t]);
        if(rt[t]!=-1) q.push(rt[t]);
    }

    for(int i=0;i<ans.size();i++)
    {
        if(i) cout<<" ";
        cout<<ans[i];
    }
    return 0;
}