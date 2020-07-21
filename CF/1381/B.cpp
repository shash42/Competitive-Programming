#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define pb push_back
#define F first
#define S second
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

const int N = 2e3+5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, dp[N][2*N], a[2*N], idx[2*N];
bool vis[2*N];
void solve(){
    cin >> n;
    for(int i = 1; i <= 2*n; i++){
        cin >> a[i];
        vis[i] = false;
        idx[a[i]] = i;
    }
    vi cnts;
    cnts.pb(0);
    vis[2*n+1] = true;
    for(int i = 2*n; i >= 1; i--){
        if(vis[idx[i]]) continue;
        int st = idx[i];
        for(int j = st; j <= 2*n+1; j++){
            if(vis[j]){
                cnts.pb(j - st);
                break;
            }
            vis[j] = true;
        }
    }
    int m = cnts.size() - 1;
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= 2*n; j++){
            dp[i][j] = 0;
        }
    }
   /* for(auto u: cnts) cout << u << " ";
    cout << endl;*/
    dp[0][0] = 1;
    for(int i = 1; i <= m; i++){
        for(int j = 0; j <= 2*n; j++) dp[i][j] = dp[i-1][j];
        for(int j = cnts[i]; j <= 2*n; j++){
            dp[i][j] = max(dp[i][j], dp[i-1][j - cnts[i]]);
      //      cout << i << " " << j << " - " << dp[i][j] << endl;
        }
    }
    if(dp[m][n]){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}
signed main(){
    fastio;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}