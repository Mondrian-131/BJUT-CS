#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 5e2+10;

int g[N][N];
int n,m;
bool st[N];
bool flag[N];

void dfs(int x)
{
    flag[x] = 1;
    for(int i=0;i<n;i++)
    {
        if(g[x][i] && !flag[i] && !st[i]) dfs(i);
    }
}

int main()
{
    cin>>n>>m;

    while(m--)
    {
        int a,b; cin>>a>>b;
        g[a][b] = g[b][a] = 1;
    }

    int cnt = 0; // 连通数块

    for(int i=0;i<n;i++)
    {
        if(!st[i])
        {
            dfs(i);
            cnt++;
        }
    }

    memset(st,0,sizeof st);
    int k; cin>>k;
    for(int i=1;i<=k;i++)
    {
        int ver ;cin>>ver;
        st[ver] = 1; 
        memset(flag,0,sizeof flag);
        int sum = 0;
        for(int j=0;j<n;j++)
        {
            if(!st[j] && !flag[j]) 
            {
                dfs(j);
                sum++;
            }
        }
        if(sum>cnt) printf("Red Alert: City %d is lost!\n",ver);
        else printf("City %d is lost.\n",ver);
        cnt = sum;
        if(i==n) printf("Game Over.\n");
    }

    return 0;
}