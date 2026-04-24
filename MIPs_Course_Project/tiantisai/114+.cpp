#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
typedef long long ll;
const int mod = 998244353;
const int N = 1e5+10;

int e[N],ne[N];

int st[N];

int addr,n;

bool flag ;

int head,tail;

void insert(int addr)
{
    if(!flag) {
        flag = 1;
        head = tail = addr;
        ne[tail] = -1;
    }
    else{
        ne[tail] = addr;
        tail = addr;
        ne[tail] =-1;
    }
}

// 模拟链表插入和删除的方式
int main()
{
    cin>>addr>>n;
    
    for(int i=1;i<=n;i++)
    {
        int a,w,ver;
        cin>>a>>w>>ver;
        e[a] = w;
        ne[a] = ver;
    }

    int pre;
    for(int i=addr;~i;i=ne[i])
    {
        int j = e[i];
        if(!st[abs(j)]) {
            st[abs(j)] = 1;
        }
        else{
            insert(i);
        }
    }

    return 0;
}