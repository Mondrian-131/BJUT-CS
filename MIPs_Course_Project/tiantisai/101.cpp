#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;
string word[1100];


int main()
{
    int n; cin>>n;
    cin.get();
    for(int i=1;i<=n;i++)
    {
        cin>>word[i];
    }
    int k; cin>>k;
    cin.get();
    string  s; 
    getline(cin,s);
    int tot = 0;

    for(int i=1;i<=n;i++)
    {
        size_t pos = 0;
        while((pos=s.find(word[i],pos))!=string::npos)
        {
            s.replace(pos,word[i].size(),"###");
            tot++;
            pos+=3; 
        }
    }
    
    size_t pos = 0;
    while((pos=s.find("###",pos))!=string::npos)
    {
        s.replace(pos,3,"<censored>");
        pos+=10;
    }    

    if(tot>=k){
        cout<<tot<<endl;
        cout<<"He Xie Ni Quan Jia!"<<endl;
    }
    else{
        cout<<s<<endl;
    }
    return 0;
}

