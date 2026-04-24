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
    int sum = 0 ;
    for(int i=a;i<=b;i++)
    {
        sum += i;
        if((i-a)%5==4) printf("%5d\n",i);
        else printf("%5d",i);
    }

    if((b-a+1)%5==0) printf("Sum = %d",sum);
    else{
        printf("\nSum = %d",sum);
    }
    return 0;
}