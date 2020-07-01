#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long

using namespace std;

const int N=1e5+5, INF=1e18+18;
int n, l, ans=0;
struct node
{
    node *c[2]={NULL, NULL};
    int d, cnt=0;
    bool end=false;
};
node *getNode(int d)
{
    node *ret = new node;
    ret->d = d;
    return ret;
}
void insert(string &s, int idx, node *curr)
{
    curr->cnt++;
    if(idx==s.length())
    {
        curr->end = true;
        return;
    }
    if(!curr->c[0])
    {
        curr->c[0] = getNode(curr->d + 1);
    }
    if(!curr->c[1])
    {
        curr->c[1] = getNode(curr->d + 1);
    }
    int ch = s[idx]-'0';
    insert(s, idx+1, curr->c[ch]);
}
void dfs(node *curr)
{
   // cout << curr->cnt << endl;
    //  cout << curr->d << endl;
    int h = l - curr->d + 1;
    if(!curr->c[0] && !curr->c[1])
    {
        if(curr->end) return;
        int div;
        for(int i = 1; i < INF; i<<=1)
        {
            if(h%i==0) div=i;
        }
     //   cout << curr->d << " " << div << endl;
        ans^=div;
        return;
    }
    dfs(curr->c[0]);
    dfs(curr->c[1]);
}
signed main()
{
    cin >> n >> l;
    node *root = getNode(0);
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        insert(s, 0, root);
    }
    dfs(root);
    if(ans)
    {
        cout << "Alice";
    }
    else
    {
        cout << "Bob";
    }
}