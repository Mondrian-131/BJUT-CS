#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

string name[N];
int num[N];
int main()
{
    int n; cin>>n;
    int sum = 0;
    for(int i=1;i<=n;i++) 
    {
        cin>>name[i]>>num[i];
        sum += num[i];
    }

    double avg = sum*1.0/n/2.0;
    double min = fabs(avg-num[1]);
    string ans = name[1];
    for(int i=1;i<=n;i++)
    {
        if(fabs(num[i]-avg)<min)
        {
            ans = name[i];
            min = fabs(num[i]-avg);
        }
    }
    
    cout<<(int)avg<<" "<<ans<<endl;

    return 0;
}