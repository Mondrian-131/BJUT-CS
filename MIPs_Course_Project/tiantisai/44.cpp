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
    string s; 
    int tot = 0;
    while(cin>>s,s!="End")
    {
       if(tot==n) 
        {
            cout<<s<<endl;
            tot = 0;
        }
       else{
            tot++;
            if(s[0]=='C') cout<<"Bu"<<endl;
            else if(s[0]=='J') cout<<"ChuiZi"<<endl;
            else cout<<"JianDao"<<endl;
       } 
    }
    return 0;
}