#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

int main()
{
    int a[3];
    for(int i=0;i<3;i++) cin>>a[i];
    sort(a,a+3);
    for(int i=0;i<3;i++)
    {
        if(i!=2) cout<<a[i]<<"->";
        else cout<<a[i];
    }
    return 0;
}