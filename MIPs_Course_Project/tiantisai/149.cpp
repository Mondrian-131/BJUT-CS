#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e2+10;

int n,m,s;

vector<char> vec[N];

int main()
{
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=s.size()-1;j>=0;j--) vec[i].push_back(s[j]);
    }

    int op;
    vector<char> stk;
    vector<char> ans;
    while(cin>>op,op!=-1)
    {
        if(op!=0 && !vec[op].empty()){
            if(stk.size()==s) {
                ans.push_back(stk.back());
                stk.pop_back();
                stk.push_back(vec[op].back());
                vec[op].pop_back();
            }
            else stk.push_back(vec[op].back()),vec[op].pop_back();
        }
        else if(!op){
            ans.push_back(stk.back());
            stk.pop_back();
        }
    }

    for(int i=0;i<ans.size();i++) cout<<ans[i];
    return 0;
}