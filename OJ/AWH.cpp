#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#define pb push_back
#define F first
#define S second
#define lint long long
#define mp make_pair
#define pli pair<lint, int>
#define pii pair<int, int>
#define vi vector<int>
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define SET(x, val) memset(x, val, sizeof(x))
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

const int N = 1e5 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

struct dsrt
{
    bool operator()(const pii &a, const pii &b)
    {
        return a.F > b.F;
    }
};
int x, n, m = 0;
vector< pii > lst[N], srt, lidx[N];
int scnt[N], cnt[N], l[N], idx[N], mxl = 0, tm = 1;
lint ssum[N], sum[N], ans[N];
pli segt[4*N];
void update(int idx, int l, int r, int pos)
{
    if(l>pos || r<pos) return;
    if(l==r)
    {
        segt[idx] = {srt[l].F, 1};
        return;
    }
    int mid = (l+r)/2;
    update(idx*2, l, mid, pos);
    update(idx*2+1, mid+1, r, pos);
    segt[idx].F = segt[idx*2].F + segt[idx*2+1].F;
    segt[idx].S = segt[idx*2].S + segt[idx*2+1].S;
}
pli query(int idx, int l, int r, int ss, int ee)
{
    if(l > ee || r < ss) return {0, 0};
    if(l==r) return segt[idx];
    int mid = (l+r)/2;
    pli qry1 = query(idx*2, l, mid, ss, ee);
    pli qry2 = query(idx*2+1, mid+1, r, ss, ee);
    return {qry1.F + qry2.F, qry1.S + qry2.S};
}
lint bs(int req)
{
    if(req<=0) return 0;
    int lo = 1, hi = m;
    if(req > query(1, 1, m, 1, m).S) return INF;
    while(true)
    {
        int mid = (hi + lo) / 2;
        pli qry = query(1, 1, m, 1, mid);
        if(qry.S == req)
        {
            return qry.F;
        }
        if(qry.S < req) lo = mid + 1;
        if(qry.S > req)  hi = mid - 1;
    }
}
signed main()
{
    fastio;
    cin >> x >> n;
    srt.pb({-1, -1});
    for(int i = 0; i < n; i++)
    {
        cin >> l[i];
        m += l[i];
        mxl = max(mxl, l[i]);
        lst[i].pb({1e9, -1});
        for(int j = 1; j <= l[i]; j++)
        {
            int y;
            cin >> y;
            srt.pb({y, tm});
            lst[i].pb(mp(y, tm++));
        }
        sort(lst[i].begin() + 1, lst[i].end(), dsrt());
        for(int j = 1; j <= l[i]; j++)
        {
            sum[j] += lst[i][j].F;
            cnt[j]++;
            lidx[j].pb(lst[i][j]);
        }
    }
    if(x>mxl)
    {
        cout << 0;
        return 0;
    }
    sort(srt.begin()+1, srt.end());
    for(int i = 1; i < srt.size(); i++)
    {
        idx[srt[i].S] = i;
    }
    ssum[mxl] = sum[mxl]; scnt[mxl] = cnt[mxl];
    for(int i = mxl-1; i >= 1; i--)
    {
        ssum[i] = ssum[i+1] + sum[i];
        scnt[i] = scnt[i+1] + cnt[i];
    }
    for(int i = 1; i < x; i++)
    {
        ans[i] = INF;
        for(auto award: lidx[i])
        {
            update(1, 1, m, idx[award.S]);
        }
    }
    for(int i = max(1, x); i <= mxl + 1; i++)
    {
        int req = i - scnt[i] - x;
        lint cost = ssum[i];
        cost += bs(req);
        ans[i] = cost;
        if(i>mxl) break;
        for(auto award: lidx[i])
        {
            update(1, 1, m, idx[award.S]);
        }
    }
    lint mn = INF;
    for(int i = 1; i <= mxl+1; i++)
    {
        mn = min(mn, ans[i]);
    }
    cout << mn;
}