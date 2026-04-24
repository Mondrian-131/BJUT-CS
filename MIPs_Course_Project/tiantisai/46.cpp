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
    int x; cin>>x;

    int n = 0;
    int tot =0;
    while(n<x)
    {
        n = n*10+1;
        tot++;
    }
    
    vector<int> num;

    while(n%x!=0)
    {
        num.push_back(n/x); 
        n = n%x;
        n = n*10 + 1;
        tot++;
        while(n<x) 
        {
            num.push_back(0);
            tot++;
            n = n * 10 + 1;
        }
    }
    num.push_back(n/x);
    for(int i=0;i<num.size();i++) cout<<num[i];
    cout<<" "<<tot<<endl; 
    return 0;
}