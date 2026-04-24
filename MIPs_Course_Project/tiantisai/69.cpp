#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

pair<int,int> taiya[5];
int main()
{
    int low,cha; 

    for(int i=1;i<5;i++) 
    {
        cin>>taiya[i].first;
        taiya[i].second = i;
    }
    cin>>low>>cha;

    sort(taiya+1,taiya+5);
    int sum = 0;
    for(int i=1;i<=4;i++)
    {
        if(abs(taiya[i].first-taiya[4].first)>cha || taiya[i].first<low) sum++;
    }

    if(!sum)  cout<<"Normal"<<endl;
    else if(sum==1) printf("Warning: please check #%d!",taiya[1].second);
    else cout<<"Warning: please check all the tires!"<<endl;

    return 0;
}