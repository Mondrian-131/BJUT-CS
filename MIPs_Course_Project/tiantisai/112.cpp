#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int mod = 998244353;
const int N = 1e3+10;

int g[N][N];
struct BD{
    int val;
    int x, y;
    bool operator<(const BD& W)
    {
        return val<W.val;
    }
}bd[N*N]; 

bool col[N];
bool row[N];

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int idx = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            bd[idx].x = i;
            bd[idx].y = j;
            cin>>g[i][j];
            bd[idx++].val = g[i][j];
        }
    }

    sort(bd,bd+idx);

    int sum = 0;
    for(int i=idx-1;i>=0;i--)
    {
        if(sum==k) break;
        int x = bd[i].x,y=bd[i].y;
        if(!row[x] && !col[y]) {
            row[x]=1;
           col[y]=1;
            sum++;
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(row[i]) continue;
        int sum = 0;
        for(int j=1;j<=m;j++)
        {
            if(col[j]) continue;
            sum++;
            cout<<g[i][j];
            if(sum!=m-k) cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}