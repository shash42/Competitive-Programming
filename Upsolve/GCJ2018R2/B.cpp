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

const int N = 502, B = 37, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int dp[2][N][N], r, b, nn;
void solve()
{
    vector< pii > v;
    r=500; b=500;
    for(int i = 0; i <= min(r, B-1); i++)
    {
        for(int j = 0; j <= min(b, B-1); j++)
        {
            v.pb({i, j});
        }
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            dp[0][i][j] = dp[1][i][j] = -INF;
        }
    }
    dp[0][0][0]=0;
    for(int it = 1; it < v.size(); it++)
    {
        int c = it%2;
        int p = 1-c;
        for(int i = 0; i <= r; i++)
        {
            for(int j = 0; j <= b; j++)
            {
                dp[c][i][j] = dp[p][i][j];
                if(i<v[it].F || j < v[it].S) continue;
                dp[c][i][j] = max(dp[c][i][j], 1+dp[p][i-v[it].F][j-v[it].S]);
            }
        }
    }
    nn = 1 - (v.size()%2);
}

signed main()
{
    solve();
    int T;
    cin >> T;
    int t = T;
    while(t--)
    {
        cout << "Case #" << T-t << ": ";
        int x, y;
        cin >> x >> y;
        cout << dp[nn][x][y];
        cout << endl;
    };
}