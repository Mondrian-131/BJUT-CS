#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e3+10;

int f[N][N];

int main()
{
    string s; getline(cin,s); 

    for(int i=0;i<s.size();i++) f[i][1] = 1;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1]) f[i][2] = 1;
    } 


    int ans = 1;
    for(int len=3;len<=s.size();len++)
    {
        for(int l=0;l+len-1<s.size();l++)
        {
            if(s[l]==s[l+len-1] && f[l+1][len-2]==1) {
                f[l][len] = 1; 
                ans = max(ans,len);
            }
        }
    }


    cout<<ans<<endl;

    return 0;
}