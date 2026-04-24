#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;
int n;
set<int> s;
int main()
{
    cin>>n;
    s.insert(0);
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        if(x<*s.rbegin()) s.erase(*s.upper_bound(x));
        s.insert(x);
    }
    cout<<s.size()-1<<endl;
    return 0;
}