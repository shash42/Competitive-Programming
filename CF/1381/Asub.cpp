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
using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n;
string a, b;
void solve(){
    vi ans;
    cin >> n >> a >> b;
    int rev = 0;
    int l = 0, r = n-1, k = n-1;
    while(r-l>=1){
        if(a[l]==b[k]){
            ans.pb(1);
        }
        ans.pb(k+1); k--;
        if(a[r]!=b[k]){
            ans.pb(1);
        }
        ans.pb(k+1); k--;
        l++; r--;
    }
    if(r==l){
        if(a[l]==b[k]){
            ans.pb(1);
        }
        ans.pb(k+1); k--;
    }
    /*for(int k = n-1; k >= 0; k--){
        int idx0 = 0, idxk = k;
        if(rev) swap(idx0, idxk);
        if(!rev && a[idx0]==b[k]){
            ans.pb(1);
        }
        else if(rev && a[idx0]!=b[k]){
            ans.pb(1);
        }
        ans.pb(k+1);
        rev = 1 - rev;
    }*/
    cout << ans.size() << " ";
    for(auto u: ans){
        cout << u << " ";
    }
    cout << endl;
}
signed main(){
    fastio;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}