#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;
int n;
double z,r;

int h[N],e[N],ne[N],idx;
void add(int a,int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}


int w[N];

double dfs(int u,double fang)
{
    double sum = 0;
    if(w[u]) sum+=w[u]*fang;
    for(int i=h[u];~i;i=ne[i]) sum += dfs(e[i],fang*(100-r)/100);
    return sum;
}

int main()
{
    cin>>n>>z>>r;
    memset(h,-1,sizeof h);
    for(int i=0;i<n;i++)
    {
        int k; cin>>k;
        if(!k) cin>>w[i];
        else{
            for(int j=0;j<k;j++)
            {
                int x; cin>>x;
                add(i,x);
            }
        }
    }

    double sum = dfs(0,z);

    cout<<(ll)sum<<endl;
    return 0;
}