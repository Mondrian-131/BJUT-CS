#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 3e4+10;

int D,P;

struct node{
    int id;
    string name;
    string num;
    int body;
    string time;
};

int idx;

bool cmp(node a,node b)
{
    int at = 60*stoi(a.time.substr(0,2)) + stoi(a.time.substr(3,2));
    int bt = 60*stoi(b.time.substr(0,2)) + stoi(b.time.substr(3,2));
    if(at!=bt) return at < bt;
    return a.id < b.id;
}

bool isnum(string s)
{
    for(int i=0;i<s.size();i++)
    {
        if(!isdigit(s[i])) return false;
    }
    return true;
}

int main()
{
    cin>>D>>P;

    unordered_map<string,int> mp;
    vector<pair<string,string>> ans;
    unordered_map<string,int> reque;
    
    for(int i=1;i<=D;i++)
    {
        int T,S; cin>>T>>S;
        vector<node> vec;
        unordered_map<string,int>  ha;
        for(int j=1;j<=T;j++)
        {
            string name,num,time;
            int body; 
            cin>>name>>num>>body>>time;
            if(num.size()==18 && isnum(num) && body==1 && !mp.count(num)) {
                mp[num]=1;
                ans.push_back({name,num});
            }
            if(!isnum(num)) continue;
            if(num.size()!=18) continue;
            if(reque.count(num) && i - reque[num] <= P) continue;
            // if(ha.count(num)) continue; // 不一定是按照时间顺序给的，如果这里先来的是一个时间靠后的，那时间靠前的就不能加入了。
            // ha[num] = 1;
            idx++;
            vec.push_back({idx,name,num,body,time});
        }

        sort(vec.begin(),vec.end(),cmp);

        if(S==0) continue;
        for(int j=0;j<vec.size();j++)
        {
            if(reque[vec[j].num]==i) continue;
            reque[vec[j].num]=i;
            cout<<vec[j].name<<" "<<vec[j].num<<endl;
            S--;
            if(S<=0) break;

        }

    }

    for(auto t : ans) {
        cout<<t.x<<" "<<t.y<<endl;
    }
    return 0;
}