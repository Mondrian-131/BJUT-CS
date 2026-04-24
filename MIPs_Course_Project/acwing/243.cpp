#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;


ll a[N];
ll t1[N],t2[N];
int n,m;
int lowbit(int x) { return x&(-x);};
void add(int x,int k){
    for(int i=x;i<=n;i+=lowbit(i)){
        t1[i]+=k;
        t2[i]+=x*(ll)k;
    }
}

ll sum(int x){
    ll ans =0 ;
    for(int i=x;i>0;i-=lowbit(i)){
        ans+= (x+1)*t1[i]-t1[i];
    }
    return ans;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) add(i,a[i]-a[i-1]);

    while(m--)
    {
        char op ;cin>>op;
        if(op==1)
        {
            int l,r,d; cin>>l>>r>>d;
            add(l,d);add(r+1,-d);
        }
        else{
            int l,r;
            cout<<sum(r)-sum(l-1)<<endl;
        }
    }
    return 0;
}