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
    getchar();
    string s;  getline(cin,s);
    string ans = "";
    if(n<=s.size())
    {
        for(int i=s.size()-n;i<s.size();i++)
        {
            ans  = ans + s[i]; 
        }
        cout<<ans<<endl;
    }
    else{
        for(int i=0;i<n-s.size();i++) ans+=ch;
        ans+=s;
        cout<<ans<<endl;
    }
    return 0;
}