#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 50+10;

struct TNode{
    TNode* left;
    TNode* right;
    int key;
    TNode(int val) : key(val),left(nullptr),right(nullptr){}
};

int n;

int post[N];
int in[N];


TNode* build(TNode*root,int l,int r)
{
    if(l>r) return nullptr;
    if(l==r) return new TNode(post[l]);

    root = new TNode(post[r]);

    int pos = find(in+1, in+n+1,post[r])-in;

    int ptr = l;
    while(ptr<=r-1) 
    {
        if(find(in+1,in+n+1,post[ptr])-in<pos) ptr++;
        else break;
    }

    if(ptr==l) root->right = build(root->right,l,r-1);
    else if(ptr==r) root->left = build(root->left,l,r-1);
    else{
        root->left = build(root->left,l,ptr-1);
        root->right = build(root->right,ptr,r-1);
    }

    return root;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>post[i];
    for(int i=1;i<=n;i++) cin>>in[i];

    TNode* root = nullptr; 
    root = build(root,1,n);

    vector<int> ans;
    queue<TNode*> q;
    q.push(root);

    while(q.size())
    {
        auto t = q.front();
        q.pop();
        ans.push_back(t->key);

        if(t->left) q.push(t->left);
        if(t->right) q.push(t->right);
    }

    for(int i=0;i<ans.size();i++)
    {
        if(i) cout<<" ";
        cout<<ans[i];
    }
    return 0;
}