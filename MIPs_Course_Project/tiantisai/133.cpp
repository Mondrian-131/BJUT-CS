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
    string name;
    double avg;
    int cnt;
};

bool cmp(node a,node b)
{
    if(a.cnt !=b.cnt) return a.cnt > b.cnt;
    return a.avg < b.avg;
}

int main()
{
    cin>>n;
    vector<node> vec;
    for(int i=1;i<=n;i++)
    {
        string s; int k;
        set<int> lab;
        cin>>s>>k;
        for(int j=1;j<=k;j++)
        {
            int x; cin>>x;
            lab.insert(x);
        }
        node t = {s,k*1.0/lab.size(),(int)lab.size()};
        vec.push_back(t);
    }

    sort(vec.begin(),vec.end(),cmp);

    int sum = 1;
    for(int i=0;i<vec.size();i++)
    {
        if(sum==3) break;
        if(!i) cout<<vec[i].name;
        else{
                cout<<" "<<vec[i].name;
                sum++;
        }
    }

    if(sum<3) 
    {
        for(int i=1;i<=3-sum;i++) cout<<" -";
    }
    return 0;
}