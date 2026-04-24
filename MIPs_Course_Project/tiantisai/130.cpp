#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
typedef pair<int,double> pid;
const int mod = 998244353;
const int N = 1e5+10;
const double eps = 1e-5;

vector<pid> mul(vector<pid>& A,pid B)
{
    vector<pid> ans;
    int e1 = B.x;
    double c1 = B.y;
    for(auto t : A)
    {
        int e2 = t.x;
        double c2 = t.y;
        ans.push_back({e1+e2,c1*c2});
    }
    return ans;
}

vector<pid> sub(vector<pid>& A,vector<pid>& B)
{
    vector<pid> ans;    
    vector<double> a(1000,0);// 假设指数最高为999
    vector<double> b(1000,0);
    for(auto t : A)
    {
        if(t.y!=0) a[t.x] = t.y;
    }
    for(auto t : B)
    {
        if(t.y!=0) b[t.x] = t.y;
    }
    for(int i=999;i>=0;i--)
    {
        if(a[i]!=0 || b[i]!=0) ans.push_back({i,a[i]-b[i]}); // 之后要考虑将系数为0的位置去掉
    }
    return ans;
}

int main()
{
    vector<pid> A,B; 
    int n; cin>>n;
    for(int i=1;i<=n;i++)
    {
        int e; double c;
        cin>>e>>c;
        A.push_back({e,c});
    }
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int e;double c;
        cin>>e>>c;
        B.push_back({e,c});
    }

    vector<pid> shang;
    while(1)
    {
        if(A.empty()) break;
        if(A.front().x < B.front().x) break;

        int e = A.front().x - B.front().x;
        double c = A.front().y / B.front().y;
        shang.push_back({e,c});

        vector<pid> temp = mul(B,{e,c});

        A = sub(A,temp);

        temp.clear();
        for(auto t : A)
        {
            if(fabs(t.y)>eps) temp.push_back({t.x,t.y});
        }
        A = temp;
    }
    
    int sum = 0;
    vector<pid> shang1;
    vector<pid> A1;
    for(auto t :shang)
    {
        if(fabs(10*t.y)>=0.5) shang1.push_back({t.x,t.y}) ;
    }
    for(auto t :A)
    {
        if(fabs(10*t.y)>=0.5) A1.push_back({t.x,t.y}) ;
    }

    if(shang1.size()==0)
    {
        cout<<"0 0 0.0";
    }
    else{
        cout<<shang1.size()<<" ";
        for(int i=0;i<shang1.size();i++)
        {
            if(i) cout<<" ";
            printf("%d %.1lf",shang1[i].x,shang1[i].y);
        }
    }

    cout<<endl;

    if(A1.size()==0) cout<<"0 0 0.0";
    else{
        cout<<A1.size()<<" ";
        for(int i=0;i<A1.size();i++)
        {
            if(i) cout<<" ";
            printf("%d %.1lf",A1[i].x,A1[i].y);
        }
    }

    return 0;
}