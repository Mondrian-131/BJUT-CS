#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

int fac[N];
int idx;

int main()
{
    int n;
    cin>>n;
    
    for(int i=1;i<=n/i;i++)
    {
        if(n%i==0 ) {
            if(i!=1) fac[idx++] = i;
            if(n/i !=i ) fac[idx++] = n/i;
        }
    }

    // for(int i=0;i<idx;i++) cout<<fac[i]<<endl;

    sort(fac,fac+idx);

    int ans = 1; // length 
    int pos = 0; //  pos
    int sum = 1; // current length 
    
    int val = n;
    for(int i=1;i<idx;i++)
    {
        val/=fac[i-1];
        if(fac[i]==fac[i-1]+1 && val%fac[i]==0)
        {
            sum ++;
            if(sum>ans)
            {
                ans = sum;
                pos = i-sum+1;
            }
        }
        else 
        {
            i = i - sum + 1;
            sum=1;
            val = n;
        }
    }   
       


    cout<<ans<<endl;

    for(int i=pos;i<pos+ans;i++)
    {
        if(i==pos+ans-1) cout<<fac[i];
        else cout<<fac[i]<<"*";
    }

    return 0;
}

