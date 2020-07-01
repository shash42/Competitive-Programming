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

const int N = 502, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, dist[N][N], p[N*N], vis[N][N], gone[N][N];
vector< pii > v;
void rec(int i, int j, int d, bool st=0)
{
    if(i<0 || i>=n || j<0 || j>=n) return;
    if(vis[i][j]) return;
    if(!st && d>=dist[i][j]) return;
    vis[i][j]=1;
    v.pb({i, j});
    dist[i][j]=d;
    int add = 1 - gone[i][j];
    int dn = d + add;
    rec(i-1, j, dn);
    rec(i+1, j, dn);
    rec(i, j-1, dn);
    rec(i, j+1, dn);
}
void solve(int i, int j, int d)
{
    rec(i, j, d, 1);
    for(auto u: v)
    {
        vis[u.F][u.S]=0;
    }
    v.clear();
}
pii getij(int x)
{
    return {x/n, x%n};
}
signed main()
{
    int ans = 0;
    cin >> n;
    for(int i = 0; i < n*n; i++)
    {
        cin >> p[i];
        p[i]-=1;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            dist[i][j] = min(i, j);
            dist[i][j] = min(dist[i][j], min(n-i-1, n-j-1));
        }
    }
    for(int it = 0; it < n*n; it++)
    {
        pii ij = getij(p[it]);
        int i = ij.F, j = ij.S;
        ans += dist[i][j];
        gone[i][j]=1;
        solve(i, j, dist[i][j]);
    }
    cout << ans;
}