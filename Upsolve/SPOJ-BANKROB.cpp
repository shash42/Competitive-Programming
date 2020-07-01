#include<bits/stdc++.h>
#define pb push_back

using namespace std;

const int N = 3002, INF=1e9;
int n, m, s, t, vis[N];
struct edge
{
    int u, v, cap;
};
vector<edge> edges;
vector<int> adj[N];
vector<int> stk;
int dfs(int u, int sink)
{
  //  cout << "node: " << u << endl;
    vis[u]=1;
    if(u==sink)
    {
        int mn = INF;
        for(auto v: stk)
        {
           // cout << edges[v].v << " - ";
            mn = min(mn, edges[v].cap);
        }
        if(mn==0) return mn; //dont update edges if path not found
        for(auto v: stk)
        {
            edges[v].cap -= mn;
            edges[v^1].cap += mn;
        }
        return mn;
    }
    int ret = 0;
    for(int i = 0; i < adj[u].size(); i++)
    {
        edge e = edges[adj[u][i]];
        if(!vis[e.v] && e.cap > 0)
        {
            stk.pb(adj[u][i]);
            ret = max(ret, dfs(e.v, sink));
            if(ret) return ret;
        }
    }
    stk.pop_back();
    return ret;
}
int FF(int numv, int source, int sink)
{
    int maxflow = 0;
    while(true)
    {
        for(int i = 1; i <= numv; i++)
        {
            vis[i]=0;
        }
        int flow = dfs(source, sink);
        stk.clear();
        if(flow==0) break;
        maxflow += flow;
    }
    return maxflow;
}
void addedge(int u, int v, int cap)
{
    adj[u].pb(edges.size());
    edges.pb({u, v, cap});
    adj[v].pb(edges.size());
    edges.pb({v, u, 0});
}
signed main()
{
    cin >> n >> m;
    cin >> s >> t;
    for(int i = 1; i <= n; i++)
    {
        if(i==s || i==t) continue;
        addedge(i*2+1, i*2, 1); //incoming to outgoing
    }
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        addedge(2*x, 2*y+1, INF); //outgoing to incoming
        addedge(2*y, 2*x+1, INF);
    }
    addedge(2*s+1, 2*s, INF); //incoming to outcoming in source/sink is INF
    addedge(2*t+1, 2*t, INF);
    int maxflow = FF(2*n+1, 2*s+1, 2*t);
    cout << maxflow;
}