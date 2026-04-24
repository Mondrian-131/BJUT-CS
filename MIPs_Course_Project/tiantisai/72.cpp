#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

int num[5][5];

bool st[10];
int f[50];

int main()
{
    for(int i=1;i<=3;i++) 
    {
        for(int j=1;j<=3;j++) 
        {
            cin>>num[i][j];
            st[num[i][j]] = 1;
        }
    }

    int tmp ;
    for(int i=1;i<=9;i++)
    {
        if(!st[i]) tmp = i;
    }

    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(!num[i][j]) num[i][j] = tmp;
        }
    }
    
    int x,y; 

    for(int i=1;i<=3;i++)
    {
        cin>>x>>y;
        cout<<num[x][y]<<endl;
    }

    int op ;cin>>op;


    f[6]=10000;
    f[7]=36;    
    f[8]=720;
    f[9]=360;
    f[10]=80;
    f[11]=252;
    f[12]=108;
    f[13]=72;
    f[14]=54;
    f[15]=180;
    f[16]=72;
    f[17]=180;
    f[18]=119;
    f[19]=36;
    f[20]=306;
    f[21]=1080;
    f[22]=144;
    f[23]=1800;
    f[24]=3600;

    int sum = 0;
    switch(op){
        case 1:
            for(int i=1;i<=3;i++) sum+=num[1][i];
            cout<<f[sum]<<endl;
            break;
        case 2:
            for(int i=1;i<=3;i++) sum+=num[2][i];
            cout<<f[sum]<<endl;
            break;
        case 3:
            for(int i=1;i<=3;i++) sum+=num[3][i];
            cout<<f[sum]<<endl;
            break;
        case 4:
            for(int i=1;i<=3;i++) sum+=num[i][1];
            cout<<f[sum]<<endl;
            break;
        case 5:
            for(int i=1;i<=3;i++) sum+=num[i][2];
            cout<<f[sum]<<endl;
            break;
        case 6:
            for(int i=1;i<=3;i++) sum+=num[i][3];
            cout<<f[sum]<<endl;
            break;
        case 7:
            for(int i=1;i<=3;i++) sum+=num[i][i];
            cout<<f[sum]<<endl;
            break;
        case 8:
            for(int i=1;i<=3;i++) sum+=num[i][4-i];
            cout<<f[sum]<<endl;
            break;
    }
        
 
    return 0;
}