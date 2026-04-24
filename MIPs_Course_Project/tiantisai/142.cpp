#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

int n;
int ptr;
int sex[N];
int fa[N];
bool st[N];

int find(int x)
{
    while(fa[x]!=x) 
    {
        x = fa[x];
    }
    return x;
}

bool isf(int u,int root)
{
    while(1)
    {
        if(fa[root]==root) return false;
        if(root==u)
        {
            return true;
        }
        else root = fa[root];
    }
}

int main()
{
    cin>>n;
    unordered_map<string,int> mp;
    for(int i=1;i<=n;i++) 
    {
        string m,x;cin>>m>>x;

        if(!mp[m]) mp[m]=++ptr;
        int t = mp[m];

        if(x.back()=='m'){
            sex[t] = 1;        
            fa[ptr] = ptr;
        }
        else if(x.back()=='f'){
            sex[t] = 0;
            fa[ptr] = ptr;
        }
        else if(x.back()=='n'){
            sex[t] = 1;
            string fm = x.substr(0,x.size()-4);
            if(!mp[fm]) mp[fm]=++ptr;
            fa[t] = mp[fm];
        }
        else{
            sex[t] = 0;
            string fm = x.substr(0,x.size()-7);
            if(!mp[fm]) mp[fm] = ++ptr;
            fa[t] = mp[fm];
        }
    }


    int q ;cin>>q;
    while(q--)
    {
        string a1,a2,b1,b2; cin>>a1>>a2>>b1>>b2;
        if(!mp.count(a1) || !mp.count(b1)) cout<<"NA"<<endl;
        else if(sex[mp[a1]] == sex[mp[b1]]) cout<<"Whatever"<<endl;
        else{
            int flag = true;
            int aa = find(mp[a1]),bb=find(mp[b1]);
            if(aa==bb)
            {
                int ida = mp[a1];
                int idb = mp[b1];
                int lca = ida;
                memset(st,0,sizeof st);
                while(1)
                {
                    if(ida==fa[ida]) 
                    {
                        st[ida] = 1;
                        break;
                    }
                    st[ida] = 1;
                    ida = fa[ida];
                }
                while(1)
                {
                    if(st[idb]) 
                    {
                        lca = idb;
                        break;
                    }
                    idb = fa[idb];
                }
                // printf("lca:%d\n",lca);

                for(int i=1,j=mp[a1];i<=4;i++,j=fa[j])
                {
                    // cout<<j<<" ";
                    if(j==lca) flag = 0;
                    if(j==fa[j]) break;
                }
                // cout<<endl;
                for(int i=1,j=mp[b1];i<=4;i++,j=fa[j])
                {
                    // cout<<j<<" ";
                    if(j==lca) flag= 0;
                    if(j==fa[j])break;
                }
                // cout<<endl;
            }
            if(flag) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}