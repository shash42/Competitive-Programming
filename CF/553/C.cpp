#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
const int N=1e5+5, MOD=1e9+7;
using namespace std;
int n, m, cmpcnt, cof[N], vis[N], ncnt, col[N];
struct edge
{
    int u, v, val;
} e[N];
vector<int> adj[N];
set<int> cadj[N];
void dfs(int u)
{
    vis[u]=1;
    cof[u]=cmpcnt;
    for(auto v: adj[u])
    {
        if(!vis[v])
        {
            dfs(v);
        }
    }
}
bool flag=true;
void dfs2(int u, int c)
{
    vis[u]=1;
    col[u]=c;
    for(auto v: cadj[u])
    {
        if(!vis[v])
        {
            dfs2(v, 1-c);
        }
        else if(col[u]==col[v])
        {
            flag=false;
        }
    }
}
signed main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> e[i].u >> e[i].v >> e[i].val;
    }
    for(int i = 1; i <= m; i++)
    {
        if(e[i].val==1)
        {
            adj[e[i].u].pb(e[i].v);
            adj[e[i].v].pb(e[i].u);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            cmpcnt++;
            dfs(i);
        }
    }
    for(int i = 1; i <= m; i++)
    {
        if(e[i].val==0)
        {
            if(cof[e[i].u]==cof[e[i].v])
            {
                cout << 0;
                return 0;
            }
            cadj[cof[e[i].u]].insert(cof[e[i].v]);
            cadj[cof[e[i].v]].insert(cof[e[i].u]);
        }
    }
    for(int i = 1; i <= cmpcnt; i++)
    {
        vis[i]=0;
    }
    for(int i = 1; i <= cmpcnt; i++)
    {
        if(!vis[i])
        {
            ncnt++;
            dfs2(i, 0);
        }
    }   
    if(!flag)
    {
        cout << 0;
        return 0;
    }
    int ans = 1;
    for(int i = 1; i < ncnt; i++)
    {
        ans*=2;
        ans%=MOD;
    }   
    cout << ans;
}