#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;


void change(string to, string& ans, string last) {
	size_t pos = ans.find(to);
	while (pos != ans.npos)
	{
		if ((!isalpha(ans[pos-1]) && !isdigit(ans[pos-1])) && (!isalpha(ans[pos+to.size()]) && !isdigit(ans[pos+to.size()])) )
		{
            ans.erase(pos,to.length());
            ans.insert(pos,last);
            // ans.replace(pos, to.length(), last);
        }	
         
		pos = ans.find(to, pos + 1);
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
        stringstream ss(s); 
        string x; 
        while(ss>>x)
        {
            if(!isalpha(x[0]) && !isdigit(x[0])) p+=x;
            else{
                p+=" ";
                p+=x;
            }
        }
        if(p[p.size()-1]==' ') p=p.substr(0,p.size()-1);  
        if(p[0]==' ') p=p.substr(1);

        for(int i=0;i<p.size();i++)
        {
            if(p[i]>='A' && p[i]<='Z' && p[i]!='I') p[i]=tolower(p[i]);
        }

        p = " "+p+" ";        

        change("can you", p, "A can");
		change("could you", p, "A could");
		change("I", p, "you");
		change("me", p, "you");
		change("A", p, "I");

        
        for(int i=0;i<p.size();i++)
        {
            if(p[i]=='?') p[i]='!';
        }

        cout<<"AI: ";
        for(int i=1;i<p.size()-1;i++) cout<<p[i];
        cout<<endl;
    }
    return 0;
}