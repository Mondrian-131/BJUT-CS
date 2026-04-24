#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

int n;

int h[N],ne[N],e[N],idx;

vector<int> member;

void add(int a,int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int minv = 1;   

void dfs(int u,int dep)
{ 
    if(h[u]==-1) 
    {
        if(dep>minv) {
            minv = dep; 
            member.clear();
            member.push_back(u);
        }
        else if(dep==minv)  member.push_back(u);
        return ;
    }
    
    for(int i=h[u];~i;i=ne[i]) dfs(e[i],dep+1);

}

int main()
{
    cin>>n;
    memset(h,-1,sizeof h);
    vector<int> anc;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        if(x==-1) anc.push_back(i);
        else add(x,i); 
    }

    for(auto t: anc) dfs(t,1);

    cout<<minv<<endl;

    sort(member.begin(),member.end());
    for(int i=0;i<member.size();i++)
    {
        if(i) cout<<" ";
        cout<<member[i];
    }
    return 0;

}