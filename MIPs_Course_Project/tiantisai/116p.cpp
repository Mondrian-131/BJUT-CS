#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e3+10;

int a[N];
int n;
vector<int> ans;
int mirror;

void dfs(int l,int r)
{
    if(l>r) return ;
    int i=l+1,j=r;
    if(mirror)
    {
        while(i<=r && a[i]>=a[l]) i++;
        while(j>l && a[j]<a[l]) j--;
    }
    else{
        while(i<=r && a[i]<a[l]) i++;
        while(j>l && a[j]>=a[l]) j--;
    }

    if(i-j!=1)  return ;

    dfs(l+1,j);
    dfs(i,r);
    
    ans.push_back(a[l]);
}

int main()
{

    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    dfs(1,n);

    if(ans.size()!=n) 
    {
        mirror = 1;
        ans.clear();
        dfs(1,n);
    }
    if(ans.size()!=n) 
    {
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)
        {
            if(i) cout<<" ";
            cout<<ans[i];
        } 
    }
    return 0;
}