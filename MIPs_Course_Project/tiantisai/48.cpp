#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 110;

int a[N][N];
int b[N][N];
int c[N][N];

int main()
{
    int ra,ca; cin>>ra>>ca;
    for(int i=1;i<=ra;i++)
    {
        for(int j=1;j<=ca;j++)
        {
            cin>>a[i][j];
        }
    }

    int rb,cb; cin>>rb>>cb;
    for(int i=1;i<=rb;i++)
    {
        for(int j=1;j<=cb;j++)
        {
            cin>>b[i][j];
        }
    }
    if(ca != rb) 
    {
        printf("Error: %d != %d",ca,rb);
        return 0;
    }
    else{
        for(int i=1;i<=ra;i++)
        {
            for(int j=1;j<=cb;j++)
            {
                for(int k=1;k<=ca;k++)
                {
                    c[i][j]+=a[i][k]*b[k][j];
                }
            }
        }


        cout<<ra<<" "<<cb<<endl;

        for(int i=1;i<=ra;i++)
        {
            for(int j=1;j<=cb;j++)
            {
                cout<<c[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}