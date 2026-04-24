#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 3000, M = 7000;

int h[N],e[M*2],ne[M*2],idx,w[M*2];

void add(int a,int b,int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}

int dist[N];
bool st[N];

int C,T,bg,ed;

int dijkstra()
{
    memset(dist,0x3f,sizeof dist);
    dist[bg] = 0;
    
    priority_queue<pii,vector<pii>,greater<pii>> heap;
    
    heap.push({0,bg});
    
    while(heap.size())
    {
        auto t = heap.top();
        heap.pop();
        
        int d = t.first, ver = t.second;
        
        if(st[ver]) continue;
        else st[ver] = 1;
        
        for(int i=h[ver];~i;i=ne[i])
        {
            int j=  e[i];
            if(dist[j] > dist[ver] + w[i]) 
            {
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j],j});
            }
        }
    }
    
    if(dist[ed]==0x3f3f3f3f) return -1;
    else return dist[ed];
}


int main()
{
    cin>>T>>C>>bg>>ed;
    
    memset(h,-1,sizeof h);
    for(int i=1;i<=C;i++)
    {
        int a,b,c; cin>>a>>b>>c;
        add(a,b,c);add(b,a,c);
    }
    
    cout<<dijkstra()<<endl;
    return 0;
}
