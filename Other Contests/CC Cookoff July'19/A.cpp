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

const int N = 5e5 + 5, B = 31, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, q, a[N], pgiv[N][B], pmsb[N][B], pzer[N];
void solve(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        for(int j = B-1; j >= 0; j--){
            pgiv[i][j] = pgiv[i-1][j]; pmsb[i][j] = pmsb[i-1][j];
        }
        pzer[i] = pzer[i-1];
        cin >> a[i];
        if(a[i]==0){
            pzer[i]++;
            continue;
        }
        bool msb=true;
        for(int j = B-1; j >= 0; j--){
            if((a[i]&(1<<j)) != 0){
                if(msb){
                    pmsb[i][j]++;
                    msb=false;
                }
                else{
                    pgiv[i][j]++;
                }
            }
        }
    }
    for(int i = 1; i <= q; i++){
        int l, r, tot;
        lint ans = 0;
        cin >> l >> r;
        tot = r-l+1;
        int z = pzer[r] - pzer[l-1];
        ans += ((lint) z)*(tot);
        for(int j = B-1; j >= 0; j--){
            int giv = pgiv[r][j] - pgiv[l-1][j];
            int msb = pmsb[r][j] - pmsb[l-1][j];
            ans += ((lint)msb)*giv;
        }
        cout << ans << endl;
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