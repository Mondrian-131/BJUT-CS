#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

string cnt[1000];
int idx;

int main()
{
    string s; 
    while(cin>>s,s!=".")
    {
        cnt[++idx] = s;
    }

    if(idx<2) cout<<"Momo... No one is for you ...";
    else if(idx<14) printf("%s is the only one for you...",cnt[2].c_str());
    else printf("%s and %s are inviting you to dinner...",cnt[2].c_str(),cnt[14].c_str());
    return 0;
}