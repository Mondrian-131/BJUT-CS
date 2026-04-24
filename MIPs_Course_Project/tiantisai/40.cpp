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
    int n; cin>>n;
    for(int i=1;i<=n;i++)
    {
        char ch; double h;
        cin>>ch>>h;
        if(ch=='F') printf("%.2f\n",h*1.09) ;
        else printf("%.2f\n",h/1.09);
    }

    return 0;
}