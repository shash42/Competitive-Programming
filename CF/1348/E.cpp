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

const int N = 502, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, k, r[N], b[N], rk, bk, rs, bs, ans, dp[N][N];

signed main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> r[i] >> b[i];
        rs+=r[i];
        bs+=b[i];
    }
    rk = rs%k; bk = bs%k;
    ans = rs/k + bs/k;
    int poss = 1;
    if(rk+bk<k)
    {
        cout << ans;
        return 0;
    }
    int want1 = rk, want2 = k-bk;
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        int rc = r[i]%k;
        if(r[i]>=k) rc=k;
        for(int j = 0; j < k; j++)
        {
            dp[i][j] = dp[i-1][j];
            for(int it = 1; it <= rc; it++)
            {
                if(b[i]<k-it) continue;
                int trg = (j - it + k)%k;
                dp[i][j] |= dp[i-1][trg];
            }
        }
    }
    if(dp[n][want1] || dp[n][want2])
    {
        ans+=poss;
    }
    cout << ans;
}