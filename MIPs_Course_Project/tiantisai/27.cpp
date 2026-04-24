#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;


bool cmp(int a,int b)
{
    return a > b;
}


int f[20];

int main()
{
    string s; cin>>s;

    vector<int> num; 
    for(int i=0;i<s.size();i++)
    {
        num.push_back(s[i]-'0');
    }

    sort(num.begin(),num.end(),cmp);

    num.erase(unique(num.begin(),num.end()),num.end());

    cout<<"int[] arr = new int[]{";
    for(int i=0;i<num.size();i++)
    {
        if(!i) cout<<num[i];
        else cout<<","<<num[i];
    }
    cout<<"};"<<endl;

    for(int i=0;i<num.size();i++)
    {
        f[num[i]] = i;
    }

    cout<<"int[] index = new int[]{";
    
    for(int i=0;i<s.size();i++)
    {
        if(!i) cout<<f[s[i]-'0'];
        else cout<<","<<f[s[i]-'0'];
    }
    cout<<"};";
    return 0;
}