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

const int N = 2e2 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int l[N], r[N];
void solve()
{
    int n, m, x, mn=1e9+1, mx=-1e9+1;
    cin >> n >> x >> m;
    mn = x, mx = x;
    for(int i = 1; i <= m; i++)
    {
        cin >> l[i] >> r[i];
        if(l[i]<=mn && r[i]>=mn) mn = min(l[i], mn);
        if(l[i]<=mx && r[i]>=mx) mx = max(r[i], mx);
    }
    cout << mx - mn + 1 << endl;
}
signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}