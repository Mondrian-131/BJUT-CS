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
    int n; cin>>n;
    getchar();
    string s; getline(cin,s);
    int t ;
    if(s.size()%n==0) t = s.size()-n;
    else t = s.size()/n*n;

    for(int i=t;i<t+n;i++)
    {
        for(int j=i;j>=i%n;j-=n)
        {
            if(j>=s.size() )
            {
                cout<<" ";
                continue;
            }
            cout<<s[j];
        }
        cout<<endl;
    }
    return 0;
}