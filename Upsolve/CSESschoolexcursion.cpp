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

const int N = 1e5 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

vi adj[N];
set<int> s;
int n, ejs, c, sz[N], dp[2][N], vis[N], cnt[N];
void dfs(int u)
{
    vis[u]=1;
    sz[c]++;
    for(auto v: adj[u])
    {
        if(!vis[v]) dfs(v);
    }
}
signed main()
{
    cin >> n >> ejs;
    for(int i = 0; i < ejs; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i = 1; i <= n; i++)
    {
        if(vis[i]) continue;
        c++;
        dfs(i);
    }
    for(int i = 1; i <= c; i++)
    {
        cnt[sz[i]]++;
        s.insert(sz[i]);
    }
    dp[0][0]=1;
    int cr = 1, pr=0;
    for(auto i: s)
    {
        for(int j = 0; j <= n; j++)
        {
            if(dp[pr][j])
            {
                dp[cr][j] = 1;
                for(int k = j+i; k <= min(n, j + cnt[i]*i); k+=i)
                {
                    if(dp[pr][k]) break;
                    dp[cr][k] = 1;
                }
            }
        }
        swap(cr, pr);
    }
    for(int i = 1; i <= n; i++)
    {
        cout << dp[pr][i];
    }
}