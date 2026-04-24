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
    int x;
    int cnt = 1;
    while(cin>>x)
    {
        if(x==250) 
        {
            cout<<cnt<<endl;
            break;
        }
        else cnt++;
    }
    return 0;
}