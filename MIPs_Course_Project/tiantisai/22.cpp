#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define x first
#define y second
typedef long long ll;

const int mod = 998244353;
const int N = 1e5 + 10;

int main() 
{
    int n; cin>>n;
    int ji=0,ou=0;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        if(x%2==1) ji++;
        else ou++;
    }

    cout<<ji<<" "<<ou<<endl;
    return 0;
}