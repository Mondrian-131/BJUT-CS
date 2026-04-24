#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

bool st[100];

string name[100];
bool sex[100];

int main()
{   
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>sex[i]>>name[i];
    }

    for(int i=1;i<=n;i++)
    {
        if(st[i]) continue;
        for(int j=n;j>=1;j--)
        {
            if(sex[i]!=sex[j] && !st[j])
            {
                st[i] = st[j] = 1;
                cout<<name[i]<<" "<<name[j]<<endl;
                break;
            }
        }
    }
    return 0;

}