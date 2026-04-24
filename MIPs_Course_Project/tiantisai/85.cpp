#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

int shaizi[10][10];

int main()
{
    for(int i=1;i<=6;i++)
    {
        int x; cin>>x;
        shaizi[i][x] = 1;
    }
    int n ;cin>>n;
    for(int i=1;i<=6;i++)
    {
        int sum = 0;
        for(int j=6;j>=1;j--)
        {
            if(!shaizi[i][j]) 
            {
                sum++;
                if(sum==n) 
                {
                    if(i==1) cout<<j; 
                    else cout<<" "<<j;
                }
            }
        }
    }
    return 0;
}