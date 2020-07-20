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

const int N = 2e5 + 5, B=64, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, a[N];
set<int> orz;
void solve(){
    orz.clear();
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(n>B) {
        cout << "NO\n";
        return;
    }
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int cor=0;
            for(int k = i; k <= j; k++){
                cor |= a[k];
            }
            if(orz.find(cor)!=orz.end()){
                cout << "NO\n";
                return;
            }
            orz.insert(cor);
        }
    }
    cout << "YES\n";
}
signed main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}