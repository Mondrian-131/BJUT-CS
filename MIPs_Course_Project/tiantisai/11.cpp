#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

bool st[500];
int main()
{
    string s,t; 
    getline(cin,s);
    getline(cin,t);

    for(int i=0;i<t.size();i++) 
    {
        st[t[i]-32]=1;
    }


    for(int i=0;i<s.size();i++)
    {
        if(!st[s[i]-32]) cout<<s[i];
    }
    return 0;
}