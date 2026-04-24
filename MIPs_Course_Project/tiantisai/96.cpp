#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

int get(int x)
{
    int sum = 0;
    while(x)
    {
        sum+=x%10;
        x/=10;
    }
    return sum;
}



int main()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b; cin>>a>>b;
        int aa = get(a),bb=get(b);
        if(a%bb==0 && b%aa!=0) cout<<"A"<<endl;
        else if(a % bb!=0 && b%aa==0) cout<<"B"<<endl;
        else{
            if(a>b) cout<<"A"<<endl;
            else cout<<"B"<<endl;
        }
    }
    return 0;
}