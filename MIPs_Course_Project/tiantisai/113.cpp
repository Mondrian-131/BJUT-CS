#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 500+10;
typedef pair<int,int> pii;

int cnt[N];
int n,m,s,d;

int h[N],e[N*N],ne[N*N],w[N*N],idx;

int dist[N];
bool st[N];

void add(int a,int b,int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}

int dijkstra()
{
    memset(dist,0x3f,sizeof dist);
    priority_queue<pii,vector<pii>,greater<pii>> heap;
    dist[s]=0;
    heap.push({0,s});

    while(heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int dis = t.x, num=t.y;

        if(!st[num]) st[num]=1;
        else continue;

        for(int i=h[num];~i;i=ne[i])
        {
            int j = e[i];
            if(dist[j]>dis+w[i]) 
            {
                dist[j] = dis + w[i];
                heap.push({dist[j],j});
            }
        }
    }

    if(dist[d]==0x3f3f3f3f) return -1;   
    else return dist[d];
}

vector<int> path;
vector<int> ans;

int tot;
int max_v;
// s - > d len
void dfs(int u,int len)
{
    if(u==s && len==0){
        tot++;
        int sum =0; 
        for(int i=0;i<path.size();i++) {
            sum+=cnt[path[i]];
        }
        if(sum>max_v) {
            max_v = sum;
            ans = path; 
        }
        return;
    }

    for(int i=h[u];~i;i=ne[i]) {
        int j = e[i];
        if(dist[j]==len-w[i]) {
            path.push_back(j);
            dfs(j,len-w[i]);
            path.pop_back();
        }
    }
}

int main()
{
    cin>>n>>m>>s>>d;
    
    memset(h,-1,sizeof h);
    for(int i=0;i<n;i++) cin>>cnt[i];

    while(m--)
    {
        int a,b,len; cin>>a>>b>>len;
        add(a,b,len); add(b,a,len);
    }

    
    int dis = dijkstra();

    path.push_back(d);

    dfs(d,dis);

    cout<<tot<<" "<<max_v<<endl;

    for(int i=ans.size()-1;i>=0;i--)
    {
        if(i) cout<<ans[i]<<" ";
        else cout<<ans[i];
    }
    return 0;
}