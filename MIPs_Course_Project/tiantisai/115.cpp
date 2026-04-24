#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

typedef pair<double,double> pdi;
int n,m;

pdi cake[N];

int main()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++) cin>>cake[i].y;
    for(int i=1;i<=n;i++) {
       double x ; cin>>x;
       cake[i].x = 1.0*x/cake[i].y; 
    }

    sort(cake+1,cake+n+1);

    int tot = 0;
    double ans =0;

    for(int i=n;i>=1;i--)
    {
        if(tot+cake[i].y<m){
            tot += cake[i].y;
            ans += cake[i].x*cake[i].y;
        }
        else{
            ans += cake[i].x * (m-tot);
            break;
        }
    }

    printf("%.2f",ans);
    return 0;
}