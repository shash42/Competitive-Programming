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

const int N = 1e3 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18+5;

int n, m, t, mat[N][N], vis[N][N], dist[N][N], curd;
string inp[N];
queue< pii > q;
void dofor(int i, int j)
{
    if(i <= 0 || i>n || j <= 0 || j > m || vis[i][j]==1) return;
    dist[i][j]=curd+1;
    vis[i][j]=1;
    q.push({i, j});
}
void bfs(int s)
{
    while(q.size()) q.pop();
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            vis[i][j]=0;
            if(mat[i][j]==s) {
                q.push({i, j});
                vis[i][j]=1;
            }
        }
    }
    while(q.size())
    {
        pii u = q.front();
        int i = u.F, j = u.S;
        q.pop();
        if(mat[i][j]==s) curd=-1;
        else curd=dist[i][j];
        dofor(i-1, j);
        dofor(i, j-1);
        dofor(i+1, j);
        dofor(i, j+1);
    }
}
signed main()
{
    cin >> n >> m >> t;
    for(int i = 1; i <= n; i++)
    {
        cin >> inp[i];
        for(int j = 1; j <= m; j++)
        {
            mat[i][j] = inp[i][j-1]-'0';
            mat[i][j]^=(i+j)%2;
            dist[i][j]=-1;
        }
    }
    bfs(0);
    bfs(1);
    for(int i = 1; i <= t; i++)
    {
        int u, v;
        lint tt;
        cin >> u >> v >> tt;
        int ans = mat[u][v] ^ ((u+v)%2);
        if(dist[u][v]==-1 || tt <= dist[u][v])
        {
            cout << ans << endl;
        }
        else
        {
            ans ^= ((tt-dist[u][v])%2);
            cout << ans << endl;
        }
    }
}