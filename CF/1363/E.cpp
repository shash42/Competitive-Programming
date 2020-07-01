#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

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
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, t2idx[N], st[N], en[N], t=0, b[N], c[N], segt[4*N][2], par[N];
pii a[N];
vi adj[N];
void dfs(int u, int p)
{
    par[u] = p;
    st[u] = ++t;
    t2idx[t] = u;
    for(auto v: adj[u])
    {
        if(v==p) continue;
        dfs(v, u);
    }
    en[u] = t;
}
void combine(int idx)
{
    segt[idx][0] = segt[idx*2][0] + segt[idx*2+1][0];
    segt[idx][1] = segt[idx*2][1] + segt[idx*2+1][1];
}
void build(int idx, int l, int r)
{
    if(l==r)
    {
        int curr = t2idx[l];
        if(b[curr]==c[curr]) return;
        segt[idx][b[curr]] += 1;
        return;
    }
    int mid = (l+r)/2;
    build(idx*2, l, mid);
    build(idx*2+1, mid+1, r);
    combine(idx);
}
int query(int idx, int l, int r, int s, int e, int w)
{
    if(l>e || r<s) return 0;
    if(l==r)
    {
        return segt[idx][w];
    }
    int mid = (l+r)/2;
    int q1 = query(idx*2, l, mid, s, e, w);
    int q2 = query(idx*2+1, mid+1, r, s, e, w);
    return q1+q2;
}
void update(int idx, int l, int r, int x, int val)
{
    if(l>x || r<x) return;
    if(l==r)
    {
        segt[idx][0] += val; segt[idx][1]+=val;
        return;
    }
    int mid = (l+r)/2;
    update(idx*2, l, mid, x, val);
    update(idx*2+1, mid+1, r, x, val);
    combine(idx);
}
int vis[N];
void d2(int u) {
    vis[u] = 1;
    for(auto v: adj[u])
    {
        if(vis[v] || v==par[u]) continue;
        d2(v);
    }
}
signed main()
{
    fastio;
    lint cost = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].F >> b[i] >> c[i];
        a[i].S=i;
    }
    sort(a+1, a+n+1);
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 0);
    build(1, 1, n);
    int z0 = query(1, 1, n, 1, n, 0), z1 = query(1, 1, n, 1, n, 1);
    if(z0!=z1)
    {
        cout << -1;
        return 0;
    }
    for(int i = 1; i <= n; i++)
    {
        int id = a[i].S;
        if(vis[id]) continue;
        int l = st[id], r = en[id];
        int zeros = query(1, 1, n, l, r, 0);
        int ones = query(1, 1, n, l, r, 1);
        if(min(zeros, ones)==0) continue;
        //cout << id << " " << zeros << " " << ones << endl;
        if(zeros<ones)
        {
            cost += (2LL*zeros)*a[i].F;
            update(1, 1, n, l, -zeros);
        }
        else
        {
            cost += (2LL*ones)*a[i].F;
            update(1, 1, n, l, -ones);
        }
        d2(id);
    }
    cout << cost;
}