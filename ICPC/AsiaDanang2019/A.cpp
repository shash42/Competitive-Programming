#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define f first
#define s second
#define lint long long
#define mp make_pair
#define pii pair<int, int>
#define pll pair<lint, lint>
#define ld long double
#define inlld(x) scanf("%lld", &x)
#define ind(x) scanf("%d", &x)
#define vi vector<int>
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define SET(x, val) memset(x, val, sizeof(x))
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define reMin(a, b) a = min(a, b)
#define reMax(a, b) a = max(a, b)
const int N=103, MOD=1e9+7;
const lint INF=1e18;
lint _add(lint x, lint y) {
    lint ret=x+y;
    while(ret<0LL) ret+=MOD;
    return ret;
}
lint _mult(lint x, lint y) {
    x%=MOD; y%=MOD;
    lint ret=x*y;
    ret%=MOD;
    while(ret<0LL) ret+=MOD;
    return ret;
}
inline int modpow(lint base, int exp, int modulo) {
  base %= modulo;  lint result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulo;
    base = (base * base) % modulo; exp >>= 1;
  }
  return result;
}
using namespace std;
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct Dinic
{
  struct flowEdge
  {
    int u, v; lint cap, flow=0;
    flowEdge(int x, int y, lint capacity): u(x), v(y), cap(capacity) {}
  };
  bool SCALING = false;
  vector < flowEdge > edges;
  vector < vi > adj;
  vi level, ptr;
  queue<int> q;
  int n, m=0, s, t, lim=1;

  Dinic(int nodes, int source, int sink)
  {
    n = nodes+1; s = source; t = sink;
    edges.clear(); while(!q.empty()) q.pop();
    adj.resize(n); level.resize(n); ptr.resize(n);
  }

  void addEdge(int u, int v, lint cap, bool isDirected=true)
  {
    edges.push_back({u, v, cap});
    edges.pb({v, u, 0});
    adj[u].pb(m++); adj[v].pb(m++);
    if(!isDirected) addEdge(v, u, cap, true);
  }

  bool bfs()
  {
    fill(level.begin(), level.end(), -1);
    while(!q.empty()) q.pop();
    q.push(s);
    level[s]=0;
    while(!q.empty())
    {
      int u = q.front(); q.pop();
      for(int id: adj[u])
      {
        int v = edges[id].v;
        lint cap = edges[id].cap, flow=edges[id].flow;
        if(level[v] != -1) continue;
        if( (cap-flow) < 1) continue;
        if(SCALING and (cap - flow) < lim) continue;
        q.push(v); level[v]=level[u]+1;
      }
    }
    return level[t] != -1;
  }
  lint dfs(int u, lint incFlow)
  {
    if(u==t) return incFlow;
    lint curFlow, outFlow=0;
    for(int &index = ptr[u]; index < sz(adj[u]); index++)
    {
      int id = adj[u][index];
      int &v = edges[id].v; lint &cap = edges[id].cap;
      if(level[v]!=(level[u]+1)) continue;
      if( (cap - edges[id].flow) < 1) continue;
      curFlow = dfs(v, min(incFlow, cap - edges[id].flow));
      edges[id].flow += curFlow;
      edges[id^1].flow -= curFlow;
      outFlow += curFlow;
      incFlow -= curFlow;
      if(incFlow < 1) break;
    }
    return outFlow;
  }
  void printer()
  {
    for(auto edge: edges)
    {
      if(edge.flow>0)
      {
        cerr << edge.u << " " << edge.v << " " << edge.cap << " " << edge.flow << endl;
      }
    }
  }
  void resetFlow()
  {
    for(auto &edge: edges) edge.flow=0;
  }
  lint findMaxFlow()
  {
    lint flow=0;
    for(lim = SCALING ? (1<<30): 1; lim > 0; lim >>=1)
    {
      while(bfs())
      {
        fill(ptr.begin(), ptr.end(), 0);
        flow += dfs(s, INF);
      }
    }
    return flow;
  }
};
int k, n, mat[N][N];
bool used[N];
signed main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
      for(int j = 1; j <= n; j++)
      {
        cin >> mat[i][j];
        used[mat[i][j]]=true;
      }
    }
    for(int i = 1; i <= n; i++)
    {
      if(!used[i])
      {
        used[i]=true;
        Dinic D(2*n+5, 0, 2*n+2);
        for(int x = 1; x <= n; x++)
        {
          for(int y = 1; y <= n; y++)
          {
            if(mat[x][y]==0)
            {
              D.addEdge(x, n+y, 1);
            }
          }
          D.addEdge(0, x, 1);
          D.addEdge(x+n, 2*n+2, 1);
        }
        int fl = D.findMaxFlow();
        //cerr << endl;
        //D.printer();
        //cout << i << " " << fl << endl;
        /*if(fl!=n)
        {
          cout << "NO";
          return 0;
        }*/
        for(auto edge: D.edges)
        {
          if(edge.u != 0 && edge.v != 2*n+2 && edge.flow==1)
          {
            mat[edge.u][edge.v-n]=i;
          }
        }
      }
    }
    cout << "YES\n";
    for(int i = 1; i <= n; i++)
    {
      for(int j = 1; j <= n; j++)
      {
        cout << mat[i][j] << " ";
      }
      cout << endl;
    }
}