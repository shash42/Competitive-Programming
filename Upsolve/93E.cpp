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

const int N = 2e3 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, m, x, par[N], cost, ans=1, mult=1, cnt;
struct edge
{
    int u, v, w;
} e[N];
struct ejsrt
{
    bool operator()(const edge &a, const edge &b)
    {
        return a.w < b.w;
    }
};
void reset()
{
    for(int i = 1; i <= n; i++)
    {
        par[i]=i;
    }
    cost=0;
}
int fnd(int x)
{
    if(par[x]==x) return x;
    return par[x]=fnd(par[x]);
}
void uni(int u, int v)
{
    par[u]=v;
}
void span()
{
    for(int i = 0; i < m; i++)
    {
        if(fnd(e[i].u)==fnd(e[i].v)) continue;
        uni(fnd(e[i].u), fnd(e[i].v)); cost+=e[i].w;
    }
}
signed main()
{
    cin >> n >> m >> x;
    for(int i = 0; i < m; i++)
    {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e, e+m, ejsrt());
    for(int i = 0; i < m; i++)
    {
        reset();
        uni(fnd(e[i].u), fnd(e[i].v)); cost+=e[i].w;
        span();
        if(cost>x) ans=(ans*2)%MOD1;
        else if(cost==x) mult=(mult*2)%MOD1;
        else cnt++;
    }
    if(mult==1)
    {
        cout << 0;
        return 0;
    }
    mult = (mult+MOD1-1)%MOD1;
    if(cnt!=0) ans=(ans*2)%MOD1;
    else mult = (mult+MOD1-1)%MOD1;
    ans = (ans*mult)%MOD1;
    cout << ans;
}