#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e2+10;

int g[N*N][N];
int n,m;
int a[N*N];

bool cmp(int a,int b)
{
    for(int i=1;i<=m;i++)
    {
        if(g[a][i]!=g[b][i]) return g[a][i]<g[b][i];
    }
    return false;
}

bool eq(int a,int b)
{
    for(int i=1;i<=m;i++)
    {
        if(g[a][i]!=g[b][i]) return false;
    }
    return true;
}

bool cmp2(pair<int,int> a,pair<int,int> b)
{
    if(a.x != b.x) return a.x>b.x;
    return cmp(a.y,b.y);
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        a[i] = i;
        for(int j=1;j<=m;j++) cin>>g[i][j];
    }
    sort(a+1,a+n+1,cmp);
    
    vector<pair<int,int>> vec;
    for(int i=1;i<=n;i++)
    {
        int cnt = 0;
        int j = i;
        while(j<=n && eq(a[j],a[i])) j++,cnt++;
        vec.push_back({cnt,a[i]});
        i = j-1;
    }

    sort(vec.begin(),vec.end(),cmp2);

    cout<<vec.size()<<endl;
    for(auto t : vec)
    {
        cout<<t.x;
        for(int i=1;i<=m;i++)
        {
            cout<<" "<<g[t.y][i];
        }
        cout<<endl;
    }
    return 0;
}