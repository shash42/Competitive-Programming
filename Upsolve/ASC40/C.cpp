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

const int N = 11, SS = 52, M = 104, MOD1 = 1e9 + 7, MOD2 = 998244353;
const double INF = 1e10;

int n, s, v[N], m[N], pref[N][M], ansa[N], lasta[N][SS][M], V;
vi leev[N];
double dp[N][SS][M];

void init(){
    memset(lasta, -1, sizeof(lasta));
}
double recurse(int i, int j, int k, int A){
    if(i==0 && j==0 && k==0) return 0;
    else if(i==0) return INF;
    if(j<0 || k<0) return INF;
    if(lasta[i][j][k]!=-1) return dp[i][j][k];

    double mn = INF;
    for(int agiv = 0; agiv <= k; agiv++){
        double ret = recurse(i-1, j - pref[i][agiv], k - agiv, A);
       // if(ret>n) continue;
        ret += abs((double)agiv/A - (double)v[i]/V);
        if(ret < mn){
            mn = ret;
            lasta[i][j][k] = agiv;
        }
    }
    if(lasta[i][j][k]==-1) lasta[i][j][k]=-2;
    dp[i][j][k] = mn;
    return dp[i][j][k];
}
signed main(){
    freopen("elections.in", "r", stdin);
    freopen("elections.out", "w", stdout);
    cin >> n >> s;
    for(int i = 1; i <= n; i++){
        cin >> v[i] >> m[i];
        V += v[i];
        for(int j = 0; j < M; j++){
            pref[i][j] = j;
        }
        int prv = 0;
        for(int j = 0; j < m[i]; j++){
            int x; cin >> x;
            leev[i].pb(x);
            for(int k = prv; k < x; k++) pref[i][k] -= j;
            prv = x;
        }
        for(int k = prv; k < M; k++) pref[i][k] -= m[i];
    }
    /*for(int i = 1; i <= n; i++){
        for(int k = 0; k < 10; k++){
            cout << pref[i][k] << " ";
        }
        cout << endl;
    }*/
    double mn = INF;
    for(int A = 1; A < M; A++){
        init();
        double ret = recurse(n, s, A, A);
        // if(A<15) cout << A << " " << ret << endl;
        if(ret<mn){
            mn = ret;
            int j = s, k = A;
            for(int i = n; i >= 1; i--){
                ansa[i] = lasta[i][j][k];
                j -= pref[i][ansa[i]];
                k -= ansa[i];
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << ansa[i] << endl;
    }
}