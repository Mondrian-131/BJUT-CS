#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e4+10;
int n,m,k;

int ene[110];
int e[N];
int ne[N];
int idx;

int fa[110];

void add(int a,int b)
{
    e[idx] = b;
    ne[idx] = ene[a];
    ene[a] = idx++;
}

int find(int x)
{
    if(fa[x]!=x) fa[x] = find(fa[x]);
    return fa[x];
}

int main()
{
    cin>>n>>m>>k; 
    memset(ene,-1,sizeof ene);
    for(int i=1;i<=n;i++) fa[i]= i;
    while(m--)
    {
        int a,b,c; cin>>a>>b>>c;
        if(c==1) 
        {
            fa[find(a)] = find(b);
        }
        else{
            add(a,b); add(b,a);
        }
    }

    while(k--)
    {
        int a,b;cin>>a>>b;
        bool fr =(find(a)==find(b));
        bool enemy = false;
        for(int i=ene[a];~i;i=ne[i])
        {
            if(e[i]==b) enemy = 1;
        }
        if(fr && !enemy) printf("No problem\n");
        else if(!fr && !enemy) printf("OK\n");
        else if(enemy && fr) printf("OK but...\n");
        else printf("No way\n");
    }
}