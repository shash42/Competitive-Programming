#include<bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
const int N=1e5+5, INF=1e9;
using namespace std;
int n, k, val[N], par[N], l[N], r[N];
vector<int> adj[N];
bool can=true;
void dfs2(int u, int x)
{
    if(l[u]<=x-1 && x-1<=r[u])
    {
        val[u]=x-1;
    }
    else if(l[u]<=x+1 && x+1<=r[u])
    {
        val[u]=x+1;
    }
    else
    {
        cout << u << ": Ye to bakchodi hogai" << endl;
        exit(7);
    }
    for(auto v: adj[u])
    {
        if(v!=par[u] && val[v]==-1)
        {
            dfs2(v, val[u]);
        }
    }
}
void dfs1(int u)
{
    l[u]=-1; r[u]=INF;
    for(auto v: adj[u])
    {
        if(v==par[u]) continue;
        par[v]=u;
        dfs1(v);
        if(!can) return;
        if(l[v]==-1) continue;
        if(l[u]!=-1)        //have been initialized
        {
            if( (l[u]%2 == l[v]%2) || (r[u]%2 == r[v]%2) ) // if equal then -1 +1 wont give same parity
            {
                can=false;
                return;
            }
        }
        l[u]=max(l[v]-1, l[u]);
        r[u]=min(r[v]+1, r[u]);
    }
    if(val[u]!=-1)
    {
        if(l[u]>val[u] || r[u]<val[u] || ( (l[u] != -1) && (r[u]%2 != val[u]%2) ) ) //in range, if initialized same parity
        {
            can=false;
            return;
        }  
        for(auto v: adj[u])
        {
            if(v!=par[u] && val[v]==-1)
            {
                dfs2(v, val[u]);
            }
        }
        l[u]=val[u];
        r[u]=val[u];
    }
   // cout << u << " - " << l[u] << " " << r[u] << endl;
}
signed main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        val[i]=-1;
    }
    for(int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    cin >> k;
    int root;
    for(int i = 0; i < k; i++)
    {
        int v, p;
        cin >> v >> p;
        root = v;
        val[v]=p;
    }
    dfs1(root);
    if(!can)
    {
        cout << "No";
    }
    else
    {
        cout << "Yes" << endl;
        for(int i = 1; i <= n; i++)
        {
            cout << val[i] << endl;
        }
    }
    
}