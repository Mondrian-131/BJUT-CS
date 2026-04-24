#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e3+10;

int  n,m,k;
stack<int> tui;
vector<int> song[N];
stack<int> box;
int idx;
int a[N];

int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }

    for(int i=n;i>=1;i--){
        tui.push(a[i]);
    }

    while(box.size() || tui.size())
    {
        idx++;
        while(1){
            if(song[idx].empty()){
                if(!box.empty()) {
                    int t = box.top(); box.pop();
                    song[idx].push_back(t);
                }
                else{
                    if(tui.empty()) break;
                    else{
                        int t= tui.top();
                        song[idx].push_back(t);
                        tui.pop();
                    }
                }
            }
            else{
                if(box.size() && box.top() <= song[idx].back())
                {
                    song[idx].push_back(box.top());
                    box.pop();
                }
                else if(tui.size())
                {
                    int t = tui.top();
                    tui.pop();
                    if(t<=song[idx].back())
                    {
                        song[idx].push_back(t);
                    }
                    else {
                        if(box.size()==m) {
                            tui.push(t);
                            break;
                        }
                        else box.push(t);
                    }
                }
                else if(tui.empty()) break;
            }
            if(song[idx].size()==k) break;
        }
    }

    for(int i=1;i<=idx;i++)
    {
        for(int j=0;j<song[i].size();j++)
        {
            if(j) cout<<" ";
            cout<<song[i][j];
        }
        cout<<endl;
    }


    return 0;
}