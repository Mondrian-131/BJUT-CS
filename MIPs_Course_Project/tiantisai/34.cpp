#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

int a[1200];

int main()
{
    int n; cin>>n;

    for(int i=1;i<=n;i++)
    {
        int k ; cin>>k;
        for(int j=1;j<=k;j++)
        {
            int t ; cin>>t;
            a[t]++;
        }
    }
   
    int max = 1000; 
    for(int i=1000;i>=1;i--)
    {
       if(a[i]>a[max]) max = i;
    }

    cout<<max<<" "<<a[max]<<endl;
    return 0;
}