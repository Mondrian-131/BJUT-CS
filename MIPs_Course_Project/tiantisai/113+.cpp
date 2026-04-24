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
int val[N];
int num[N];
int pre[N];

void dijkstra()
{
    memset(dist,0x3f,sizeof dist);
    dist[s] = 0;
    priority_queue<pii,vector<pii>,greater<pii>> heap;
    heap.push({0,s});
    val[s] = cnt[s];
    num[s] = 1;

    
    while(heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int d = t.x, ver = t.y;

        if(st[ver]) continue;
        else st[ver] = 1;

        for(int i=h[ver];~i;i=ne[i])
        {
            int j = e[i];
            if(dist[j]>d+w[i]){
                pre[j] = ver;
                dist[j] = d+w[i];
                heap.push({dist[j],j});
                val[j] = val[ver] + cnt[j];
                num[j] = num[ver];
            }
            else if(dist[j]==d+w[i])
            {
                if(val[j]<val[ver]+cnt[j]) {
                    val[j] = val[ver]+cnt[j];
                    pre[j] = ver;
                }
                num[j]+=num[ver];
            }
        }
    }
    
}

void add(int a,int b,int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
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


    dijkstra();

    cout<<num[d]<<" "<<val[d]<<endl;
    
    vector<int> path;
    int cur = d;
    while(cur!=s)
    {
        path.push_back(cur);
        cur = pre[cur];
    }

    cout<<s<<" ";
    for(int i=path.size()-1;i>=0;i--)
    {
        cout<<path[i];
        if(i) cout<<" ";
    }

    return 0;
}