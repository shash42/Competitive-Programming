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
#define FF fflush(stdout);
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int a[4];
bool AP(){
    vi b;
    for(int i = 1; i <= 3; i++) b.pb(a[i]);
    sort(all(b));
    if(b[2]-b[1] == b[1]-b[0]) return true;
    return false;
}
void solve(){
    int K = 1000;
    cin >> a[1] >> a[2] >> a[3];
    cout << "Second\n";   FF;
    int prev = 0;
    for(int i = 0; i < K; i++){
        int x;
        cin >> x;
        if(x==0) return;
        for(int i = 1; i <= 3; i++){
            if(i==prev) continue;
            int tmp = a[i];
            a[i] += x;
            if(AP()){
               a[i] = tmp;
            }
            else{
                prev=i;
                cout << i << endl;
                FF;
                break;
            }
        }
    }
    int x;
    cin >> x;
    return;
}
signed main(){
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}