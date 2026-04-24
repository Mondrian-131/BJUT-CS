#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

int f(int x) { return 2*x*x-1;}

int main()
{
    char ch;
    int n ;

    cin>>n>>ch;

    int l=1,r=22;
    // while(l<r)
    // {
    //     int mid = l+r+1>>1;
    //     if(f(mid)<=n) l=mid;
    //     else r=mid-1;
    // }

    int ans;

    while(l<=r)
    {
        int mid = l+r>>1;
        if(f(mid)<=n)
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }

        
    int sum = 0;
    for(int i = ans;i>=1;i--) 
    {
        for(int j=0;j<sum;j++) cout<<" ";
        for(int j=0;j<(2*i-1);j++) cout<<ch;
        cout<<endl;
        sum++;
    }

    sum-=2;

    for(int i=2;i<=ans;i++)
    {
        for(int j=0;j<sum;j++) cout<<" ";
        for(int j=0;j<2*i-1;j++) cout<<ch;
        cout<<endl;
        sum--;
    }

    cout<<n-f(ans)<<endl;
    
    return 0;
}