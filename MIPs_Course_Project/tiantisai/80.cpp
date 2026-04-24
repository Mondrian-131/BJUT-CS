#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;


void push(vector<int>& item,int idx)
{
    int t = item[idx]*item[idx+1];
    string s = to_string(t);
    for(int i=0;i<s.size();i++) item.push_back(s[i]-'0');
}

int main()
{
    int a,b,n;
    cin>>a>>b>>n;
    vector<int> item;
    item.push_back(a);
    item.push_back(b);
    if(n==1) cout<<a;
    else if(n==2) cout<<a<<" "<<b;
    else{

        int idx = 0;
        while(item.size()<n)
        {
            push(item,idx);
            idx++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(i) cout<<" "<<item[i];
            else cout<<item[i];
        }
    }

    
    return 0;
}