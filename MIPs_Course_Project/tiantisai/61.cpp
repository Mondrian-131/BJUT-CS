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
    double a,b; cin>>a>>b;
    printf("%.1f\n",a/(b*b));
    if(a/(b*b)>25) cout<<"PANG"<<endl;
    else cout<<"Hai Xing";
    return 0;
}