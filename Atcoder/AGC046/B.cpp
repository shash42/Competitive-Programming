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

const int N = 3e3 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int a, b, c, d, dp[N][N];
signed main()
{
    cin >> a >> b >> c >> d;
    dp[a][b] = 1;
    for(int i = a; i <= c; i++)
    {
        for(int j = b; j <= d; j++)
        {
            if(i==a && j==b) continue;
            dp[i][j] = (dp[i-1][j]*j + dp[i][j-1]*i)%MOD2;
            dp[i][j] = (dp[i][j] - (dp[i-1][j-1]*(i-1)*(j-1))%MOD2 + MOD2)%MOD2;
        }
    }
    cout << dp[c][d];
}