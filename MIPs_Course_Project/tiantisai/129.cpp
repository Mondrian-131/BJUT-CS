#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

int n; 
int a[N];

int main()
{
    cin>>n; 
    for(int i=1;i<=n;i++) cin>>a[i];

    sort(a+1,a+n+1);

    ll s1=0,s2=0;
    for(int i=1;i<=n;i++)
    {
        if(i<=n/2) s1+=a[i];
        else s2+=a[i];
    }

    printf("Outgoing #: %d\n",n-n/2);
    printf("Introverted #: %d\n",n/2);
    printf("Diff = %d",s2-s1);
    return 0;
}