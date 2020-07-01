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

const int N = 3e5 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, mnx=INF, mxx=-INF, mny=INF, mxy=-INF, ans[N];
pii a[N];
vector<pii> xl, xg, yl, yg;
struct pxpy
{
    bool operator()(pii &u, pii &v)
    {
        return u.F + u.S < v.F + v.S;
    }
};
struct pxmy
{
    bool operator()(pii &u, pii &v)
    {
        return u.F - u.S < v.F - v.S;
    }
};
void chkl(int &mn, int val, vector<pii> &v, pii act)
{
    if(val <= mn)
    {
        if(val < mn)
        {
            mn = val;
            v.clear();
        }
        v.pb(act);
    }
}
void chkg(int &mx, int val, vector<pii> &v, pii act)
{
    if(val >= mx)
    {
        if(val > mx)
        {
            mx = val;
            v.clear();
        }
        v.pb(act);
    }
}
int comp(vector<pii> tmp)
{
    int mxX=-INF, mxY=-INF, mnX=INF, mnY=INF;
    for(auto p: tmp)
    {
        mxX = max(mxX, p.F);
        mxY = max(mxY, p.S);
        mnX = min(mnX, p.F);
        mnY = min(mnY, p.S);
    }
    int ret = mxX - mnX + mxY - mnY;
    return ret*2;
}
void solve(vector<pii> &v1, vector<pii> &v2, int idx)
{
    for(auto p1: v1)
    {
        for(auto p2: v2)
        {
            vector<pii> tmp;
            tmp.pb(p1); tmp.pb(p2); tmp.pb(a[idx]);
            ans[3] = max(ans[3], comp(tmp));
        }
    }
}
signed main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].F >> a[i].S;
        chkl(mnx, a[i].F, xl, a[i]);
        chkg(mxx, a[i].F, xg, a[i]);
        chkl(mny, a[i].S, yl, a[i]);
        chkg(mxy, a[i].S, yg, a[i]);
    }
    for(int i = 3; i <= n; i++)
    {
        ans[i]=-INF;
    }
    //xl, yl
    sort(a, a+n, pxpy());
    solve(xl, yl, n-1);
    //xg, yg
    solve(xg, yg, 0);
    //xl, yg
    sort(a, a+n, pxmy());
    solve(xl, yg, n-1);
    solve(xg, yl, 0);
    int restans = xg[0].F - xl[0].F + yg[0].S - yl[0].S;
    for(int i = 4; i <= n; i++)
    {
        ans[i]=2*restans;
    }
    for(int i = 3; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
}