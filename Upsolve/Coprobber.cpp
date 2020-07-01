#include<bits/stdc++.h>
#define int long long
#define lint long long
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define SET(x, val) memset(x, val, sizeof(x))
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

typedef vector < int > vi ;
typedef pair < int, int > pii ;

const int N = 32 ;
const int MOD = 1e9 + 7 ;
const lint INF = 1e18 ;


struct Dinic { // Dinic dinics(totalNodes, source, sink) ; dinics.addEdge(u, v, w); // Adds a directed edge from u to v with cap w 
               // RunTime : non-scaling = V^2E, Scaling=VElog(U) with higher constant (E*root(V) for bipartite graphs)
    struct flowEdge {
        int u, v ;
        lint cap, flow = 0 ;
        flowEdge(int x, int y, lint capacity): u(x), v(y), cap(capacity) {}
    };

    bool SCALING = false; 
    vector < flowEdge > edges ;
    vector < vi > adj ; // Stores the ID of flowEdges
    vi level, ptr ; // Stores the pointer of the edge which can be used next
    queue < int > q ;
    int n, m = 0, s, t, lim = 1 ; 

    /* Convention used :
    Whenever we add a forward edge, flow is increased in that direction with cap unchanged.
    For each backward edge, cap is set to 0 and flow is taken in -ve which denotes
    the flow flowing in opposite ie. forward direction.
    */

    Dinic(int nodes, int source, int sink)
    {
        n = nodes + 1; s = source ; t = sink ;
        edges.clear(); while(!q.empty()) q.pop();
        adj.resize(n); level.resize(n); ptr.resize(n);
    }

    void addEdge(int u, int v, lint cap, bool isDirected = true)
    {
        edges.push_back({u, v, cap}); edges.push_back({v, u, 0});
        adj[u].push_back(m++); adj[v].push_back(m++);

        if(!isDirected) addEdge(v, u, cap, true);
    }

    bool bfs()
    {
        fill(level.begin(), level.end(), -1);
        while(!q.empty()) q.pop();
        q.push(s); level[s] = 0 ;
        while(!q.empty())
        {
            int u = q.front(); q.pop();
            for(int id : adj[u])
            {
                int v = edges[id].v; lint cap = edges[id].cap, flow = edges[id].flow ;
                if(level[v] != -1) continue ;  // Already seen node
                if( (cap - flow) < 1) continue ; // Can't take saturated/back edge
                if(SCALING and (cap - flow) < lim) continue ; // // Current flow push has to be >= currentLimit
                q.push(v); level[v] = level[u] + 1 ;
            }
        }
        return level[t] != -1 ; // Return whether t is reachable from s
    }

    lint dfs(int u, lint incFlow)
    {
        if(u == t) return incFlow ;
        lint curFlow, outFlow = 0 ;
        for(int& index = ptr[u]; index < sz(adj[u]); index++)
        {
            int id = adj[u][index] ;
            int& v = edges[id].v ; lint& cap = edges[id].cap ;

            if(level[v] != (level[u] + 1) ) continue ;
            if( (cap - edges[id].flow ) < 1) continue ;

            curFlow = dfs(v, min(incFlow, cap - edges[id].flow) );

            edges[id].flow += curFlow ;
            edges[id^1].flow -= curFlow ; // BackEdge of current edge (to undo/augment)

            outFlow += curFlow ;
            incFlow -= curFlow ;
            if(incFlow < 1) break ;
        }
        return outFlow ;
    }

    void printer()
    {
        for(auto edge : edges)
            if(edge.flow > 0)
                cout << edge.u << " " << edge.v << " " << edge.cap << " " << edge.flow << "\n" ;
    }

    void resetFlow()
    {
        for(auto& edge : edges) edge.flow = 0 ;
    }

    lint findMaxFlow()
    {
        lint flow = 0 ;
        for(lim = SCALING ? (1 << 30): 1; lim > 0; lim >>= 1) {
            while(bfs()) // Make layered graph of the network
            {
                fill(ptr.begin(), ptr.end(), 0);
                flow += dfs(s, INF); // Calculates the blocking flow of the network
            }
        }
        return flow ;
    }
};

char grid[N][N];
int costs[N], n, m, c;
signed main()
{
    cin >> m >> n >> c;
    int src;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> grid[i][j]; 
            if(grid[i][j]=='B') src = 2*((i-1)*m+j)+1;
        }
    }
    for(int i = 0; i < c; i++)
    {
        cin >> costs[i];
    }
    Dinic gg(2*((n+1)*(m+1))+5, src, 1);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            lint cc=INF;
            if(grid[i][j]!='.') cc =  costs[grid[i][j]-'a'];
            if(i==1 || j==1 || i==n || j==m)
            {
                gg.addEdge(2*((i-1)*m+j)+1, 1, INF);
            }
            if(2*((i-1)*m+j)+1==src) continue;
            gg.addEdge(2*((i-1)*m+j), 2*((i-1)*m+j)+1, cc);
            if(i!=1) gg.addEdge(2*((i-2)*m+j)+1, 2*((i-1)*m+j), INF);
            if(i!=n) gg.addEdge(2*(i*m+j)+1, 2*((i-1)*m+j), INF);
            if(j!=m) gg.addEdge(2*((i-1)*m+j+1)+1, 2*((i-1)*m+j), INF);
            if(j!=1) gg.addEdge(2*((i-1)*m+j-1)+1, 2*((i-1)*m+j), INF);
        }
    }
  //  cout << gg.edges.size();
    lint tot = gg.findMaxFlow();
  //  gg.printer();
    if(tot>=INF) cout << -1;
    else cout << tot;
}