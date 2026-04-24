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
    int n0,n1,n;
    cin>>n0>>n1>>n;

    int ans_m,ans_f;
    int minv = 1e9;
    bool flag = false; 

    for(int i=2;i<=n1;i++)
    {
        if(n1%i==0)
        {
           if(n-n1/i>0 && n0%(n-n1/i)==0) 
           {
                int t = n0/(n-n1/i);
                if(t==1) continue;
                if(abs(t-i)<minv)   
                {
                    ans_m = i;
                    ans_f = t;
                    minv = abs(t-i);
                    flag = true;
                }
           }
        }
    }

    if(!flag) cout<<"No Solution"<<endl;
    else cout<<n0/ans_f<<" "<<n1/ans_m<<endl;
    return 0;
}