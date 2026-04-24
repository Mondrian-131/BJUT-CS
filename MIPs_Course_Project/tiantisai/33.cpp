#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

bool st[15];

bool check(int i,int n)
{
    memset(st,0,sizeof st); 
    int cp = i;
    while(i)
    {
        st[i%10]=1;
        i/=10;
    }
    int sum = 0;
    for(int i=0;i<10;i++)
    {
        if(!i && cp<1000) sum++;
        else if(st[i]) sum++;
    }
    if(sum==n) return true;
    else return false;
}

int main()
{
    int y,n; cin>>y>>n;

    for(int i=y;;i++)
    {
        if(check(i,n))
        {
            printf("%d %04d",i-y,i);
            break;
        }
    }
    return 0;
}