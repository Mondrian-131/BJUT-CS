#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e4+10;

int n,G,k;

struct node{
    string id;
    int score;
    int rank;
}stu[N];

bool cmp(node a,node b)
{
    if(a.score!=b.score) return a.score > b.score;
    return a.id < b.id;
}

int main()
{
    cin>>n>>G>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>stu[i].id>>stu[i].score;
    }

    int sum = 0;
    for(int i=1;i<=n;i++)
    {
        if(stu[i].score>=60 && stu[i].score<G) sum+=20;
        else if(stu[i].score>=G) sum+=50;
    }

    cout<<sum<<endl;
    
    sort(stu+1,stu+n+1,cmp);

    stu[1].rank = 1;
    int cnt = 1;
    for(int i=2;i<=n;i++) 
    {
        if(stu[i].score == stu[i-1].score) {
            stu[i].rank = stu[i-1].rank;
            cnt++;
        }
        else {
            stu[i].rank = stu[i-1].rank + cnt;
            cnt = 1;
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(stu[i].rank>k) break;
        else cout<<stu[i].rank<<" "<<stu[i].id<<" "<<stu[i].score<<endl;
    }
    return 0;
}