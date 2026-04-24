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
    int n ; cin>>n;
    for(int i=1;i<=n;i++)
    {
        int bg,ed; // 序号从1开始 
        string fr,ta;
        cin>>bg>>ed>>fr>>ta;
        string t = s.substr(bg-1,ed-bg+1);
        s.erase(bg-1,ed-bg+1);
       
        size_t pos = 0;
        bool flag = false;
        while((pos = s.find(fr,pos))!=string::npos)
        {
            if(pos+fr.size()+ta.size()-1<s.size() && s.substr(pos+fr.size(),ta.size())==ta)
            {
                s = s.substr(0,pos+fr.size()) + t + s.substr(pos+fr.size());
                flag = 1;
                break;
            }
            pos+=1;
        }
        if(!flag) s+=t;
    }

    
    cout<<s<<endl;
    return 0;
}
