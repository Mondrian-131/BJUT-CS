#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;
int l,n;

int a[5][5];
int cnt ;

void dfs(int x,int y)
{
    if(x>=1 && x<=n-1 && y>=1 && y<=n-1)
    {
        for(int i=0;i<10;i++)
        {
            a[x][y] = i;
            dfs(x+1,y);
        }
    }
    else if(y>=1 && y<=n-1 && x==n){
        int sum = 0 ;
        for(int i=1;i<=n-1;i++) sum+=a[i][y];
        if(sum>l) return ;
        a[x][y] = l - sum;
        dfs(1,y+1);
    }
    else if(y==n) {
        for(int i=1;i<=n;i++)
        {
            int sum = 0;
            for(int j=1;j<=n-1;j++) sum+=a[i][j];
            if(sum>l) return ;
            a[i][n] = l - sum;
        }
        int sum = 0;
        for(int i=1;i<=n;i++) sum+=a[n][i];
        if(sum!=l) return ;
        cnt++;
    }
}

int main()
{
    cin>>l>>n;

    dfs(1,1);
    
    cout<<cnt<<endl;
    
    return 0;
}