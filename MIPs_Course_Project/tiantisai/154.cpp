#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

int tim[N];
int n;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int h1,m1,s1,h2,m2,s2;
        scanf("%d:%d:%d - %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
        int t1 = h1*60*60 + m1*60 + s1;
        int t2 = h2*60*60 + m2*60 + s2 ;
        for(int j=t1;j<=t2;j++) tim[j]=1;
    }

    for(int i=0;i<86400;i++)
    {
        if(tim[i]) continue;
        int bg;
        if(i) bg = i-1;
        else bg = i;
        while(i<86400 && !tim[i]) i++;
        int ed;
        if(i==86400) ed = i-1;
        ed = i;
        int h1,m1,s1,h2,m2,s2; 
        h1 = bg/3600; bg -= h1*3600;
        m1 = bg/60; bg -= m1*60;
        s1 = bg;
        h2 = ed/3600; ed -= h2*3600;
        m2 = ed/60; ed -= m2*60;
        s2 = ed;
        printf("%02d:%02d:%02d - %02d:%02d:%02d\n",h1,m1,s1,h2,m2,s2);
        i--;
    }
}