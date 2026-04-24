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
    int n1,n2,a,b;
    cin>>n1>>n2>>a>>b;
    if(a<n1 && b<n1) 
    {
        printf("%d-N %d-N\n",a,b);
        printf("zhang da zai lai ba");
    }
    else if(a>=n1 && b>=n1) 
    {
        printf("%d-Y %d-Y\n",a,b);
        printf("huan ying ru guan");
    }
    else if((a>=n2 && b<n1) || (b>=n2 && a<n1)) 
    {
        printf("%d-Y %d-Y\n",a,b);
        if((a>=n2 && b<n1)) printf("qing 1 zhao gu hao 2");
        else printf("qing 2 zhao gu hao 1");
    }
    else{
        if(a>b)
        {
            printf("%d-Y %d-N\n",a,b);
            printf("%d: huan ying ru guan",1);
        } 
        else 
        {
            printf("%d-N %d-Y\n",a,b);
            printf("%d: huan ying ru guan",2);
        }
    }
    return 0;

}