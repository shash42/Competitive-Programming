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
using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, a[N], dp[N][62], mx=0;

signed main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i]+=30;
    }
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= 60; j++)
        {
            dp[i][j]=-MOD1;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = a[i]; j <= 60; j++)
        {
            dp[i][j] = dp[i-1][j] + a[i] - 30;
            mx = max(mx, dp[i][j]);
        }
        int mx2 = 0;
        for(int j = 0; j < a[i]; j++)
        {
            mx2 = max(mx2, dp[i-1][j] + j - 30);
        }
        dp[i][a[i]] = max(dp[i][a[i]], max(mx2, 0));
        mx = max(mx, dp[i][a[i]]);
     //   cout << i << " " << mx << endl;
    }
    cout << mx;
}