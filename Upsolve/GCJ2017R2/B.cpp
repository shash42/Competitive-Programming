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

const int N = 1e3 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, c, m, degc[N], degs[N], ans=0, shf=0, pref[N], mxdegc, mxdegs;
void solve()
{
    mxdegc=0; mxdegs=0; shf=0;
    cin >> n >> c >> m;
    for(int i = 1; i <= n; i++)
    {
        degs[i]=0;
    }
    for(int i = 1; i <= c; i++)
    {
        degc[i]=0;
    }
    for(int i = 1; i <= m; i++)
    {
        int p, b;
        cin >> p >> b;
        degs[p]++;
        degc[b]++;
    }
    for(int i = 1; i <= c; i++)
    {
        mxdegc=max(mxdegc, degc[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        pref[i]=pref[i-1]+degs[i];
        mxdegs = max(mxdegs, pref[i]/i + ((pref[i]%i)!=0LL));
    }
    ans = max(mxdegs, mxdegc);
    for(int i = 1; i <= n; i++)
    {
        if(degs[i] > ans) shf+=degs[i]-ans;
    }
    cout << ans << " " << shf;
}
signed main()
{
    int T;
    cin >> T;
    int t = T;
    while(t--)
    {
        cout << "Case #" << t << ": ";
        solve();
        cout << endl;
    }
}