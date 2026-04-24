#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e4+10;

int h[N],e[N],ne[N],idx;

void add(int a,int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

vector<int> ans;
int din[N];
int n;
int maxv=-1;
vector<int> res;

void dfs(int u,int dep)
{
    if(h[u]==-1){
        if(dep>maxv) {
            ans = res;
            maxv = dep;
        }
        else if(dep==maxv && res<ans) {
            ans = res;
        }
    }
    else{
        for(int i=h[u];~i;i=ne[i]) {
            res.push_back(e[i]);
            dfs(e[i],dep+1);
            res.pop_back();
        }
    }
}
int main()
{
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=0;i<n;i++)
    {
        int k;cin>>k;
        while(k--)
        {
            int x; cin>>x;
            din[x]++;
            add(i,x);
        }
    }

    int root;
    for(int i=0;i<n;i++)
        if(!din[i]){
            root = i;
            break;
        } 

    res.push_back(root);
    dfs(root,1);

    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
        if(i) cout<<" ";
        cout<<ans[i];
    }
    return 0;
}