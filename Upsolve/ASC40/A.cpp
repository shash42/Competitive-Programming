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

const int N = 2e5 + 100, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, m, ans[N];
vi posts[N];
map<pii, int> ejt;
int feed(int p, int st, int en){
    int ret = lower_bound(all(posts[p]), en) - posts[p].begin();
    ret -= lower_bound(all(posts[p]), st) - posts[p].begin();
    return ret;
}
signed main(){
    freopen("intouch.in", "r", stdin);
    freopen("intouch.out", "w", stdout);
    fastio;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        char c;
        cin >> c;
        int x, y;
        if(c=='!'){
            cin >> x;
            posts[x].pb(i);
            continue;
        }
        else{
            cin >> x >> y;
        }
        if(c=='+'){
            ejt[{x, y}]=i;
            continue;
        }
        if(ejt.find({x, y})==ejt.end()){
            swap(x, y);
        }
        if(ejt.find({x, y})==ejt.end()) exit(7);
        int st = ejt[{x, y}];
        ejt.erase({x, y});
        int en = i;
        ans[x] += feed(y, st, en);
        ans[y] += feed(x, st, en);
    }

    for(int i = 1; i <= n; i++){
        posts[i].pb(m+2);
    }
    for(auto e: ejt){
        int x = e.F.F, y = e.F.S;
        ans[x] += feed(y, e.S, m+1);
        ans[y] += feed(x, e.S, m+1);
    }

    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
}