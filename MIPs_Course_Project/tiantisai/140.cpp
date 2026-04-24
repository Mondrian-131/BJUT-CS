#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e3+10;

int n,m;
vector<string> vec[N];

double a[N];
double b[N];

int main()
{
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        int k; cin>>k;
        for(int j=1;j<=k;j++)
        {
            string x; cin>>x; vec[i].push_back(x);
        }
    }

    string s1,s2;
    cin>>s1>>s2;

    int A,B; 
    if(s1[0]=='-') A=-1,B=1;
    else A=1,B=-1;

    for(int i=1;i<=m;i++)
    {
        bool aa = false;
        bool bb = false;
        for(auto t : vec[i])
        {
            if(t==s1) aa = 1;
            if(t==s2) bb= 1;
        }
        
        if(aa)
        {
            for(auto t : vec[i])
            {
                if(A < 0 && t[0]!='-') {
                    a[abs(stoi(t))]+= 1.0/vec[i].size();
                }
                else if(A >0 && t[0]=='-') a[-stoi(t)]+=1.0/vec[i].size();
            }
        }
        if(bb)
        {
            for(auto t : vec[i])
            {
                if(B <0 && t[0]!='-') b[stoi(t)]+=1.0/vec[i].size();
                else if(B >=0 && t[0]=='-') b[-stoi(t)]+=1.0/vec[i].size();
            }
        }
    }

    vector<int> v1,v2;
    double ma = 0;
    double mb = 0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>ma)
        {
            ma = a[i];
            v1.clear();
            v1.push_back(i);
        }
        else if(a[i]==ma) v1.push_back(i);

        if(b[i]>mb)
        {
            mb = b[i];
            v2.clear();
            v2.push_back(i);
        }
        else if(b[i]==mb) v2.push_back(i);
    }

    bool a1=false;
    bool a2 = false;

    for(auto t: v1) 
    {
        if(t==abs(stoi(s2))) a1=1;
    }

    for(auto t :v2)
        if(t==abs(stoi(s1))) a2=1;

    if(a1 && a2) cout<<s1<<" "<<s2<<endl;
    else{
        for(auto t :v1) {
            if(A>0) cout<<s1<<" -"<<t<<endl;
            else cout<<s1<<" "<<t<<endl;
        }
        for(auto t :v2) {
            if(B>0) cout<<s2<<" -"<<t<<endl;
            else cout<<s2<<" "<<t<<endl;
        }
    }
    return 0;
}