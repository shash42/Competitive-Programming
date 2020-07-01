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

const int N = 1e2+2, M=1e3+3, MOD1 = 1e9 + 7, MOD2 = 998244353;
const int INF = 1e6;

int n, m, p[N], dist[N];
vector<pii> wt, num, comb;
bool vis[N];
struct ej
{
    int u, v, t, idx;
} e[M];
int nei(int i, int u)
{
    return e[i].u ^ e[i].v ^ u;
}
struct dijsrt
{
    bool operator()(const pii &a, const pii &b)
    {
        if(p[a.F]==p[b.F])
        {
            return dist[nei(a.S, a.F)] > dist[nei(b.S, b.F)];
        }
        return p[a.F] > p[b.F];
    }
};
vector<pii> adj[N];
priority_queue<pii, vector<pii>, dijsrt> dij;
void reset()
{
    while(dij.size()) dij.pop();
    wt.clear(); num.clear(); comb.clear();
    for(int i = 1; i <= n; i++)
    {
        adj[i].clear();
        vis[i]=false;
        dist[i]=0;
        p[i]=0;
    }
    for(int i = 1; i <= m; i++)
    {
        e[i].t = 0;
    }
}
void consol()
{
    sort(num.begin(), num.end());
    sort(wt.begin(), wt.end());
    int pn=0, pw=0;
    while(pn < num.size() && pw<wt.size())
    {
        if(comb.size() < num[pn].F && pw < wt.size())
        {
            comb.pb(wt[pw]);
            pw++;
        }
        else if(num[pn].F <= comb.size() && pn < num.size())
        {
            comb.pb({-num[pn].F, num[pn].S});
            pn++;
        }
    }
    while(pn < num.size())
    {
        comb.pb({-num[pn].F, num[pn].S});
        pn++;
    }
    while(pw < wt.size())
    {
        comb.pb(wt[pw]);
        pw++;
    }
}
void inp()
{
    cin >> n >> m;
    for(int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        if(x<0)
        {
            num.pb({-x, i});
        }
        else
        {
            wt.pb({x, i});
        }
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> e[i].u >> e[i].v;
        adj[e[i].u].pb({e[i].v, i});
        adj[e[i].v].pb({e[i].u, i});
        e[i].idx = i;
    }
}
void dijkstra()
{
    dij.push({1, -1});
    int mxnum = 0, mxwt = 0;
    while(dij.size())
    {
        pii c = dij.top();
        dij.pop();
        int u = c.F;
        if(vis[u]) continue;
        vis[u]=true;
        int val = comb[p[u]].F;
       // cout << u << " - " << val << endl;
        if(val < 0LL)
        {
            if(-val==mxnum)
            {
                e[c.S].t = mxwt - dist[nei(c.S, u)];
            }
            else
            {
                mxnum = -val;
                mxwt = mxwt + 1;
                e[c.S].t = mxwt - dist[nei(c.S, u)];
            }
        }
        else if(val > 0LL)
        {
            e[c.S].t = val - dist[nei(c.S, u)];
            mxwt = max(mxwt, val);
        }
        dist[u] = mxwt;
        for(auto vv: adj[u])
        {
            int v = vv.F;
            if(vis[v]) continue;
            dij.push({v, vv.S});
        }
    }
}
void solve()
{
    reset();
    inp();
    comb.pb({0, 1});
    consol();
    for(int i = 0; i < n; i++)
    {
        p[comb[i].S]=i;
        //cout << i << ": " << comb[i].S << endl;
    }
    dijkstra();
    for(int i= 1; i <= m; i++)
    {
        if(e[i].t==0LL) e[i].t = INF;
        cout << e[i].t << " ";
    }
}
signed main()
{
    int T;
    cin >> T;
    int t = T;
    while(t--)
    {
        cout << "Case #" << T-t << ": ";
        solve();
        cout << endl;
    }
}