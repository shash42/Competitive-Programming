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

const int N= 5003, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, a[N], dp[2][N][3];
signed main()
{
    cin >> n;
    int k = n/2 + (n%2!=0);
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j <= k; j++)
        {
            for(int it = 0; it < 3; it++)
                dp[i][j][it] = MOD1;
        }
    }
    dp[0][0][0] = 0;
    a[0] = -1;
    a[n+1] = -1;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        int p = (i-1)%2, c = i%2;
        dp[c][0][0] = 0;
        for(int j = 1; j <= k; j++)
        {
            dp[c][j][0] = min(dp[p][j][0], dp[p][j][2]);
            dp[c][j][1] = dp[p][j-1][0] + max(0LL, a[i-1]-a[i]+1) + max(0LL, a[i+1]-a[i]+1);
            if(i!=1) dp[c][j][1] = min(dp[c][j][1], dp[p][j-1][2] + max(0LL, min(a[i-2]-1, a[i-1])-a[i]+1) + max(0LL, a[i+1]-a[i]+1));
            dp[c][j][2] = dp[p][j][1];
        }
    }
    for(int i = 1; i <= k; i++)
    {
        int ans = min(dp[n%2][i][0], dp[n%2][i][1]);
        ans = min(ans, dp[n%2][i][2]);
        cout << ans << " ";
    }
}