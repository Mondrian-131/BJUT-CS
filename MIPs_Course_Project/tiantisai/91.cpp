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
    int n,m,k;
    string x;
    cin>>n>>x>>m>>k;

    if(k==n) printf("mei you mai %s de",x.c_str());
    else if(k==m) printf("kan dao le mai %s de",x.c_str());
    else printf("wang le zhao mai %s de",x.c_str());
    return 0;
}