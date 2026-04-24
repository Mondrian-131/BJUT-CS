#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define x first
#define y second
typedef long long ll;

const int mod = 998244353;
const int N = 1e5+10;

int fa[N];
int siz[N];
bool st[N];

int find(int x)
{
    if(fa[x]!=x) fa[x] = find(fa[x]);
    return fa[x];
}


int main() 
{
    int n; cin>>n;

    for(int i=0;i<N;i++) 
    {
        fa[i] = i;
        siz[i] = 1;
    }

    for(int i=0;i<n;i++)
    {
        int k ; cin>>k;
        int cur,pre;
        for(int j=0;j<k;j++)   
        {
            if(j)
            {
                cin>>cur;
                int aa = find(cur), bb=find(pre);
                if(aa!=bb) {
                    fa[aa] = bb;
                    siz[bb]+=siz[aa];
                }
                pre = cur;
            }
            else cin>>pre;
        }
    }

    bool flag = false;
    int m; cin>>m;
    for(int i=0;i<m;i++)
    {
        int t; cin>>t;
        if(!st[t] && siz[find(t)]==1)
        {
            if(!flag) printf("%05d",t);
            else printf(" %05d",t);
            st[t] = true;
            flag = true;
        }
    }

    if(!flag) cout<<"No one is handsome";
    return 0;
}


// 整理一下并查集的笔记，包括维护的好几种性质
// 这题真tm坑，最后输出编号忘了是要写成5位的形式了