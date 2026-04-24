#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

ll qmi(int a,int k)
{
    ll res = 1;
    while(k)
    {
        if(k&1) res=res*a;
        a= a*a;
        cout<<res<<endl;
        cout<<a<<endl;
        k>>=1;
    }
    return res;
}

int main()
{
    ll n; cin>>n;
    
    int ans = -1;
    int pos ;
    for(int i=1;i<=31;i++)
    {
        ll sum = 0;        
        for(int j=1;;j++)
        {
            sum+=qmi((ll)j,i);
            if(sum==n) 
            {
                ans = i;
                pos = j;
            }
            else if(sum>n) break;
        }
    }


    if(ans==-1) 
    {
        printf("Impossible for %d.",n);
    }
    else{
        for(int i=1;i<=pos;i++)
        {
            if(i>1) cout<<"+";
            printf("%d^%d",i,ans);
        }
    }
    cout<<qmi(2,31)<<endl;
    return 0;
}