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

    for(int i=1;i<=n;i++)
    {
        int h ,w; cin>>h>>w;
        double t  = (h-100) * 0.9 *2;
        if(fabs(w-t)<0.1*t) cout<<"You are wan mei!"<<endl;
        else if(w>t) cout<<"You are tai pang le!"<<endl;
        else cout<<"You are tai shou le!"<<endl;
    }
    return 0;
}