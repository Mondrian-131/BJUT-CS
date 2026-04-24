#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

int a[N];
int main()
{
    int n; cin>>n;
    int max = 1,min = 1;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        if(a[i]>a[max]) max = i;
        if(a[i]<a[min]) min = i;
    }

    int s1=0,s2=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==a[max]) s1++;
        if(a[i]==a[min]) s2++;
    }

    cout<<a[min]<<" "<<s2<<endl;
    cout<<a[max]<<" "<<s1<<endl;
    return 0;
}