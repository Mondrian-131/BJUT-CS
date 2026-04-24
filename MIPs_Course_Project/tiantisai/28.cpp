#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;


bool isprime(int x)
{
    if(x==1) return false;
    for(int i=2;i<=x/i;i++)
    {
        if(x%i==0) return false;
    }
    return true;
}

int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;  cin>>x;
        if(isprime(x)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}