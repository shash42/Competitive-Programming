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

bool vis[N];
int n, m, ans[N];
vi adj[N];
queue< int > q;
signed main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }
    ans[1]=-1;
    vis[1]=true;
    q.push(1);
    while(q.size())
    {
        int u = q.front();
        q.pop();
        for(auto v: adj[u])
        {
            if(vis[v]) continue;
            ans[v]=u;
            q.push(v);
            vis[v]=true;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(ans[i]==0)
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes\n";
    for(int i = 2; i <= n; i++)
    {
        cout << ans[i] << endl;
    }
}
