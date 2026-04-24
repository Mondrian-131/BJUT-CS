#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

int n; 
int t[N];
int a[N];

int res[N];

int lowbit(int x)  {return x&(-x);};

void add(int x,int k){
    for(int i=x;i<=n;i+=lowbit(i)) t[i]+=k;
}

int sum(int x) {
    int ans = 0;
    for(int i=x;i>0;i-=lowbit(i)) ans+=t[i];
    return ans;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)  cin>>a[i];
    for(int i=1;i<=n;i++) add(i,1);
    
    for(int i=n;i>=1;i--) 
    {
        int l=1,r=n;
        // while(l<r)
        // {
        //     int mid = l+r>>1;
        //     if(sum(mid)>=a[i]) r=mid;
        //     else l=mid+1;
        // }
        res[i]=l;
        add(l,-1);
    }

    for(int i=1;i<=n;i++) cout<<res<<endl;
    return 0;
}