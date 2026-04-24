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
    int num1,num2;
    int n; 
    cin>>num1>>num2;
    cin>>n;
    
    int sum1=0,sum2=0; 
    
    for(int i=0;i<n;i++)
    {
        int  a,b,c,d; cin>>a>>b>>c>>d;
        if(a+c==b && a+c!=d) sum1++;
        if(a+c==d && a+c!=b) sum2++;

        if(sum1>num1){
            cout<<"A"<<endl;
            cout<<sum2<<endl;
            break;
        }
        if(sum2>num2)
        {
            cout<<"B"<<endl;
            cout<<sum1<<endl;
            break;
        }
    }
    return 0;
}


// 审题问题：酒量的定义。