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

const int N = 102, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int spf[N];
vector<int> primes;

void spfsieve() {
    for (int i = 2; i < N; i++)
        spf[i] = -1;
    for (int i = 2; i < N; i++) {
        if (spf[i] != -1) continue;
        primes.pb(i);
        for (int j = i; j < N; j += i) if (spf[j] == -1) spf[j] = i;
    }
}

vi adj[N];
int n, a[N], d[N];
void rest(){
    for(int i = 1; i <= n; i++){
        adj[i].clear();
        a[i]=1;
    }
}
void dfs(int u, int p){
    for(auto v: adj[u]){
        if(v==p) continue;
        d[v] = d[u]+1;
        dfs(v, u);
    }
}
void solve(){
    cin >> n;
    rest();
    /*for(int i = 1; i < n; i++){
        adj[i].pb(i+1);
        adj[i+1].pb(i);
    }*/
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }
    int st = 1;
    d[st] = 1;
    dfs(st, st);
    for(int i = 2; i <= n; i++){
        int req = i/2 + 1;
        for(int j = 1; j <= n; j++){
            if(d[j]%req==req/2){
                a[j]*=i;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(a[i]>2e18) exit(7);
        cout << a[i] << " ";
        //if(a[i]<0) cout << i << " - "<< a[i] << endl;
    }
    cout << endl;
}
signed main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}