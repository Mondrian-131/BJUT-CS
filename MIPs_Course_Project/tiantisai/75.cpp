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
    if(s.size()==6)
    {
        cout<<s.substr(0,4)<<"-"<<s.substr(4);
    }
    else{
        if(stoi(s.substr(0,2))<22) cout<<"20"<<s.substr(0,2)<<"-"<<s.substr(2);
        else cout<<"19"<<s.substr(0,2)<<"-"<<s.substr(2);
    }
    return 0;
}