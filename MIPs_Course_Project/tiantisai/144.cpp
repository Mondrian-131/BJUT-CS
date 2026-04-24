#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e3+10;

int n,m,k;
int a[N];

int main()
{
    cin>>n>>m>>k;
    while(k--) 
    {
        stack<int> stk;
        int cur = 1;
        bool flag = true;
        for(int i=1;i<=n;i++)
        {
            int x; cin>>x;
            if(x==cur) cur++;
            else if(!stk.empty() && stk.top()==cur) {
                stk.pop();
                stk.push(x);
                cur++;
            }
            else{
                stk.push(x);
                if(stk.size()>k) {
                    flag = false;
                    break;
                }
            }
        }

        while(!stk.empty() && cur==stk.top()) {
            cur++;
            stk.pop();
        }

        if(stk.size()!=0) flag = false;

        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }


    return 0;
}