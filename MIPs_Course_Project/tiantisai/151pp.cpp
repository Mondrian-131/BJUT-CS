#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
typedef pair<int, vector<int> >   vpiv;
const int N = 10010, M = 110;
map<vector<int>, int> cnt;
vector<pair<int, vector<int> > > ans;
int n, m;

bool cmp(vpiv a,vpiv b)
{
    if(a.first != b.first) return a.first>b.first;
    return a.second < b.second;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		vector<int> temp;
		for (int j = 0; j < m; j++)
		{
			int x;
			scanf("%d", &x);
			temp.push_back(x);
		}
		cnt[temp]++;
	}
	for (auto &u : cnt) ans.push_back({ u.second, u.first });
	sort(ans.begin(), ans.end(),cmp);
	printf("%d\n", cnt.size());
	for (auto &u : ans)
	{
		printf("%d", u.first);
		for (auto &v : u.second)
			printf(" %d", v);
		puts("");
	}
	return 0;
}
