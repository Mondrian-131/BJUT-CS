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
    int n; cin>>n;
    double sum = 0;
    for(int i=1;i<=n;i++)
    {
        double x; cin>>x;
        sum += 1/x;
    }

    sum/=n;

    printf("%.2f",1/sum);
    return 0;
}