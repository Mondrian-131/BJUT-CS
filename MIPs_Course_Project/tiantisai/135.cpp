#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 500+10;

int h[N];
int e[N*N],ne[N*N],idx;

int color[N];
int st[N];

void add(int a,int b)
{
    e[idx] = b;
    ne[idx] =h[a];
    h[a] = idx++;
}

int n,m,k;

bool dfs(int u)
{
    st[u] = 1;
    int cc = color[u];
    for(int i=h[u];~i;i=ne[i])
    {
        if(color[e[i]]==cc) return false;
        if(!st[u]) 
        {
            int t = dfs(e[i]);
            if(!t) return false;
        }
    }
    return true;
}

int main()
{
    cin>>n>>m>>k;
    memset(h,-1,sizeof h);

    for(int i=1;i<=m;i++)
    {
        int a,b; cin>>a>>b;
        add(a,b);add(b,a);
    }

    int p ;
    cin>>p;

    for(int i=1;i<=p;i++)
    {
        set<int> ss;
        for(int j=1;j<=n;j++) {
            cin>>color[j];
            ss.insert(color[j]);
        }
        if(ss.size()>k)
        {
            cout<<"No"<<endl;
            continue;
        }

        memset(st,0,sizeof st);
        bool flag = false;
        for(int j=1;j<=n;j++)
        {
            if(!st[j]) 
            {
                int t = dfs(j);
                if(!t) {
                    flag = 1;
                    break;
                }   
            }
        }
        if(flag) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }

    return 0;
}