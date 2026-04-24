#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

int num[10];
int main()
{
    string s; cin>>s;
    for(int i=0;i<s.size();i++) 
    {
        if(s[i]=='G' || s[i]=='g') num[0]++;
        else if(s[i]=='P' || s[i]=='p') num[1]++;
        else if(s[i]=='L' || s[i] == 'l') num[2]++;
        else if(s[i]=='T' || s[i]=='t') num[3]++; 
    }
    
    int sum = 0;
    for(int i=0;i<4;i++) sum+=num[i];

    while(sum)
    {
        for(int i=0;i<4;i++)
        {
            if(num[i]>0) 
            {
                switch(i){
                    case 0: 
                        cout<<'G';
                        break;
                    case 1: 
                        cout<<'P';
                        break;
                    case 2: 
                        cout<<'L';
                        break;
                    case 3: 
                        cout<<'T';
                        break;
                }
                num[i]--;
                sum--;
            }
        }
    }    



    return 0;
}