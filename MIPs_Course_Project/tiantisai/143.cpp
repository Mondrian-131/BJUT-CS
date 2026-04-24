#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;
int n;

int din[N];
int h[N],e[N],ne[N],idx;

void add(int a,int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int ans;
int maxv;

void dfs(int u,int dep)
{
    if(h[u]==-1) {
        if(dep>maxv)
        {
            maxv = dep;
            ans = u;
        }
        return ;
    }

    for(int i=h[u];~i;i=ne[i]) dfs(e[i],dep+1);
}

int main()
{
    cin>>n;
    memset(h,-1,sizeof h);

    for(int i=1;i<=n;i++)
    {
        int k; cin>>k;
        for(int j=1;j<=k;j++)
        {
            int x; cin>>x;
            add(i,x);
            din[x]++;
        }
    }

    int root; 
    for(int i=1;i<=n;i++)
    {
        if(!din[i]) 
        {
            root = i;
            break;
        }
    }

    dfs(root,1);    

    cout<<ans<<endl;

    return 0;
}