#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;


int check(int x)
{
    string s  = to_string(x);
    int tot = 0;
    if(s.size()==1) return 1;
    else{
        while(s.size()!=1)
        {
            int t = 1;
            for(int i=0;i<s.size();i++)
            {
                t*=s[i]-'0';
            }
            s = to_string(t);
            tot++;
        }
    }
    return tot;
}

int main()
{
    int a,b; cin>>a>>b;

    vector<int> ans;
    int maxv = 0;

    for(int i=a;i<=b;i++)
    {
        int t = check(i);
        if(t>maxv)
        {
            maxv = t;
            ans.clear();
            ans.push_back(i);
        }
        else if(t==maxv) ans.push_back(i);
    }
    
    cout<<maxv<<endl;
    for(int i=0;i<ans.size();i++)
    {
        if(i) cout<<" "<<ans[i];
        else cout<<ans[i];
    }
    return 0;
}