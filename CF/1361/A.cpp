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

const int N = 5e5 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, m, p[N], ans[N];
pii t[N];
vi adj[N];
set<int> rem, tmp;
signed main()
{
    fastio;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }
    for(int i = 1; i <= n; i++)
    {
        rem.insert(i);
        cin >> t[i].F;
        t[i].S=i;
    }
    sort(t+1, t+n+1);
    for(int i = 1; i <= n; i++)
    {
        tmp.clear();
        int u = t[i].S;
        p[u] = i;
        ans[i] = u;
        for(auto v: adj[u])
        {
        //    cout << u << " - " << v << endl;
            if(p[v] == 0) continue;
            if(rem.find(t[p[v]].F)!=rem.end())
            {
                rem.erase(t[p[v]].F);
                tmp.insert(t[p[v]].F);
            }
        }
        int lol = *rem.begin();
        //cout << i << " " << lol << endl;
        if(lol!=t[i].F)
        {
            cout << -1;
            return 0;
        }
        for(auto v: tmp)
        {
            rem.insert(v);
        }
    }
    for(int i = 1; i<=n; i++)
    {
        cout << ans[i] << " ";
    }
}