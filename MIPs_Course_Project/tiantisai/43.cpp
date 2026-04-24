#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

struct BOOK{
    int hh,mm; 
    bool isborrow;
}books[1500];

int main()
{
    int n; cin>>n;
    int hh,mm;
    char ch;
    int id;

    
    int tot = 0 ;
    int time = 0; 

    while(scanf("%d %c %d:%d",&id,&ch,&hh,&mm)!=-1)
    {
        if(id == 0) 
        {
            if(tot==0) cout<<0<<" "<<0<<endl;
            else printf("%d %.0f\n",tot,time*1.0/tot);
            time=tot=0;
            for(int i=0;i<1500;i++) books[i].isborrow = false;
        }
        else if(ch == 'S')
        {
            books[id].isborrow = 1;
            books[id].hh = hh;
            books[id].mm = mm;
        } 
        else if(ch == 'E' && books[id].isborrow == true)
        {
            books[id].isborrow = false;
            int begin = books[id].hh*60 + books[id].mm;
            int end =  hh*60 + mm;
            time += end - begin;
            tot++; 
        } 
    }
    return 0;
}