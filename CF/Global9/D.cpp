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

const int N = 2e5 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, a[N], p[N];
vi ans;
bool sorted(){
    for(int i = 0; i < n-1; i++){
        if(a[i]>a[i+1]) return false;
    }
    return true;
}
int findmex(){
    multiset<int> s;
    for(int i = 0; i <= n; i++) s.insert(i);
    for(int i = 0; i < n; i++) s.erase(a[i]);
    return *s.begin();
}
void findp(){
    for(int i = 0; i < n; i++) p[i]=-1;
    for(int i = 0; i < n; i++){
        p[a[i]]=i;
    }
}
void solve(){
    ans.clear();
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    while(!sorted()){

        int x = findmex();
        if(x==n) break;
        a[x]=x;
        ans.pb(x);
        //if(n==9) cout << min(n-1, x) << endl;
    }
    while(!sorted()){
        for(int i = 0; i < n; i++){
            if(a[i]!=i){
                findp();
                if(p[i]==-1){
                    a[i]=findmex();
                    ans.pb(i);
                    break;
                }
                a[p[i]] = findmex();
                ans.pb(p[i]);
                //cout << p[i] << endl;
                a[i] = findmex();
                //if(a[i]!=i) return;
                ans.pb(i);
                //cout << i << endl;
                break;
            }
        }
    }
    if(ans.size()>2*n) exit(7);
    cout << ans.size() << endl;
    for(auto u: ans) cout << u+1 << " ";
    cout << endl;
}
signed main(){
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}