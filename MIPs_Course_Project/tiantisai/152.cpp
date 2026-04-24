#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

vector<int> g[N];
int n,m;

int cun[110];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int k; cin>>k;
        while(k--){
            int x; cin>>x;
            g[i].push_back(x);
        }
    }

    int bg = 1;
    while(m--)
    {
        int op,t; cin>>op>>t;
        if(!op){
            bg = g[bg][t-1];
        }
        else if(op==1){
            cun[t] = bg;
            cout<<bg<<endl;
        }
        else {
            bg = cun[t];
        }
    }

    cout<<bg;
    return 0;
}