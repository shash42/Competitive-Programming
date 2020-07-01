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
using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, k, vis[N], d[N], subt[N], tot[N];
vi adj[N];

void dfs(int u) {
    vis[u] = 1;
    subt[u]=1;
    for (auto v: adj[u]) {
        if (!vis[v]) {
            d[v] = d[u]+1;
            dfs(v);
            subt[u] += subt[v];
        }
    }
    tot[u] = d[u] - subt[u] + 1;
}
signed main()
{
    cin >> n >> k;
    for(int i = 0; i < n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);
    sort(tot+1, tot+n+1, greater<int>());
    int ans = 0;
    for(int i = 1; i <= k; i++)
    {
        ans += tot[i];
    }
    cout << ans << endl;
}