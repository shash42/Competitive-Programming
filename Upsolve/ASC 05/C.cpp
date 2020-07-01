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

const int N = 102, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

struct trans
{
    int st, ch, mv;
};
int n, m;
bool vis[N][N], vst[N];
trans adj[N][N];
int final[N];
void restvis()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            vis[i][j] = false;
        }
    }
}
signed main()
{
    //freopen("left.in", "r", stdin);
    //freopen("left.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> adj[i][j].st >> adj[i][j].ch >> adj[i][j].mv;
        }
    }
    for(int i = 1; i < n; i++)
    {
        restvis();
        int u = i, s = m;
        cerr << "starting at: " << i << endl;
        while(true)
        {
            if(u==n)
            {
                final[i] = n;
                break;
            }
            cerr <<u << " " << s << endl;
            vis[u][s] = true;
            if(adj[u][s].mv == -1)
            {
                final[i] = -1;
                break;
            }
            if(adj[u][s].mv == 1) {
                final[i] = adj[u][s].st;
                break;
            }
            int nxtu = adj[u][s].st, nxts = adj[u][s].ch;
            if(vis[nxtu][nxts])
            {
                final[i] = i;
                break;
            }
            else
            {
                u = nxtu; s = nxts;
            }
        }
    }
    final[n] = n;
    int u = 1;
    while(true)
    {
        cerr << u << " " << final[u] << endl;
        vst[u] = true;
        if(final[u]==-1)
        {
            cout << "NO";
            return 0;
        }
        if(vst[final[u]])
        {
            cout << "YES";
            return 0;
        }
        u = final[u];
    }
}