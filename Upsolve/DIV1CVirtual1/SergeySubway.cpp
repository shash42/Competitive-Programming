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

const int N = 2e5 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

vi adj[N];
int n, vis[N], indp[N][2], outdp[N][2], incnt[N][2], outcnt[N][2];
void dfs(int u, int p) {
    incnt[u][0]=1;
    for (auto v: adj[u]) {
        if (v!=p) {
            dfs(v, u);
            incnt[u][1] += incnt[v][0];
            incnt[u][0] += incnt[v][1];
            indp[u][0] += indp[v][1];
            indp[u][1] += indp[v][0]+incnt[v][0];
        }
    }
}
void dfs2(int u, int p)
{
    for(auto v: adj[u]) {
        if(v!=p) {
            outcnt[v][0] = outcnt[u][1] + incnt[u][1] - incnt[v][0];
            outcnt[v][1] = outcnt[u][0] + incnt[u][0] - incnt[v][1];
            outdp[v][0] = outdp[u][1] + (indp[u][1] - (indp[v][0] + incnt[v][0]) );
            outdp[v][1] = (outdp[u][0] + outcnt[u][0]) + ( (indp[u][0] + incnt[u][0] - incnt[v][1]) - (indp[v][1]) );
            dfs2(v, u);
        }
    }
}
signed main()
{
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 0);
    dfs2(1, 0);
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans += indp[i][0] + outdp[i][0] + indp[i][1] + outdp[i][1];
    }
    cout << ans/2;
}