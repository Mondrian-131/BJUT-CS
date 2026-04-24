#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 60;

set<int> arr[N];
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int m; cin>>m;
        for(int j=1;j<=m;j++)
        {
            int x; cin>>x; 
            arr[i].insert(x);
        }
    }

    int k ; cin>>k;

    while(k--)
    {
        int a,b; cin>>a>>b;

        int c = 0;
        for(auto it : arr[a]) 
        {
            if(arr[b].count(it)) c++;
        }
        set<int> temp;
        for(auto it : arr[a]) temp.insert(it);
        for(auto it: arr[b]) temp.insert(it);
        int t= temp.size();

        // printf("%.2f%%\n",1.0*c/t*100);
        cout<<setprecision(2)<<fixed<<c*1.0/t*100<<endl;

    }
    return 0;
}