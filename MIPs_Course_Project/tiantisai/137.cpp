#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e4+10;

int n,m;
int h[N],e[N*2],ne[N*2],idx;
int v[N];

void add(int a,int b)
{
    e[idx] =b;
    ne[idx] = h[a];
    h[a] = idx++;
}


bool check(int u)
{
    int sum = 0;
    for(int i=h[u];~i;i=ne[i])
    {
        int j = e[i];
        if(v[j]) continue;
        else sum ++;
    }
    if(sum>0) return false;
    else return true;
}

int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof h); 

    while(m--)
    {
        int a,b; cin>>a>>b;
        add(a,b); add(b,a);
    }

    int k; cin>>k;
    while(k--)
    {
        int np; cin>>np;
        memset(v,0,sizeof v);
        for(int i=1;i<=np;i++) 
        {
            int x; cin>>x; v[x] = 1;
        }

        bool flag = 1;
        for(int i=1;i<=n;i++)
        {
            if(v[i]) continue;
            if(!check(i))
            {
                flag = 0;
                break;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}