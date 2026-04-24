#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

int n;
int m;
int main()
{
    cin>>n;
    unordered_map<string,int> mp;
    for(int i=1;i<=n;i++) 
    {
        string s; cin>>s;
        mp[s] = 1;
    }
    cin>>m;
    vector<pair<string,int>> vec;
    vector<string> ans;
    int sum = 0;
    for(int i=1;i<=m;i++)
    {
        string s; int cnt;
        cin>>s>>cnt;
        vec.push_back({s,cnt});
        sum += cnt;
    }

    double avg = sum*1.0/m;
    for(auto t : vec)
    {
        if(!mp.count(t.x) && t.y>avg) ans.push_back(t.x);
    }

    sort(ans.begin(),ans.end());
    if(ans.size()==0) cout<<"Bing Mei You"<<endl;
    else 
    {
        for(auto t: ans) cout<<t<<endl;
    }
    return 0;
}