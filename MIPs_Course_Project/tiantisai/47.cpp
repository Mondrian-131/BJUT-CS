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
    int n;
    cin>>n;
    while(n--)
    {
        string s;
        int a,b;
        cin>>s>>a>>b;
        if(a<15 || a>20 || b>70 || b<50) {
            cout<<s<<endl;
        }
    }
    return 0;
}