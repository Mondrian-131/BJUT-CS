#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

int val[30];
int cnt[30];
int main()
{
    string s; cin>>s;
    for(int i=1;i<=26;i++)
    {
        cin>>val[i];
    }

    int sum = 0;
    for(int i=0;i<s.size();i++)
    {
        cnt[s[i]-'a'+1]++;
        sum+=val[s[i]-'a'+1];
    }

    for(int i=1;i<=26;i++)
    {
        if(i>1) cout<<" ";
        cout<<cnt[i];
    }
    cout<<endl;
    cout<<sum<<endl;
    return 0;
}