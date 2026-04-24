#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e4+10;

int n;

int fa[N];

int find(int x)
{
    if(fa[x]!=x) fa[x]=find(fa[x]);
    return fa[x];
}

int main()
{
    cin>>n;
    set<int> cnt;
    for(int i=1;i<=n;i++)
    {
        int k; cin>>k;
        int head;
        for(int j=1;j<=k;j++)
        {
            int x; cin>>x;
            cnt.insert(x);
            if(j==1)
            {
                head = x;
                if(!fa[x]) fa[x] = x;
            }
            else{
                if(!fa[x]) fa[x] = head;
                else fa[find(x)] = head;
            }
        }
    } 

    int sum = 0;
    for(int i=1;i<=1e4;i++)
    {
        if(fa[i]==i) sum++;
    }

    cout<<cnt.size()<<" "<<sum<<endl;

    int q; cin>>q;
    while(q--)
    {
        int a,b; cin>>a>>b;
        if(find(a)==find(b)) cout<<"Y"<<endl;
        else cout<<"N"<<endl;
    }
    return 0;
}