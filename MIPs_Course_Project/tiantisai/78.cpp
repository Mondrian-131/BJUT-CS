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
    int n,m;cin>>n>>m;
    getchar();

    int sum = 0;
    bool flag = false;
    for(int i=1;i<=n;i++)
    {
        string s; 
        getline(cin,s);
        if(s.find("qiandao")==string::npos && s.find("easy")==string::npos) sum++;
        if(sum>m)
        {
            cout<<s<<endl;
            flag = 1;
            break;
        }
    }

    if(!flag) cout<<"Wo AK le"<<endl;
    return 0;
}