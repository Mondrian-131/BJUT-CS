#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

void change(string to, string& ans, string last)
{
    size_t pos=0;
    while((pos = ans.find(to, pos)) != std::string::npos)
    {
        if(pos-1>=0 && (isalpha(ans[pos-1]) || isdigit(ans[pos-1])) )
        {
            pos+=1;
            continue;
        }
        if(pos+to.size()<ans.size() && (isalpha(ans[pos+to.size()]) || isdigit(ans[pos+to.size()])))
        {
            pos+=1;
            continue;
        }
        ans.erase(pos,to.size());
        ans.insert(pos,last);
        pos+=1;
    }
}

int main()
{
    
    int n; cin>>n;
    getchar();
    for(int i=1;i<=n;i++)
    {
        string s; getline(cin,s);
        cout<<s<<endl;
        string p = "";
        // stringstream ss(s); 
        // string x; 
        // while(ss>>x)
        // {
        //     if(!isalpha(x[0]) && !isdigit(x[0])) p+=x;
        //     else{
        //         p+=" ";
        //         p+=x;
        //     }
        // }
        // if(p[p.size()-1]==' ') p=p.substr(0,p.size()-1);  
        // if(p[0]==' ') p=p.substr(1);
        while(s[0]==' ') s.erase(0,1);
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                int j = i;
                while(j<s.size() && s[j]==' ') j++; 
                if(j==s.size()) break;
                if(ispunct(s[j]))
                {
                    p+=s[j];
                    i = j;
                }
                else{
                    p+=" ";
                    p+=s[j];
                    i=j;
                }
            }
            else p+=s[i];
        }
    
        for(int i=0;i<p.size();i++)
        {
            if(p[i]>='A' && p[i]<='Z' && p[i]!='I') p[i]=tolower(p[i]);
        }


        change("I", p, "#");
		change("me", p, "#");
        change("can you", p, "I can");
		change("could you", p, "I could");
        change("#",p,"you");

        for(int i=0;i<p.size();i++)
        {
            if(p[i]=='?') p[i]='!';
        }

        cout<<"AI: ";
        cout<<p<<endl;
    }
    return 0;
}