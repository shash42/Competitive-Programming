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
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e3 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int a, n, m, dp[N][N], rain[N];
pii umbs[N];
vi umbat[N];
signed main(){
    fastio;
    cin >> a >> n >> m;
    for(int i = 0; i <= a; i++){
        for(int j = 0; j <= m; j++){
            dp[i][j] = MOD1;
        }
    }
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        for(int j = l+1; j <= r; j++){
            rain[j] = 1;
        }
    }
    for(int i = 1; i <= m; i++) {
        cin >> umbs[i].F >> umbs[i].S;
        umbat[umbs[i].F].pb(i);
    }
    dp[0][0] = 0;
    for(int i = 1; i <= a; i++){
        int mnback = MOD1, mnidx=0;
        for(int j = 0; j <= m; j++){
            if( dp[i-1][j] < mnback) {
                mnidx = j;
                mnback = dp[i-1][j];
            }
        }
        if(!rain[i]){
            dp[i][0] = min(mnback, dp[i][0]);
        }
        for(int j = 1; j <= m; j++){
            dp[i][j] = dp[i-1][j] + umbs[j].S;
        }
        for(auto u: umbat[i-1]){
            dp[i][u] = mnback + umbs[u].S;
        }
    }
    int mn = MOD1;
    for(int i = 0; i <= m; i++){
        mn = min(mn, dp[a][i]);
    }
    if(mn>1e9){
        cout << -1;
    }
    else{
        cout << mn;
    }
}