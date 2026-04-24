#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;
int n;

int main()
{
    cin>>n;
    stack<int> stk1;
    stack<char> stk2;
    for(int i=1;i<=n;i++) 
    {
        int x; cin>>x;
        stk1.push(x);
    } 
    for(int i=1;i<=n-1;i++)
    {
        char ch;cin>>ch;
        stk2.push(ch);
    }

    while(!stk2.empty())
    {
        int op1 = stk1.top();
        stk1.pop();
        int op2 = stk1.top();
        stk1.pop();

        char ch = stk2.top();
        stk2.pop();

        if(ch=='+'){
            stk1.push(op1+op2);
        }
        else if(ch=='-') stk1.push(op2-op1);
        else if(ch=='*') stk1.push(op1*op2);
        else{
            if(op1==0) {
                printf("ERROR: %d/0",op2);
                return 0;
            }
            else stk1.push(op2/op1);
        }
    }

    cout<<stk1.top()<<endl;
    return 0;
}