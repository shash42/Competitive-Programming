#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define pb push_back
#define F first
#define S second
#define int long long
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

const int N = 5e5 + 5, K = 62, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, m, k, ans = 1, pw2[N], a[N], nodes;
set<int> xors;
struct graph{
    map<int, vi> adj;
    map<int, bool> vis;
};
map<int, graph> xorlst;
map<int, vi> xornds;
void dfs(int u, int x)
{
    nodes++;
    xorlst[x].vis[u] = true;
    for(auto v: xorlst[x].adj[u])
    {
        if(!xorlst[x].vis[v])
        {
            dfs(v, x);
        }
    }
}
vector<int> emp;
signed main()
{
    fastio;
    pw2[0] = 1;
    for(int i = 1; i < N; i++)
    {
        pw2[i] = ( pw2[i-1] * 2 ) % MOD1;
    }
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 0; i < m; i++)
    {
        int u, v, x;
        cin >> u >> v;
        x = a[u]^a[v];
        xors.insert(x);
        xornds[x].pb(u); xornds[x].pb(v);
        xorlst[x].adj[u].pb(v);
        xorlst[x].adj[v].pb(u);
    }
    int okx = (pw2[k] - (int) xors.size() + MOD1)%MOD1;
    ans = (okx*pw2[n])%MOD1;
    for(auto x: xors)
    {
        nodes = 0;
        int comps = 0;
        for(auto u: xornds[x])
        {
            if(!xorlst[x].vis[u])
            {
                comps++;
                dfs(u, x);
            }
        }
        ans += (pw2[n - nodes + comps])%MOD1;
        ans %= MOD1;
    }
    cout << ans;
}