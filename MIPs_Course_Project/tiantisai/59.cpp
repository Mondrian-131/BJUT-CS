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
    int n ; cin>>n;
    getchar();
    for(int i=1;i<=n;i++)
    {
        string s;
        int tot=0;
        vector<string> word;
        while(cin>>s)
        {
            word.push_back(s);
            int t = s.size();
            if(t>3 && s[t-1]==',' && s.substr(t-4,3)=="ong") tot++;
            if(t>3 && s[t-1]=='.' && s.substr(t-4,3)=="ong") tot++;

            if(s[t-1]=='.') break;
        }

        if(tot<2) cout<<"Skipped"<<endl;
        else{
            for(int i=0;i<word.size()-3;i++) cout<<word[i]<<" ";
            cout<<"qiao ben zhong."<<endl;
        }
    }
    return 0;
}