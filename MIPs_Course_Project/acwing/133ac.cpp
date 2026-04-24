#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define Maxn 1000010
using namespace std;
typedef long long ll;
ll n,q;
ll a[Maxn],tree1[Maxn],tree2[Maxn];
namespace DY {
ll lowbit(ll x)
{
    return x&(-x);
}
void add(ll x,ll k)
{
    for(ll i=x;i<=n;i+=lowbit(i))
    {
        tree1[i]+=k;
        tree2[i]+=(x*k);
    }
}
ll getsum(ll x)
{
    ll ans = 0 ;
    for(ll i=x;i>0;i-=lowbit(i))
    {
        ans+= (x+1ll)*tree1[i]-tree2[i];
    }
    return ans;
}
	void main() {
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=n;i>=1;i--) {
        add(i,a[i]-a[i-1]);
    }

    
		while(q--) {
			        int op ;cin>>op;
        ll l,r,x;
        if(op==1)
        {
            cin>>l>>r>>x;
            add(l,x);
            add(r+1,-x);
        }
        else{
            cin>>l>>r;
            cout<<getsum(r)-getsum(l-1)<<endl;
        }
		}
	}
};
int main() {
	DY::main();
	return 0;
}