#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

ll a[N];
ll t[N];
int n,m;
ll lowbit(ll x)
{
    return x&(-x);
}
void add(int x,int k){
    for(int i=x;i<=n;i+=lowbit(i))  t[i]+=k;
}

ll sum(int x){
    ll ans = 0;
    for(int i=x;i>0;i-=lowbit(i)) ans+=t[i];
    return ans;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)  cin>>a[i];
    for(int i=1;i<=n;i++) add(i,a[i]-a[i-1]);

    while(m--)
    {
        char op;
        cin>>op;
        if(op=='C'){
            int l,r,d;
            cin>>l>>r>>d;
            add(l,d);
            add(r+1,-d);
        }
        else{
            int x; cin>>x;
            cout<<sum(x)<<endl;
        }
    }
    return 0;
}