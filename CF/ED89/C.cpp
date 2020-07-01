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

const int N = 35, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, m, mat[N][N], cnt[2*N][2];
void solve()
{
    cin >> n >> m;
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            int it = i+j;
            if(it > n+m-2 - it)
            {
                it = n+m-2 - it;
            }
            cnt[it][0] += mat[i][j]==0;
            cnt[it][1] += mat[i][j]==1;
        }
    }
    int tot = n+m-2, ans = 0;
    for(int i = 0; i < n+m-1; i++)
    {
        if(tot%2==0 && i == (tot)/2) continue;
        ans += min(cnt[i][0], cnt[i][1]);
        //cout << i << ans << endl;
    }
    cout << ans << endl;
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