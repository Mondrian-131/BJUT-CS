#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

string a[15];

int main()
{
    string s; cin>>s;
    a[0] = "ling";
    a[1] = "yi";
    a[2] = "er";
    a[3] = "san";
    a[4] = "si";
    a[5] = "wu";
    a[6] = "liu";
    a[7] = "qi";
    a[8] = "ba";
    a[9] = "jiu";

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='-') cout<<"fu"<<" ";
        else{
            if(i==s.size()-1) cout<<a[s[i]-'0'];
            else cout<<a[s[i]-'0']<<" ";
        }
    }
    return 0;
}