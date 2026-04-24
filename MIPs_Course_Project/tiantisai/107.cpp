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
    int T,s,t; cin>>T>>s>>t;
    if((s==1 && T>35) && (s==1 && t>=33) ) 
    {
        cout<<"Bu Tie"<<endl;
        cout<<T<<endl;
    }
    else{
        if(s==0 && (T>35 && t>=33)){
            cout<<"Shi Nei"<<endl;
            cout<<T<<endl;
        }
        else if(s==1 && T<=35 || s==1 && t<33) 
        {
            cout<<"Bu Re"<<endl;
            cout<<t<<endl;
        }
        else if(T<=35 || t<33) 
        {
            cout<<"Shu Shi"<<endl;
            cout<<t<<endl;
        }
    }
    return 0;
}