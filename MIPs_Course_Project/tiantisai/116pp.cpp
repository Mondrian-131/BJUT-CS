#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

int n; 
int a[N];
int mirror = false;
vector<int> ans;
struct TNode{
    int key;
    TNode* left;
    TNode* right;

    TNode(int val): key(val),left(nullptr),right(nullptr){}
};

TNode* insert(TNode* root,int val)
{
    if(root==nullptr) return new TNode(val);

    if(root->key<=val) root->right = insert(root->right,val);
    else root->left = insert(root->left,val);

    return root; // ?
}

void preOrder(TNode* root)
{
    if(root==nullptr) return ;

    ans.push_back(root->key);
    if(!mirror)
    {
        preOrder(root->left);
        preOrder(root->right);
    }
    else{
        preOrder(root->right);
        preOrder(root->left);
    }
}

void postOrder(TNode* root)
{
    if(root==nullptr) return;
    if(mirror)
    {
        postOrder(root->right);
        postOrder(root->left);
    }
    else {
        postOrder(root->left);
        postOrder(root->right);
    }
    ans.push_back(root->key);
}


int main()
{
    cin>>n;
    TNode * root  = nullptr;     
    for(int i=0;i<n;i++) {
        cin>>a[i];
        root = insert(root,a[i]);
    }

    preOrder(root);
    for(int i=0;i<ans.size();i++)
    {
        if(a[i]!=ans[i]) {
            mirror = 1;
            break;
        }
    }
    if(mirror)
    {
        ans.clear();
        preOrder(root);
        for(int i=0;i<n;i++)
        {
            if(a[i]!=ans[i])
            {
                mirror = 2;
                break;
            }
        }
    }
    
    if(mirror==2) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        ans.clear();
        postOrder(root);

        for(int i=0;i<ans.size();i++)
        {
            if(i) cout<<" ";
            cout<<ans[i];
        }
    }


    return 0;
}