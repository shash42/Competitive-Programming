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

const int B = 9, N = (1<<18)+5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;
const int SS = (1<<9)+2;
int n, q, dp[SS][N], v[N], w[N];
signed main()
{
    fastio;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i];
    }
    for(int i = 1; i < SS; i++)
    {
        for(int j = 1; j < N; j++)
        {
            dp[i][j] = dp[i/2][j];
            if(w[i] <= j) dp[i][j] = max(dp[i][j], dp[i/2][j-w[i]] + v[i]);
        }
    }
    cin >> q;
    for(int it = 1; it <= q; it++)
    {
        int u, l;
        cin >> u >> l;
        vector<pii> obj;
        while(u>=SS)
        {
            obj.pb({v[u], w[u]});
            u/=2;
        }
        int sz = obj.size(), mx = 0;
        for(int i = 0; i < (1<<sz); i++)
        {
            int vt = 0, wt = 0;
            for(int j = 0; j < sz; j++)
            {
                if(((1<<j)&i) != 0)
                {
                    vt += obj[j].F; wt+=obj[j].S;
                }
            }
            if(wt <= l)
            {
                mx = max(mx, vt + dp[u][l-wt]);
            }
        }
        cout << mx << endl;
    }
}