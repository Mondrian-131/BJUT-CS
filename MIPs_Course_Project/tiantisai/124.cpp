#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e3+10;

int n,m;

int h[N];
int cnt;

void down(int x)
{
    int t = x;
    if(x*2 <= cnt && h[x*2]<h[t]) t=x*2;
    if(x*2 + 1 <=cnt && h[x*2+1]<h[t]) t=x*2+1;
    if(t!=x) {
        swap(h[t],h[x]);
        down(t);
    }
}

void up(int x)
{
    while(x>1 && h[x/2]>h[x])
    {
        swap(h[x],h[x/2]);
        x = x/2;
    }
}


int main()
{
    cin>>n>>m;  
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        h[++cnt] = x;
        up(cnt);
    }
    getchar();
    while(m--)
    {
        string s; getline(cin,s);
        if(s.find("root")!=string::npos)
        {
            string t = s.substr(0,s.find("is")-1);
            if(h[1]==stoi(t)) cout<<"T"<<endl;
            else cout<<"F"<<endl;
        }
        else if(s.find("siblings")!=string::npos)
        {
            size_t pos = s.find("and");
            string x = s.substr(0,pos-1);
            size_t pos2 = s.find("are");
            string y = s.substr(pos+4,pos2-pos-5);
            int xx = find(h+1,h+n+1,stoi(x))-h;
            int yy = find(h+1,h+n+1,stoi(y))-h;
            if(xx/2 == yy/2) cout<<"T"<<endl;
            else cout<<"F"<<endl;
        }
        else if(s.find("parent")!=string::npos)
        {
            string x = s.substr(0,s.find("is")-1);
            string y = s.substr(s.find("of")+3,s.size()-s.find("of")-3);
            int xx = find(h+1,h+n+1,stoi(x)) - h;
            int yy = find(h+1,h+n+1,stoi(y)) - h;
            if(xx == yy/2) cout<<"T"<<endl;
            else cout<<"F"<<endl;
        }
        else{
            string x = s.substr(0,s.find("is")-1);
            string y = s.substr(s.find("of")+3,s.size()-s.find("of")-3);
            int xx = find(h+1,h+n+1,stoi(x)) - h;
            int yy = find(h+1,h+n+1,stoi(y)) - h;
            if(xx==yy*2 || xx==yy*2+1) cout<<"T"<<endl;
            else cout<<"F"<<endl;
        }
    }
    return 0;
}