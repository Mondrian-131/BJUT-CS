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
    int hh,mm; 
    scanf("%d:%d",&hh,&mm);

    if(hh>=0 && hh<=12)
    {
        printf("Only %02d:%02d.  Too early to Dang.",hh,mm);
    }
    else{
        int ans = hh-12;
        if(mm!=0) ans+=1;
        for(int i=0;i<ans;i++) cout<<"Dang";
    }
    return 0;
}