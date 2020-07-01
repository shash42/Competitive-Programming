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
#define pll pair<lint, lint>
#define ld long double
#define inlld(x) scanf("%lld", &x)
#define ind(x) scanf("%d", &x)
#define vi vector<int>
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define SET(x, val) memset(x, val, sizeof(x))
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define reMin(a, b) a = min(a, b)
#define reMax(a, b) a = max(a, b)
const int N=1005, MOD=1e9+7;
const lint INF=1e18;
lint _add(lint x, lint y) {
    lint ret=x+y;
    while(ret<0LL) ret+=MOD;
    return ret;
}
lint _mult(lint x, lint y) {
    x%=MOD; y%=MOD;
    lint ret=x*y;
    ret%=MOD;
    while(ret<0LL) ret+=MOD;
    return ret;
}
inline int modpow(lint base, int exp, int modulo) {
  base %= modulo;  lint result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulo;
    base = (base * base) % modulo; exp >>= 1;
  }
  return result;
}
using namespace std;
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
char mat[N][N];
int n, m, findist=INF, vis[N][N], dist[N][N];
queue<pii> q;
pii st, en;
signed main()
{
    fastio;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> mat[i][j];
            if(mat[i][j]=='S') st = {i, j};
            if(mat[i][j]=='E') en = {i, j};
        }
    }
    dist[en.F][en.S]=0;
    q.push(en);
    int ans = 0;
    while(q.size())
    {
        pii u = q.front();
        q.pop();
        if(mat[u.F][u.S]=='T') continue;
        if(dist[u.F][u.S] > findist) break;
        if(u==st)
        {
            findist=dist[u.F][u.S];
        }
        if(mat[u.F][u.S]<='9' && mat[u.F][u.S]>='0') ans+=mat[u.F][u.S]-'0';
        if(findist==dist[u.F][u.S]) continue;
        if(u.F!=1)
        {
            if(!vis[u.F-1][u.S])
            {
                dist[u.F-1][u.S] = dist[u.F][u.S]+1;
                vis[u.F-1][u.S]=1;
                q.push({u.F-1, u.S});
            }
        }
        if(u.F!=n)
        {
            if(!vis[u.F+1][u.S])
            {
                dist[u.F+1][u.S] = dist[u.F][u.S]+1;
                vis[u.F+1][u.S]=1;
                q.push({u.F+1, u.S});
            }
        }
        if(u.S!=1)
        {
            if(!vis[u.F][u.S-1])
            {
                dist[u.F][u.S-1] = dist[u.F][u.S]+1;
                vis[u.F][u.S-1]=1;
                q.push({u.F, u.S-1});
            }
        }
        if(u.S!=m)
        {
            if(!vis[u.F][u.S+1])
            {
                dist[u.F][u.S+1] = dist[u.F][u.S]+1;
                vis[u.F][u.S+1]=1;
                q.push({u.F, u.S+1});
            }
        }
    }
    cout << ans;
}