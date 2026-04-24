#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

int tim[50];

int main()
{
    for(int i=0;i<24;i++) cin>>tim[i];
    int x;
    while(cin>>x,x>=0 && x<=23)
    {
        if(tim[x]>50) cout<<tim[x]<<" "<<"Yes"<<endl;
        else cout<<tim[x]<<" No"<<endl;
    }

    return 0;
}