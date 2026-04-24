#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 110;

int num[N];
vector<int> team[N];

int main()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
        num[i]*=10;
    }

    int idx = 1;
    int t = n; 

    while(1)
    {
        if(t==1) break;
        for(int i=1;i<=n;i++)
        {
           if(num[i]){
                num[i]--;
                team[i].push_back(idx++);
                if(!num[i]) t--;
                if(t==1) break;
           }
        }
    }

    int ans;
    for(int i=1;i<=n;i++)
    {
        if(num[i]) ans = i;
    }

    while(num[ans]--)
    {
        team[ans].push_back(idx);
        idx+=2;
    }


    for(int i=1;i<=n;i++)
    {
        printf("#%d\n",i);
        for(int j=0;j<team[i].size();j++)
        {
            if((j+1)%10==0) cout<<team[i][j]<<endl;
            else cout<<team[i][j]<<" ";
        }
    }
    return 0;
}