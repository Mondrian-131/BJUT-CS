#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

int g[15][15];
bool st[10];

int main()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++)
    {

        bool flag = 0;

        for(int j=1;j<=9;j++)
        {
            for(int k=1;k<=9;k++) 
            {
                cin>>g[j][k];
                if(g[j][k]<1 || g[j][k]>9) flag = 1;
            }
        }



        memset(st,0,sizeof st);

          
        for(int j=1;j<=9;j++) 
        {
            for(int k=1;k<=9;k++)
            {
                if(!st[g[j][k]]) st[g[j][k]]=1;
                else {
                    flag = 1;
                }
            }
            memset(st,0,sizeof st);
        }
        

        for(int j=1;j<=9;j++) 
        {
            for(int k=1;k<=9;k++)
            {
                if(!st[g[k][j]]) st[g[k][j]]=1;
                else {
                    flag = 1; 
                }
            }
            memset(st,0,sizeof st);
        } 

        

        for(int j=1;j<=9;j+=3)
        {
            for(int k=1;k<=9;k+=3) 
            {
                for(int p=j;p<j+3;p++)
                {
                    for(int q=k;q<k+3;q++)
                    {
                        if(!st[g[p][q]])  st[g[p][q]] = 1;
                        else {
                            flag = 1;
                        }
                    }
                }
                memset(st,0,sizeof st);
            }
        }

        if(flag) cout<<0<<endl;
        else cout<<1<<endl;
    }
    return 0;
}