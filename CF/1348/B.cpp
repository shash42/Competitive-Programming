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

const int N = 2e5 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, k, a[N], cnt[N];
vi ans;
void solve()
{
    ans.clear();
    int dist = 0;
    for(int i = 0; i <= 100; i++) cnt[i]=0;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(!cnt[a[i]])
        {
            dist++;
            cnt[a[i]]=1;
        }
    }
    if(dist>k)
    {
        cout << -1 << endl;
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        if(dist==k) break;
        if(!cnt[i])
        {
            cnt[i]=1;
            dist++;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j <= n; j++) if(cnt[j]) ans.pb(j);
    }
    cout << ans.size() << endl;
    for(auto vv: ans)
    {
        cout << vv << " ";
    }
    cout << endl;
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