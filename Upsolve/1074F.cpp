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
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5 + 5, L = 20, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, q, p[N][L], st[N], en[N], lazy[4*N], tt, d[N];
pii segt[4*N];
set < pii > sp;
vi adj[N];
void dfs(int u)
{
    st[u] = ++tt;
    for(auto v: adj[u])
    {
        if(v==p[u][0]) continue;
        p[v][0] = u;
        d[v] = d[u]+1;
        dfs(v);
    }
    en[u] = tt;
}
void lcafy()
{
    for(int i = 1; i < L; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            p[j][i] = p[p[j][i-1]][i-1];
        }
    }
}
void lazify(int idx, int l, int r)
{
    segt[idx].F += lazy[idx];
    if(l!=r)
    {
        lazy[idx*2]+=lazy[idx];
        lazy[idx*2+1]+=lazy[idx];
    }
    lazy[idx]=0;
}
pii combine(pii a, pii b)
{
    if(a.F==b.F)
    {
        return {a.F, a.S+b.S};
    }
    if(a.F>b.F) return a;
    return b;
}
void build(int idx, int l, int r)
{
    if(l==r)
    {
        segt[idx] = {0, 1};
        return;
    }
    int mid = (l+r)/2;
    build(idx*2, l, mid);
    build(idx*2+1, mid+1, r);
    segt[idx] = combine(segt[idx*2], segt[idx*2+1]);
}
void update(int idx, int l, int r, int s, int e, int val)
{
    lazify(idx, l, r);
    if(l>e || r<s) return;
    if(l>=s && r<=e)
    {
        lazy[idx] += val;
        lazify(idx, l, r);
        return;
    }
    int mid = (l+r)/2;
    update(idx*2, l, mid, s, e, val);
    update(idx*2+1, mid+1, r, s, e, val);
    segt[idx] = combine(segt[idx*2], segt[idx*2+1]);
}
pii query(int idx, int l, int r, int s, int e)
{
    lazify(idx, l, r);
    if(l>e || r<s) return {0, 0};
    if(l>=s && r<=e)
    {
        return segt[idx];
    }
    int mid = (l+r)/2;
    pii ql = query(1, l, mid, s, e);
    pii qr = query(1, mid+1, r, s, e);
    return combine(ql, qr);
}
signed main()
{
    fastio;
    cin >> n >> q;
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }
    p[1][0] = 1;
    dfs(1);
    lcafy();
    build(1, 1, n);
    int tot = 0;
    for(int i = 1; i <= q; i++)
    {
        int u, v, upd=1;
        cin >> u >> v;
        if(st[u]>st[v]) swap(u, v);
        if(sp.find({u, v}) != sp.end()) {
            tot--;
            sp.erase({u, v});
            upd = -1;
        }
        else {
            sp.insert({u, v});
            tot++;
        }
        if(st[v]<=en[u])
        {
            update(1, 1, n, 1, n, upd);
            update(1, 1, n, st[v], en[v], upd);
            for(int i = L-1; i >= 0; i--)
            {
                if(d[p[v][i]] > d[u])
                {
                    v = p[v][i];
                }
            }
            update(1, 1, n, st[v], en[v], -upd);
        }
        else{
            update(1, 1, n, st[u], en[u], upd);
            update(1, 1, n, st[v], en[v], upd);
        }
        pii qry = query(1,1, n, 1, n);
        if(qry.F == tot) cout << qry.S << endl;
        else cout << 0 << endl;
    }
}