#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define f first
#define s second
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
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N=1e5+5, MOD=1e9+7;
const lint INF=1e18;

int n, m, a[N];
void solve()
{
    cin >> n;
    int p = -INF, ans = -INF;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        ans = max(ans, p - a[i]);
        p = max(p, a[i]);
    }
    for(int i = 0; i < 35; i++)
    {
        if((1<<i) - 1 >= ans)
        {
            cout << i << endl;
            return;
        }
    }
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