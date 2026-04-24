#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e4+10;

bool st[N];

int get(int x)
{
    int sum = 0;
    while(x) {
        sum +=(x%10)* (x%10);
        x/=10;
    }
    return sum;
}

bool isprime(int x)
{
    for(int i=2;i<=x/i;i++)
    {
        if(x%i==0) return false;
    }
    return true;
}

int main()
{
    int A,B; cin>>A>>B;
    
    vector<int> ans;

    for(int i=A;i<=B;i++) st[i]=1;

    for(int i=A;i<=B;i++)
    {
        if(!st[i]) continue;
        vector<int> num;
        unordered_map<int,int> mp;
        int t = i;
        bool flag = false;
        while(1)
        {
            if(mp.count(t)) break;
            mp[t] = 1;
            num.push_back(t);
            t = get(t);
            if(t==1) 
            {
                num.push_back(1);
                flag = 1;
                break;
            } 
        }
        if(flag)
        {
            for(auto t : num)
                if(t!=i && t>=A && t<=B) st[t] = false; 
        }
        else{
            for(auto t :num)
                if(t>= A && t<=B) st[t] = false;
        }
    }

    bool has = false;
    for(int i=A;i<=B;i++)
    {
        if(st[i])
        {
            has = true;
            int t = i;
            int cnt = 0;
            while(1){
                if(t==1) break;
                t = get(t); 
                cnt++;
            }
            if(isprime(i)) cnt = cnt*2;
            cout<<i<<" "<<cnt<<endl;
        }
    }

    if(!has) cout<<"SAD"<<endl;

    return 0;
}