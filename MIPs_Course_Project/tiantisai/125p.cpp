#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define endl "\n"
#define PII pair<int,int>
#define INF 0x3f3f3f3f

const int N = 5e2+10;

bool mp[N][N];
bool vis[N],over[N];
int n,m;

void dfs(int u){
	if(vis[u]) return;
	vis[u] = true;
	for(int i = 0;i < n; ++i) {
		if(i != u && mp[u][i] && !over[i])
			dfs(i);
	}
}

int get_num(){
	int ans = 0;
	memset(vis,false,sizeof vis);
	for(int i = 0;i < n; ++i) {
		if(!vis[i] && !over[i]){
			dfs(i);
			ans++;
		}
	}
	return ans;
}

int main()
{
	cin>>n>>m;
	int u,v;
	for(int i = 1;i <= m; ++i) {
		cin>>u>>v;
		mp[u][v] = mp[v][u] = true;
	}
	int k,t,num = get_num();
	cin>>k;
	for(int i = 1;i <= k; ++i) {
		cin>>t;
		over[t] = true;
		int loc = get_num();
        printf("liantong:%d\n",loc);
		if(loc > num) {	
			cout<<"Red Alert: City "<<t<<" is lost!"<<endl;
		} else {
			cout<<"City "<<t<<" is lost."<<endl;
		}
		num = loc;
			
	}
	if(k == n) cout<<"Game Over."<<endl;
	
	return 0;
}
