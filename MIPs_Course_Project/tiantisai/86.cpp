#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

string f(string s)
{
    string p = "";
    for(int i=1;i<s.size();i++)
    {
        if(s[i]%2 == s[i-1]%2){
            p += max(s[i],s[i-1]);
        }
    }
    return p;
}

int main()
{
    string s1,s2;   
    cin>>s1>>s2;

    if(f(s1)==f(s2)) cout<<f(s1);
    else{
        cout<<f(s1)<<endl;
        cout<<f(s2)<<endl;
    }

    return 0;
}