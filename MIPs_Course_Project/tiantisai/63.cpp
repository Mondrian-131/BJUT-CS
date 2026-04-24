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
        int s,h,w; cin>>s>>h>>w;
        if(s)
        {
            if(h>130) cout<<"ni li hai!"<<" ";
            else if(h==130) cout<<"wan mei!"<<" ";
            else cout<<"duo chi yu!"<<" ";

            if(w>27) cout<<"shao chi rou!"<<endl;
            else if(w==27) cout<<"wan mei!"<<endl;
            else cout<<"duo chi rou!"<<endl;
        }
        else{
            if(h>129) cout<<"ni li hai!"<<" ";
            else if(h==129) cout<<"wan mei!"<<" ";
            else cout<<"duo chi yu!"<<" ";

            if(w>25) cout<<"shao chi rou!"<<endl;
            else if(w==25) cout<<"wan mei!"<<endl;
            else cout<<"duo chi rou!"<<endl;
        }
    }
    return 0;
}