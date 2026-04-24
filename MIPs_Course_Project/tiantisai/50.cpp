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
    int l,n;
    cin>>l>>n; 
    int num = pow(26, l); 
    num -= n;

    vector<int> item;


    if(!num) item.push_back(0);
    while(num)
    {
        item.push_back(num%26);
        num/=26;
    }

    for(int i=item.size()-1;i>=0;i--) printf("%c",item[i]+'a');

    return 0;
}