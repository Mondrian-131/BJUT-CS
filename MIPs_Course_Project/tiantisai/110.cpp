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
    int n,m;
    cin>>n>>m;

    string s; 
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        s.push_back('a'+x-1);
    }

    while(m--)
    {
        int op; cin>>op;
        if(op==1)
        {
            int l1; cin>>l1;
            string t;
            for(int i=0;i<l1;i++)
            {
                int x; cin>>x;
                t.push_back('a'+x-1);
            }
            int l2; cin>>l2;
            string p;
            for(int i=0;i<l2;i++)
            {
                int x; cin>>x;
                p.push_back('a'+x-1);
            }
            size_t pos = s.find(t);
            if(pos!=string::npos) s.replace(pos,t.size(),p);
        }
        else if(op==2)
        {
            for(int i=1;i<s.size();i++)
            {
                int tmp = s[i]-'a'+s[i-1]-'a'+2;
                if(tmp%2==0) {
                    s.insert(i,1,'a'+tmp/2-1);
                    i++;
                }
            }
        }
        else{
            int l,r; cin>>l>>r;
            reverse(s.begin()+l-1,s.begin()+r);
        }
        
    }

    for(int i=0;i<s.size();i++)
    {
        if(i)  cout<<" ";
        cout<<s[i]-'a'+1;
    }
    return 0;

}