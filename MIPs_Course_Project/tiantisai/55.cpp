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
    int a,b;  cin>>a>>b;
    int x; 
    int sum = 0;
    for(int i=0;i<3;i++) 
    {
        cin>>x;
        sum+=x;
    }
    
    if(a>b && sum<3 || a<b && sum==0) printf("The winner is a: %d + %d",a,3-sum);
    else printf("The winner is b: %d + %d",b,sum);
    return 0;
}