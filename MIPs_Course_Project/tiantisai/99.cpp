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
    int a,b; cin>>a>>b;
    if(a==2 || b==1)
    {
        if(a==2) 
        {
            cout<<"-"<<endl;
            cout<<"stop"<<endl;
        }
        else if(a==1)
        {
            cout<<"-"<<endl;
            cout<<"move"<<endl;
        }
        else{
            cout<<"-"<<endl;
            cout<<"stop"<<endl;
        }
    } 
    else{
        if(a==0)
        {
            cout<<"biii"<<endl;
            cout<<"stop"<<endl;
        }
        else if(a==1)
        {
            cout<<"dudu"<<endl;
            cout<<"move"<<endl;
        }
    }
    return 0;
}