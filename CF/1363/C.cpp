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
using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e3+5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, x;
vi adj[N];

int dfs(int u, int p) {
    int xr = 1;
    if(u==x) xr = 0;
    for(auto v: adj[u])
    {
        if(v==p) continue;
        xr ^= dfs(v, u);
    }
    return xr;
}
void solve()
{
    cin >> n >> x;
    for(int i = 1; i <= n; i++)
    {
        adj[i].clear();
    }
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int ans = dfs(x, 0);
    if(adj[x].size()<=1)
    {
        cout << "Ayush" << endl;
        return;
    }
    if(ans==1)
    {
        cout << "Ayush" << endl;
        return;
    }
    cout << "Ashish" << endl;
}
signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}