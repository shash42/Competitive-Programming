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

const int N = 33, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

//DINICS
struct Dinic { //Dinic dinics(totalNodes, source, sink) ; dinics.addEdge(u, v, w);
//RunTime: non-scaling= V^2E, Scaling=VElog(U) with higher constant, (E*root(V) bipartite graphs)
    struct flowEdge {
        int u, v; lint cap, flow = 0 ;
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
    {   n = nodes + 1; s = source ; t = sink ;
        edges.clear(); while(!q.empty()) q.pop();
        adj.resize(n); level.resize(n); ptr.resize(n); }

    void addEdge(int u, int v, lint cap, bool isDirected = true)
    {   edges.push_back({u, v, cap}); edges.push_back({v, u, 0});
        adj[u].push_back(m++); adj[v].push_back(m++);
        if(!isDirected) addEdge(v, u, cap, true); }

    bool bfs()
    {
        fill(level.begin(), level.end(), -1);
        while(!q.empty()) q.pop(); q.push(s); level[s] = 0 ;
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
    {   for(auto edge : edges) if(edge.flow > 0)
                cerr << edge.u << " " << edge.v << " " << edge.cap << " " << edge.flow << "\n" ; }

    void resetFlow()
    {   for(auto& edge : edges) edge.flow = 0 ; }

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
        return flow ; }
};
struct cont{
    char op;
    int x1, x2, y1, y2;
};
int m, n, h, v, s, ans, turns;
vector<string> outp;
char mat[N][N], grid[N][N];
int hidx[N][N], vidx[N][N];
bool vis[N][N];
void restgrid(){
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            grid[i][j] = '.';
            hidx[i][j] = vidx[i][j] = -1;
        }
    }
}
void dfs(int i, int j, char c)
{
    if(i<=0 || i>m || j<=0 || j>n || vis[i][j] || mat[i][j]!=c) return;
    vis[i][j] = true;
    grid[i][j] = c;
    dfs(i+1, j, c); dfs(i-1, j, c);
    dfs(i, j-1, c); dfs(i, j+1, c);
}
void solve(char c){

    map<pii, pii> hvtoc;
    vector<cont> H, V;
    vector<bool> HT, VT;
    //check horiz;
    for(int i = 1; i <= m; i++)
    {
        bool in=false;
        cont t;
        for(int j = 1; j <= n+1; j++){
            if(!in && grid[i][j]!='.'){
                in = true;
                t.x1 = i; t.y1 = j;
            }
            if(in && grid[i][j]=='.'){
                in = false;
                t.x2 = i, t.y2 = j-1;
                t.op = 'h';
                H.pb(t);
            }
            if(in){
                //cout << i << " - " << j << " " <<  H.size() << endl;
                hidx[i][j] = H.size();
            }
        }
    }
    //check vertical
    for(int j = 1; j <= n; j++)
    {
        bool in=false;
        cont t;
        for(int i = 1; i <= m+1; i++){
            if(!in && grid[i][j]!='.'){
                in = true;
                t.x1 = i; t.y1 = j;
            }
            if(in && grid[i][j]=='.'){
                in = false;
                t.x2 = i-1, t.y2 = j;
                t.op = 'v';
                V.pb(t);
            }
            if(in){
                vidx[i][j] = V.size();
            }
        }
    }

    HT.resize(H.size()); VT.resize(V.size());
    //setup flow
    int src = 0, bh = 1, bv = H.size() + bh, sink = bv + V.size();
    Dinic M(sink+1, src, sink);
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(grid[i][j]=='.') continue;
            //cout << i << " " << j << " " << hidx[i][j] << " " << vidx[i][j] << endl;
            hvtoc[{hidx[i][j], vidx[i][j]}] = {i, j};
            M.addEdge(bh + hidx[i][j], bv + vidx[i][j], s);
        }
    }
    for(int i = bh; i < bh + H.size(); i++){
        M.addEdge(src, i, h);
    }
    for(int i = bv; i < bv + V.size(); i++){
        M.addEdge(i, sink, v);
    }
    M.findMaxFlow();
   // M.printer();
   M.bfs();
   for(int i = bh; i < bv; i++){
       if(M.level[i]!=-1) continue;
       int idx = i - bh;
       HT[idx] = true;
       string tmp = "h " + to_string(H[idx].x1) + " " + to_string(H[idx].y1) + " ";
       tmp += to_string(H[idx].x2) + " " + to_string(H[idx].y2) + " " + c;
       outp.pb(tmp);
       ans+=h; turns++;
   }
   for(int i = bv; i < sink; i++){
       if(M.level[i]==-1) continue;
       int idx = i - bv;
       VT[idx] = true;
       string tmp = "v " + to_string(V[idx].x1) + " " + to_string(V[idx].y1) + " ";
       tmp += to_string(V[idx].x2) + " " + to_string(V[idx].y2) + " " + c;
       outp.pb(tmp);
       ans+=v; turns++;
   }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(grid[i][j]=='.') continue;
            if(!HT[hidx[i][j]] && !VT[vidx[i][j]]){
                string tmp = "s " + to_string(i) + " " + to_string(j) + " " + c;
                ans+=s; turns++;
                outp.pb(tmp);
            }
        }
    }
}
signed main()
{
    //freopen("painter.in", "r", stdin);
    //freopen("painter.out", "w", stdout);
    cin >> m >> n >> h >> v >> s;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> mat[i][j];
        }
    }
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(vis[i][j]) continue;
            restgrid();
            dfs(i, j, mat[i][j]);
            solve(mat[i][j]);
        }
    }
    cout << ans << " " << turns << endl;
    for(auto os: outp){
        cout << os << endl;
    }
}