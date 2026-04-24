#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

bool isint(string s)
{
    if(s.size()==0) return false;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>'9' || s[i]<'0') return false; 
    }

    int t = stoi(s);
    if(t>1000 ||  t<1) return false;
    return true;
}

int main()
{
    string s1="";
    string s2="";


    char ch;
    while(cin.get(ch))
    {
        if(ch==' ') break;
        else s1+=ch;
    }    
    while(cin.get(ch))
    {
        s2+=ch;
    }


    if(isint(s1) && isint(s2)) printf("%d + %d = %d",stoi(s1),stoi(s2),stoi(s1)+stoi(s2));
    else if(isint(s1) && !isint(s2)) printf("%d + ? = ?",stoi(s1));
    else if(!isint(s1) && isint(s2)) printf("? + %d = ?",stoi(s2));
    else printf("? + ? = ?");
    return 0;
}