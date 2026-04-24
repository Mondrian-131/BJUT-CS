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
    int n; char ch;
    cin>>n>>ch;

    for(int i=0;i<(int)round(n/2.0);i++)
    {
        for(int j=0;j<n;j++) cout<<ch;
        cout<<endl;
    }
    return 0;
}