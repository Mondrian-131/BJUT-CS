#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e2+10;

double price[N];
int tot[N];
int main()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>price[i];
    }

    int a,b; 
    while(cin>>a>>b,a)
    {
        tot[a]+=b;
    }

    double sum = 0;
    for(int i=1;i<=n;i++)
    {
        sum+=tot[i]*price[i];
        cout<<tot[i]<<endl;
    }
    

    printf("%.2f",sum);
    return 0;
}