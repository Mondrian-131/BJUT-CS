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
    string s; cin>>s;
    int sum = 0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]-'0' == 2) sum++;
    }

    double ans = (s[0]=='-') ? (1.5*sum/(s.size()-1)) : (1.0*sum/s.size());
    if((s[s.size()-1]-'0')%2==0) ans = ans*2.0;

    printf("%.2f%%",ans*100);
    return 0;
}