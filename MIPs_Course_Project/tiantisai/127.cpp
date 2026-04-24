#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e4+10;

double a[N];
int n,k,m;
int main()
{
    cin>>n>>k>>m;
    for(int i=1;i<=n;i++) 
    {
        double sum = 0;
        int minv = 1000, maxv = -1;
        for(int j=1;j<=k;j++)
        {
            int x; cin>>x;
            if(x>maxv) maxv = x;
            if(x<minv) minv = x;
            sum += x;
        }
        a[i] = (sum-minv-maxv)/(k-2);
    }


    sort(a+1,a+n+1);
    for(int i=n-m+1;i<=n;i++) 
    {
        if(i==n) printf("%.3lf",a[i]);
        else printf("%.3lf ",a[i]);
    }
    return 0;
}