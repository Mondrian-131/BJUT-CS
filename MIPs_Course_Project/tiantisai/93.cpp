#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

int hat[N];

int main()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>hat[i];
    int k ;cin>>k;
    while(k--)
    {
        int ri = 0, wr = 0;
        for(int i=1;i<=n;i++)
        {
            int x; cin>>x;
            if(x!=0)
            {
                if(x==hat[i]) ri++;
                else wr++;
            }
        }
        if(ri>=1 && wr==0)  cout<<"Da Jiang!!!"<<endl;
        else cout<<"Ai Ya"<<endl;
    }
    return 0;
}