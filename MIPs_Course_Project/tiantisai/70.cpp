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
    int tot = 0;
    bool flag = false;
    int idx ;

    int sum = 0;
    while(getline(cin,s),s!=".")
    {
        sum ++;
        size_t pos = 0;
        if((pos=s.find("chi1 huo3 guo1",pos))!= string::npos) 
        {
            if(!flag) 
            {
                flag = true;
                idx = sum;  
            }
            tot++;
        }
    }


    cout<<sum<<endl;
    if(!tot) cout<<"-_-#";
    else cout<<idx<<" "<<tot;
    return 0;
}