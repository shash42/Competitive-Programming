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

const int N = 3005, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

string s, t;
int dp[N][N], n, m, ans=0;
signed main()
{
    cin >> s >> t;
    n = s.length();
    m = t.length();
    for(int i = 0; i < n; i++)
    {
        dp[0][i] = 2;
        if(i<m && t[i]!=s[0]) dp[0][i] = 0;
    }
    if(m==1) ans = dp[0][0];
    for(int i = 1; i < n; i++) {
        for(int j = 0; j+i < n; j++)
        {
            int lst = j + i, addf=dp[i-1][j+1], addb=dp[i-1][j];
            if(lst < m && t[lst]!=s[i]) addb=0;
            if(j < m && t[j]!=s[i]) addf = 0;
            dp[i][j] = (addf + addb)%MOD2;
        //    cout << i << " " << j << " - " << dp[i][j] << endl;
        }
        if(i>=m-1) ans = (ans+dp[i][0])%MOD2;
    }
    cout << ans;
}