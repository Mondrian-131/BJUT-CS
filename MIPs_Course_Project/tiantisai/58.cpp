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
    string s; 
    getline(cin,s);

    for(int i=0;i<s.size();i++)
    {   
        if(s[i]!='6') cout<<s[i];
        else{
            int k = i;
            int sum = 0;
            while(k<s.size() && s[k]=='6')
            {
                sum++;
                k++;
            }
            if(sum<=3)
            {
                for(int i=0;i<sum;i++) cout<<'6';
            }
            else if(sum<=9) cout<<'9';
            else cout<<"27";
            i=k-1;
        }
    }
    return 0;
}