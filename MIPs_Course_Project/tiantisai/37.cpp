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
    int a,b; cin>>a>>b;
    if(b>0) printf("%d/%d=%.2f",a,b,a*1.0/b);
    else if(b<0) printf("%d/(%d)=%.2f",a,b,a*1.0/b);
    else printf("%d/%d=Error",a,b);
    return 0;
}