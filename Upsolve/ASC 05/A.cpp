#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define pb push_back
#define F first
#define S second
#define lint long long
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define SET(x, val) memset(x, val, sizeof(x))
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e2 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

//MinCostFlow
struct MinCostFlow{
/*  Runtime: O(iter*NM), on hacks: O(2^N/2 * NM)
Usage: MinCostFlow mcmf(totalNodes);
mcmf.addEdge(u, v, capacity, cost); // directed edge
auto ans = mcmf.getMinCostFlow(source, sink); // <flow, cost> */
    struct Edge{
        int u, v; int cap, cost;
        Edge(int _u, int _v, int _cap, int _cost){
            u = _u; v = _v; cap = _cap; cost = _cost;
        }
    };
    int n, s, t; int flow, cost;
    vector<vector<int> > graph; vector<Edge> e;
    vector<int> dist; vector<int> parent;
    MinCostFlow(int _n){
        n = _n; // 0-based indexing
        graph.assign(n, vector<int> ());
    }
    void addEdge(int u, int v, int cap, int cost, bool directed = true){
        graph[u].push_back(e.size());
        e.push_back(Edge(u, v, cap, cost));
        graph[v].push_back(e.size());
        e.push_back(Edge(v, u, 0, -cost));
        if(!directed)
            addEdge(v, u, cap, cost, true);
    }
    pair<int, int> getMinCostFlow(int _s, int _t){
        s = _s; t = _t;
        flow = 0, cost = 0;
        while(SPFA())
            flow += sendFlow(t, 1<<20);
        return make_pair(flow, cost);
    }
    bool SPFA(){ // not sure about negative cycle
        parent.assign(n, -1);
        dist.assign(n, 1<<20);  dist[s] = 0;
        vector<int> queuetime(n, 0); queuetime[s] = 1;
        vector<bool> inqueue(n, 0); inqueue[s] = true;
        queue<int> q; q.push(s); bool negativecycle = false;

        while(!q.empty() && !negativecycle){
            int u = q.front(); q.pop(); inqueue[u] = false;

            for(int i = 0; i < graph[u].size(); i++){
                int eIdx = graph[u][i];
                int v = e[eIdx].v, w = e[eIdx].cost, cap = e[eIdx].cap;
                if(dist[u] + w < dist[v] && cap > 0){
                    dist[v] = dist[u] + w;
                    parent[v] = eIdx;
                    if(!inqueue[v]){
                        q.push(v);
                        queuetime[v]++;
                        inqueue[v] = true;
                        if(queuetime[v] == n+2){
                            negativecycle = true;
                            break;
                        }
                    }
                }
            }
        } return dist[t] != (1<<20);
    }
    int sendFlow(int v, int curFlow){
        if(parent[v] == -1) return curFlow;
        int eIdx = parent[v];
        int u = e[eIdx].u, w = e[eIdx].cost;
        int f = sendFlow(u, min(curFlow, e[eIdx].cap));
        cost += f*w;
        e[eIdx].cap -= f;
        e[eIdx^1].cap += f;
        return f; }
};

int m, n, d[N], ginw[N], ans[N], inf=1e3, must[N], cntmust;
vi adj[N];
pii solve(int k, int pr=0)
{
    MinCostFlow mcmf(m+n+3);
    int super = m+n+2, source = 0, sink = m+n+1;
    mcmf.addEdge(super, source, k, 0);
    for(int i = 1; i <= m; i++)
    {
        mcmf.addEdge(source, i, 1, 0);
    }
    for(int i = m+1; i <= m+n; i++)
    {
        if(must[i-m]) mcmf.addEdge(i, sink, 1, -inf);
        else mcmf.addEdge(i, sink, 1, 0);
    }
    for(int i = 1; i <= n; i++)
    {
        for(auto v: adj[i])
        {
            if(must[i] && i!=ginw[v])
            {
                mcmf.addEdge(v, i+m, 1, 1);
            }
            else mcmf.addEdge(v, i+m, 1, 0);
        }
    }
    pii anss = mcmf.getMinCostFlow(super, sink);
    if(pr==0) return anss;
    cout << anss.first << " " << anss.second + cntmust*(inf) << endl;
    for(auto e: mcmf.e)
    {
        if(e.u<=m && e.v>m &&e.cap==0)
        {
            //if(ans[e.u]!=0) exit(7);
            ans[e.u] = e.v - m;
        }
        //cout << e.u << " " << e.v << " " << e.cap << " " << e.cost << endl;
    }
    for(int i = 1; i <= m; i++)
    {
        cout << ans[i] << " ";
    }
    return anss;
}
signed main()
{
    fastio;
    freopen("keeper.in", "r", stdin);
    freopen("keeper.out", "w", stdout);
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
    {
        cin >> d[i];
        for(int j = 0; j < d[i]; j++)
        {
            int v; cin >> v;
            adj[v].pb(i);
        }
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> ginw[i];
        if(ginw[i]){
            must[ginw[i]]=1;
            cntmust++;
        }
    }
    //solve(2, 1);
    int costr = cntmust*(-inf) + n;
    int l = cntmust, r = n, ans = 0;
    while(l<=r)
    {
        if(r-l<=1)
        {
            pii rethi = solve(r);
            if(rethi.S <= costr)
            {
                ans = r;
            }
            else ans = l;
            break;
        }
        int mid = (l+r)/2;
        pii ret = solve(mid);
        //if(n==200) cout << l << " " << r << " " << mid << " - " << ret.F << " " << ret.S << endl;
        if(ret.F==mid && ret.S <= costr)
        {
            l = mid;
        }
        else r = mid-1;
    }
    solve(ans, 1);
}