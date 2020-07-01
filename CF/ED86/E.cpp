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

const int N = 2e5 + 5, MOD = 998244353;
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
int n, k, fac[N], ifac[N], mult=1;

int ncr(int n, int r)
{
    int ret = (fac[n]*ifac[r])%MOD;
    ret = (ret*ifac[n-r])%MOD;
    return ret;
}
signed main()
{
    ifac[0] = fac[0]=1;
    for(int i = 1; i < N; i++)
    {
        fac[i] = (fac[i-1]*i)%MOD;
        ifac[i] = modpow(fac[i], MOD-2, MOD);
    }
    cin >> n >> k;
    if(k==0)
    {
        cout << fac[n];
        return 0;
    }
    if(k>=n)
    {
        cout << 0;
        return 0;
    }
    int g = n-k;
    int ans = (2 * ncr(n, g))%MOD;
    int num = 0;
    for(int i = 0; i < g; i++)
    {
        int cur = ncr(g, i) * modpow(g-i, n, MOD);
        cur%=MOD;
        if(mult==-1)
        {
            cur = MOD-cur;
        }
        mult*=-1;
        num += cur;
        num%=MOD;
    }
    ans = (ans*num)%MOD;
    cout << ans;
}