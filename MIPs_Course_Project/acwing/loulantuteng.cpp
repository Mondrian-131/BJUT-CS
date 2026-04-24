#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 2e5+10;

int t[N];
int n;
int l[N];
int a[N];
int r[N];
int lowbit(int x){ return x& (-x);}

void add(int x,int k){
    for(int i=x;i<=n;i+=lowbit(i)){
        t[i]+=k;
    }
}

int sum(int x){
    int ans = 0;
    for(int i=x;i>0;i-=lowbit(i)){
        ans+=t[i];
    }
    return ans;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        add(a[i],1);
        l[i] = sum(a[i]-1);
    }

    memset(t,0,sizeof t);

    for(int i=n;i>=1;i--)
    {
        add(a[i],1);
        r[i]=sum(a[i]-1);
    }

    ll ans1 = 0;
    ll ans2 = 0;
    for(int i=1;i<=n;i++)
    {
        ans1 += l[i]*1ll*r[i];
        ans2 += (i-1-l[i]) * 1ll * (n-i-r[i]) ;
    }

    cout<<ans2<<" "<<ans1<<endl;
    return 0;
}