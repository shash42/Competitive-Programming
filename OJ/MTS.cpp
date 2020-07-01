#include<iostream>
#include<vector>
#include<utility>
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

const int N = 1e6 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;
vi adj[N];
int n, s[N][2], r;

void dfssz(int u, int p, int tp)
{
    s[u][tp] = 1;
    for(auto v: adj[u])
    {
        if(v==p) continue;
        dfssz(v, u, tp);
        s[u][tp] += s[v][tp];
     }
}
void findr(int u, int p)
{
    r = u;
    for(auto v: adj[u])
    {
        if(v==p) continue;
        if(s[v][0] > n/2) findr(v, u);
        if(s[v][0] == n - s[v][0] && v > u) findr(v, u);
    }
}
inline int modpow(lint base, int exp, int modulo) {
    base %= modulo;
    lint result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % modulo;
        base = (base * base) % modulo;
        exp >>= 1;
    }
    return result;
}
signed main()
{
    fastio;
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            adj[i].clear();
        }
        for(int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfssz(1, 0, 0);
        findr(1, 0);
        dfssz(r, 0, 1);
        lint ans = 1;
        for(int i = 1; i <= n; i++) ans = (ans*i)%MOD1;
        for(int i = 1; i <= n; i++)
        {
            lint inv = modpow(s[i][1], MOD1-2, MOD1);
            ans = (ans*inv)%MOD1;
        }
        cout << r << " " << ans << endl;
    }
}