#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 110;

string zifu[N];
string ans[N];

int main()
{
    char ch; int n; 
    cin>>ch>>n;
    getchar();

    for(int i=1;i<=n;i++)
    {
        getline(cin,zifu[i]);
    }

    for(int i=1;i<=n;i++)
    {
        ans[i]=zifu[i];
    }

    reverse(zifu+1,zifu+n+1);

    for(int i=1;i<=n;i++) reverse(zifu[i].begin(),zifu[i].end());
    
        bool flag = true;


    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<zifu[i].size();j++)
        {
            if(zifu[i][j]!=ans[i][j]) 
            {
                flag = false;
                break;
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<zifu[i].size();j++)
        {
            if(zifu[i][j]=='@') zifu[i][j]=ch;
        }
    }

    if(flag) cout<<"bu yong dao le"<<endl;

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<zifu[i].size();j++) cout<<zifu[i][j];
        cout<<endl;
    }

    return 0;
}