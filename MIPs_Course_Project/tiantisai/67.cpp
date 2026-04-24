#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

int main()
{
    double a,c; int b; 
    cin>>a>>b>>c;
    double ans;
    if(b) ans = 1.26*a;
    else ans = 2.455*a;
    printf("%.2f ",ans);
    if(c<=ans) cout<<"T_T";
    else cout<<"^_^";
    return 0;
}