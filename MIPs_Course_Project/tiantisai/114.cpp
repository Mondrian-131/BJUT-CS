#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

int e[N],ne[N];

int st[N];

int addr,n;

int main()
{
    cin>>addr>>n;
    
    for(int i=1;i<=n;i++)
    {
        int a,w,ver;
        cin>>a>>w>>ver;
        e[a] = w;
        ne[a] = ver;
    }

    vector<int> ans;
    vector<int> re;
    for(int i=addr;~i;i=ne[i])
    {
        int val = e[i];
        if(st[abs(val)]) {
            re.push_back(i);
        }
        else {
            st[abs(val)] = 1;
            ans.push_back(i);
        }
    }



    for(int i=0;i<ans.size();i++)
    {
        printf("%05d %d ",ans[i],e[ans[i]]);
        if(i<ans.size()-1) printf("%05d\n",ans[i+1]); 
        else cout<<-1<<endl;
    }

    for(int i=0;i<re.size();i++)
    {
        int addr = re[i];
        if(i<re.size()-1) printf("%05d %d %05d\n",addr,e[addr],re[i+1]) ;
        else printf("%05d %d %d\n",addr,e[addr],-1) ;
    }
    return 0;
}