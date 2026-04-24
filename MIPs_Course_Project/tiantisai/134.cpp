#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;
int head,n;

int w[N]; // 节点数据
int ne[N]; // 下地址

int main()
{
    cin>>head>>n;
    for(int i=1;i<=n;i++)
    {
        int add,data,naddr;
        cin>>add>>data>>naddr;
        ne[add] = naddr;
        w[add] = data;
    }

    vector<pair<int,int>> vec;
    for(int i=head;~i;i=ne[i])  vec.push_back({w[i],i});


    for(int i=vec.size()-1,j=0;j<=i;i--,j++)
    {
        if(i==j)
        {
            printf("%05d %d -1",vec[i].y,vec[i].x);
            break;
        }
        else if(i==j+1)
        {
            printf("%05d %d %05d\n",vec[i].y,vec[i].x,vec[j].y);
            printf("%05d %d -1",vec[j].y,vec[j].x);
        }
        else{
            printf("%05d %d %05d\n",vec[i].y,vec[i].x,vec[j].y);
            printf("%05d %d %05d\n",vec[j].y,vec[j].x,vec[i-1].y);
        }
    }
    return 0;
}