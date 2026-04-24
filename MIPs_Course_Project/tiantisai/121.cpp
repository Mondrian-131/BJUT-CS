#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e4+10;

int n;

struct node{
    int id;
    int money;
    int num;
}a[N];

bool cmp(node&a,node&b)
{
    if(a.money!=b.money) return a.money>b.money;
    else if(a.num!=b.num) return a.num>b.num;
    return a.id < b.id;
}

int main()
{
    cin>>n;
    for(int i = 1;i<=n;i++) a[i].id = i;
    for(int i=1;i<=n;i++)
    {
        int k ;cin>>k;
        int sum = 0;
        while(k--)
        {
            int ver,val;
            cin>>ver>>val;
            a[ver].num++;
            sum += val;
            a[ver].money += val;
        }
        a[i].money-=sum;
    }

    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++) printf("%d %.2f\n",a[i].id,a[i].money/100.0); 
}