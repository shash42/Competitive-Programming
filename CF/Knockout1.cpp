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

const int N = 1e3+5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int a[N], n;
vi th[N];
void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        for(int j = 0; j < a[i]; j++){
            int x;
            cin >> x;
            th[i].pb(x);
        }
        th[i].pb(MOD1);
        sort(all(th[i]));
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        int l = (i-1), r = (i+1);
        if(l==0) l = n;
        if(r==n+1) r=1;
        for(int j = 0; j < a[i]-1; j++){
            auto mx = lower_bound(th[l].begin(), th[l].end(), th[i][j+1]);
            auto mn = lower_bound(th[l].begin(), th[l].end(), th[i][j]);
            int lt = mx - mn;
         //   cout << i << " " << j << " - " << lt << endl;
            auto mx2 = lower_bound(th[r].begin(), th[r].end(), th[i][j+1]);
            auto mn2 = lower_bound(th[r].begin(), th[r].end(), th[i][j]);
            int rt = mx2 - mn2;
           // cout << i << " " << j << " - " << rt << endl;
            if(lt!=rt) cnt++;
        }
     //   cout << cnt << endl;
    }
    cout << cnt;
}
signed main(){
    fastio;
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}