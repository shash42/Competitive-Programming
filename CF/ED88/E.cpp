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
using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 5e5 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

inline int modpow(lint base, int exp, int modulo) {
    base %= modulo;
    lint result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % modulo;
        base = (base * base) % modulo;
        exp >>= 1;
    }
    return result;
}

int n, k, dp[N];

signed main()
{
    cin >> n >> k;
    int km1 = k-1;
    dp[km1] = 1;
    for(int i = km1+1; i <= n; i++)
    {
        dp[i]=dp[i-1];
        dp[i]=(dp[i]*i)%MOD2;
        dp[i]=(dp[i]*(modpow(i-km1, MOD2-2, MOD2)))%MOD2;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        int j = n/i - 1;
        ans += dp[j];
        ans%=MOD2;
    }
    cout << ans;
}