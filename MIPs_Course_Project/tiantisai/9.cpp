#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
typedef pair<ll,ll> pll;
const int mod = 998244353;
const int N = 1e5+10;

typedef struct{
    int op ;
    ll a,b;
} Frac;


Frac yf(Frac x)
{
    ll a = x.a;
    ll b = x.b; 

    ll p = __gcd(a,b);
    a = a/p;
    b = b/p;

    return {x.op,a,b};
}


Frac add(Frac x,Frac y)
{
    int op1 = x.op;
    int op2 = y.op;
    int op3;
    ll sum1,sum2;
    if(!op1 && !op2)
    {
        sum1 = x.a*y.b + y.a*x.b;  
        sum2 = x.b * y.b;
        op3 = 0;
    }
    else if(op1==0 && op2==1)
    {
        sum1 = abs(x.a*y.b-x.b*y.a) ;
        sum2 = x.b * y.b;
        op3 = ((x.a*y.b-x.b*y.a)>=0) ? 0 :1;
    }
    else if(op1==1 && op2==0)
    {
        sum1 = abs(x.b*y.a - x.a*y.b);
        sum2 = x.b * y.b;
        op3 = ((x.b*y.a - x.a*y.b)>=0) ? 0:1;
    }
    else{
        sum1 = x.a*y.b + y.a*x.b; 
        sum2 = x.b*y.b; 
        op3 = 1;
    }
    return yf({op3,sum1,sum2});
}

int main()
{
    int n; cin>>n;

    string s;
    cin>>s;
    Frac ans;
    ll a,b;
    int op = 0;
    if(s[0]=='-') op = 1;
    string p = "";
    for(int i=op;i<s.size();i++)
    {
        if(s[i]!='/')p += s[i];  
        if(s[i]=='/') 
        {
            a = stoll(p);
            p =  "";
        }
        if(i==s.size()-1) b = stoll(p);
    }
    

    ans.op =  op;
    ans.a = a;
    ans.b = b;
    ans = yf(ans);

    for(int i=0;i<n-1;i++)
    {
        cin>>s;
        op = 0;
        p= "";
        if(s[0]=='-') op = 1;
        for(int j=op;j<s.size();j++)
        {
            if(s[j]!='/')p += s[j];  
            if(s[j]=='/') 
            {
                a = stoll(p);
                p =  "";
            }
            if(j==s.size()-1) b = stoll(p);
        }
        Frac temp = {op,a,b}; 
        ans = add(ans,temp);
    }
    
    // cout<<ans.a<<" "<<ans.b<<endl;

    if(ans.a==0) cout<<0;
    else{
        if(ans.a<ans.b)
        {
            if(ans.op==0) cout<<ans.a<<"/"<<ans.b;
            else cout<<"-"<<ans.a<<"/"<<ans.b;
        }
        else if(ans.a%ans.b==0) // bug1
        {
            if(ans.op==0) cout<<ans.a/ans.b;
            else cout<<'-'<<ans.a/ans.b;
        }
        else{
            if(ans.op==0)
            {
                cout<<ans.a/ans.b<<" ";
                cout<<ans.a-ans.a/ans.b*ans.b<<"/"<<ans.b;
            }
            else{
                cout<<"-"<<ans.a/ans.b<<" ";
                cout<<"-"<<ans.a-ans.a/ans.b*ans.b<<"/"<<ans.b;
            }
        }
    }
    return 0;
}
