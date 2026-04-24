#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;
int n,m;

string g[N];

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int cnt ;
int ans;

bool dfs(int x,int y)
{
    bool flag = false;
    if(g[x][y]!='1') flag = true;
    g[x][y] = '0';
    for(int i=0;i<4;i++)
    {
        int xx = x + dx[i], yy=y+dy[i];
        if(xx<=n && xx>=1 && yy>=0 && yy<m && g[xx][yy]!='0')  {
            int t = dfs(xx,yy);
            if(t) flag = 1;
        }
    }
    if(flag) return 1;
    else return false;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>g[i];

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<g[i].size();j++)
        {
            if(g[i][j]!='0') {
                int t = dfs(i,j);
                if(t) ans++;
                cnt++;
            }
        }
    }

    cout<<cnt<<" "<<ans;
    return 0;
}