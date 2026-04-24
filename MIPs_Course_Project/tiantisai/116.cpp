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

vector<int> res;
bool check(int l,int r,int sig)
{
    if(r-l<=0) {
        if(r-l==0) res.push_back(a[l]);
        return true;
    }
    int flag;
    int p = l + 1;
    if(a[p]<a[l]){
        bool tag = false;
        flag = 1;
        while(p<=r && a[p]<a[l]) p++;
        for(int i=p;i<=r;i++)
        {
            tag = 1;
            if(a[i]<a[l]) return false;
        }
        if(!tag && sig) flag = sig;
    }
    else{
        bool tag= false;
        flag = -1;
        while(p<=r && a[p]>=a[l]) p++;
        for(int i=p;i<=r;i++)
        {
            tag = 1;
            if(a[i]>=a[l]) return false;
        }
        if(!tag && sig) flag = sig;
    }
    if(sig==0) sig = flag; 
    else if(flag != sig) return false;

    if(!check(l+1,p-1,sig)) {
        return false;
    }
    if(!check(p,r,sig)) {
        return false;
    }
    res.push_back(a[l]);
    return true;
}

int main()
{
    cin>>n; 
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==1) {
        cout<<"YES"<<endl;
        cout<<a[1];
    }
    else{
        int ans = check(1,n,0);
        if(ans) {
            cout<<"YES"<<endl;
            for(int i=0;i<res.size();i++)
            {
                if(i) cout<<" ";
                cout<<res[i];
            }
        }
        else cout<<"NO"<<endl;
    } 
    return 0;
}