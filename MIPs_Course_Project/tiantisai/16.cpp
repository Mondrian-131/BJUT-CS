#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

int val[20] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};


int main()
{
    string mo = "10X98765432";
    int n; cin>>n;
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        int tot = 0;
        string s;cin>>s;
        for(int j=0;j<s.size();j++)
        {
            if(j==s.size()-1)
            {
                if(mo[tot%11]==s[s.size()-1]) sum++;
                else cout<<s<<endl;
            }
            else if(isdigit(s[j])) 
            {
                tot+=(s[j]-'0')*val[j];
            }
            else{
                cout<<s<<endl; 
                break;
            }
        }
    }
    
    if(sum==n) cout<<"All passed"<<endl;
    return 0;
}