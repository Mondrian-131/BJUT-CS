#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;
int n; 

struct node{
    bool sex;
    int fid;
    int mid;
}person[N];

// 是否出五服
int dfs(int a,int b,int dep)
{
    if(dep==5) return true;
    if(!person[a].fid && !person[a].mid) return true;
    if(!person[b].fid && !person[b].mid) return true;
    if(a==-1 || b==-1) return true;

    int afa = person[a].fid;
    int bfa = person[b].fid;
    int ama = person[a].mid;
    int bma = person[b].mid;

    if((afa == bfa) && afa!=-1|| (ama == bma) && ama!=-1) {
        return false;
    }

    int mm = dfs(ama,bma,dep+1);
    int ff = dfs(afa,bfa,dep+1);
    int mf = dfs(ama,bfa,dep+1);
    int fm = dfs(afa,bma,dep+1);

    if(mm && ff && mf && fm) return true;
    else return false;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int id,fid,mid;
        char sex;
        cin>>id>>sex>>fid>>mid;
        if(fid!=-1) person[fid].sex = 1;
        if(mid!=-1) person[mid].sex = 0;
        if(sex=='M') person[id] = {1,fid,mid};
        else person[id] = {0,fid,mid};
    }

    int k;cin>>k;
    while(k--)
    {
        int a,b; cin>>a>>b;
        if(person[a].sex==person[b].sex) cout<<"Never Mind"<<endl;
        else{
            if(dfs(a,b,1)) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    
    return 0;
}