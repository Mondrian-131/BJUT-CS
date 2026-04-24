#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 5e3+10;

int f[N];

int main()
{
    int n,k,s;  cin>>n>>k>>s; 
    int sum = 0;
    int tot = 0;
    for(int i=1;i<=n;i++)
    {
        int fen,pat; cin>>fen>>pat; 
        if(fen>=175 && pat<s) f[fen]++;
        if(fen<175) tot++;
    }

    for(int i=175;i<=290;i++)
    {
        if(f[i]>k) 
        {
            sum+=f[i]-k;
        }

    }

    cout<<n-sum-tot<<endl;
    return 0;
}