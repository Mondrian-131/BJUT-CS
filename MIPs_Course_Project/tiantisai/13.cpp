#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

int fact(int x)
{
    if(x==1) return 1;
    else return fact(x-1)*x;
}

int main()
{
    int n;cin>>n;
    int sum =0 ;
    for(int i=1;i<=n;i++)
    {
        sum += fact(i);
    }
    
    cout<<sum<<endl;
    return 0;
}