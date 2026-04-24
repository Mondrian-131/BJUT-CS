#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e3+10;

struct STU{
    string num;
    int t;
}stu[N];

int main()
{
    int n; 
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        string s;
        int a,b;
        cin>>s>>a>>b;
        stu[a].num = s;
        stu[a].t = b;
    }
    
    int m;
    cin>>m;

    for(int i=0;i<m;i++)
    {
        int x; cin>>x;
        cout<<stu[x].num<<" "<<stu[x].t<<endl;
    }
    return 0;
}