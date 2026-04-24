#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e4+10;

int fa[N];

int find(int x)
{
    if(fa[x]!=x) fa[x] = find(fa[x]);
    return fa[x];
}

int cnt[N];
int area[N]; 

int n; 

struct node{
    int minv;
    int count;
    double pcnt;
    double parea;
};

vector<int> fam[N];

bool cmp(node& a,node&b)
{
    if(a.parea!=b.parea) return a.parea>b.parea;
    return a.minv<b.minv;
}
set<int> person;


int main()
{
    cin>>n;
    for(int i=1;i<N;i++) fa[i] = i;
    for(int i=1;i<=n;i++) 
    {
        int ver,f,m,k;
        cin>>ver>>f>>m>>k;
        person.insert(ver);
        if(f!=-1) {
            person.insert(f);
            fa[find(f)] = find(ver);
        }
        if(m!=-1) {
            person.insert(m);
            fa[find(m)] = find(ver);
        }
        while(k--){
            int x; cin>>x;
            person.insert(x);
            fa[find(x)] = find(ver);
        }
        cin>>cnt[ver]>>area[ver];
    }
    for(auto i : person)
    {
        int root = find(i);
        fam[root].push_back(i);
    }
    int tot = 0;
    vector<node> vec;
    unordered_map<int,int> mp;
    for(auto i : person)
    {
        int root = find(i);
        if(!mp.count(root)) 
        {
            mp[root] = 1;
            tot++;
            double sum = 0 ;
            double tao= 0;
            int num = fam[root].size();
            int minv = 10000;
            for(int j=0;j<fam[root].size();j++)
            {
                int ver = fam[root][j];
                if(ver<minv) minv = ver;
                sum += area[ver];
                tao += cnt[ver];
            }
            vec.push_back({minv,num,tao/num,sum/num});
        }
    }

    sort(vec.begin(),vec.end(),cmp);
    
    cout<<tot<<endl;

    for(int i=0;i<vec.size();i++)
    {
        printf("%04d %d %.3f %.3f\n",vec[i].minv,vec[i].count,vec[i].pcnt,vec[i].parea);
    }

    return 0;
}