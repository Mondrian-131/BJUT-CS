#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

void f(int x,int y)
{
    int ans = 5000;

    ans -= (x*y+(100-y)*(100-x))/2;

    ans -= (100-x) * (y);

    cout<<ans<<endl;
}
int main()
{
    for(int i=1;i<=50;i++)
    {
        for(int j=1;j<=50;j++)
        {
            f(i,j);
        }
    }
   
    return 0;
}