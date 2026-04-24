#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 200+10;
int n,m;
int g[N][N];
int v[N];

int main()
{
    cin>>n>>m;

    while(m--)
    {
        int  a,b,c; cin>>a>>b>>c;
        if(a==0 || b==0)
        {
            if(a==0) v[b] = c;
            else v[a] = c;
        }
        else g[a][b] = g[b][a] = c; 
    }

    int k; cin>>k;
    int minv=10000, ver;
    int cnt = 0;
    for(int i=1;i<=k;i++)
    {
        int x; cin>>x;
        int flag = true;
        if(x!=n) flag = false;
        unordered_map<int,int> mp;
        int sum = 0;
        int pre;
        for(int j=1;j<=x;j++)
        {
            int t; cin>>t;
            if(mp.count(t)) flag =false;
            else mp[t] = 1;
            if(j==1) {
                pre = t;
                if(v[t])sum+=v[t];
                else flag = false;
            }
            else if(j==x) {
                if(g[pre][t] && v[t]) sum += g[pre][t]+v[t];
                else flag = false;
            }
            else{
                if(g[pre][t]) sum+=g[pre][t],pre = t;
                else flag = false;
            }
        }
        if(flag){
            cnt++;
            if(minv>sum){
                minv = sum;
                ver = i;
            }
        }
    }


    cout<<cnt<<endl;
    cout<<ver<<" "<<minv<<endl;

    return 0;
}