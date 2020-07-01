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

const int N = 303, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, mov, m, dp[N][N][N], a[N], suff[N], pref[N], pdsum[N][N][N], psum[N][N][N];
string s;
signed main()
{
    cin >> s;
    cin >> mov;
    s = "0" + s;
    n = s.length();
    mov = min(mov, n);
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i]=='0'){
            cnt++;
        }
        else{
            m++;
            a[cnt]++;
        }
    }
    for(int i = 1; i <= cnt; i++)
    {
        pref[i] = pref[i-1] + a[i];
    }
    dp[0][0][0] = 1;
    for(int it = 0; it <= min(m, mov); it++){
        pdsum[0][it][it] = 1;
    }
    for(int it = 0; it <= m; it++){
        psum[0][it][0] = 1;
    }
    for(int i = 1; i <= cnt; i++){
        for(int j = pref[i]; j <= m; j++){
            for(int k = 0; k <= mov; k++){
                dp[i][j][k] = pdsum[i-1][j-a[i]][k];
                int it = min(j-a[i]+k, j);
                dp[i][j][k] = (dp[i][j][k] + psum[i-1][it][k] - psum[i-1][j-a[i]][k] + MOD2)%MOD2;
                psum[i][j][k] = pdsum[i][j][k] = dp[i][j][k];
                if(j>0 && k>0){
                    pdsum[i][j][k] = (pdsum[i][j][k] + pdsum[i][j-1][k-1])%MOD2;
                }
                if(j>0) {
                    psum[i][j][k] = (psum[i][j][k] + psum[i][j - 1][k]) % MOD2;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= mov; i++){
        ans = (ans + dp[cnt][m][i])%MOD2;
    }
    cout << ans;
}