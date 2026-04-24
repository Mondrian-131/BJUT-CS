#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 50+10;

int n;
int a[N];

struct node{
    int left;
    int right;
    int val;
}tr[N];

int idx;

int build(int l,int r)
{
    if(l>r) return -1;
    if(l==r) {
        tr[++idx] = {-1,-1,a[l]};
        return idx;
    }
    int tot = r-l+1;
    int k  = (int)log2(tot);
    int cnt = 0;
    cnt += ((int)pow(2,k)-2)/2;
    
    int t= (int)pow(2,k)/2;
    int temp = tot-(int)pow(2,k)+1;
    if(temp<t) cnt+=temp;
    else cnt+=t; 

    int root = ++idx;
    tr[root].left = build(l,l+cnt-1);
    tr[root].right = build(l+cnt,r-1);
    tr[root].val = a[r];

    return root;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    int root = build(1,n);

    vector<int> ans;
    queue<int> q;
    q.push(root);
    while(q.size())
    {
        int t = q.front();q.pop();
        ans.push_back(tr[t].val); 

        if(~tr[t].left) q.push(tr[t].left);
        if(~tr[t].right) q.push(tr[t].right);
    }

    for(int i=0;i<ans.size();i++)
    {
        if(i) cout<<" ";
        cout<<ans[i];
    }

    return 0;
}