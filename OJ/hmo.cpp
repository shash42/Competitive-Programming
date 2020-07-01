#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
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

const int N = 1e6+6;
const lint MOD=1e9+7;

inline lint modpow(lint base, int exp, int modulo) {
    base %= modulo;
    lint result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % modulo;
        base = (base * base) % modulo;
        exp >>= 1;
    }
    return result;
}
vi ans;
pii qarr[N];
vector< pii > srt;
int q, x, pos[N], lazy[4*N];
lint p, pinv;
pii segt[4*N];
void lazify(int idx, int l, int r)
{
    if(lazy[idx]==1) return;
    segt[idx].S = ((lint) segt[idx].S * lazy[idx])%MOD;
    if(l==r){
        lazy[idx] = 1;
        return;
    }
    lazy[2*idx] = ( (lint) lazy[idx] * lazy[2*idx]) % MOD;
    lazy[2*idx + 1] = ( (lint) lazy[idx] * lazy[2*idx+1]) % MOD;
    lazy[idx]=1;
}
void update(int idx, int l, int r, int ss, int rc, int hc)
{
    lazify(idx, l, r);
    if(l>ss || r<ss) return;
    if(l==r)
    {
        segt[idx].S = (segt[idx].S + hc)%MOD;
        segt[idx].F = segt[idx].F + rc;
        return;
    }
    int mid = (l+r)/2;
    update(idx*2, l, mid, ss, rc, hc);
    update(idx*2+1, mid+1, r, ss, rc, hc);
    segt[idx].S = (segt[idx*2].S + segt[idx*2+1].S)%MOD;
    segt[idx].F = segt[idx*2].F + segt[idx*2+1].F;
}
void updmult(int idx, int l, int r, int ss, int ee, lint mult)
{
    lazify(idx, l, r);
    if(l>ee || r<ss) return;
    if(l >= ss && r <= ee)
    {
        lazy[idx] = (lazy[idx] * mult)%MOD;
        lazify(idx, l, r);
        return;
    }
    int mid = (l+r)/2;
    updmult(idx*2, l, mid, ss, ee, mult);
    updmult(idx*2+1, mid+1, r, ss, ee, mult);
    segt[idx].S = (segt[idx*2].S + segt[idx*2+1].S)%MOD;
    segt[idx].F = segt[idx*2].F + segt[idx*2+1].F;
}
pii query(int idx, int l, int r, int ss, int ee)
{
    lazify(idx, l, r);
    if(l > ee || r < ss) return {0, 0};
    if(l >= ss && r <= ee) return segt[idx];
    int mid = (l+r)/2;
    pii ql = query(idx*2, l, mid, ss, ee);
    pii qr = query(idx*2+1, mid+1, r, ss, ee);
    return {ql.F + qr.F, (ql.S + qr.S)%MOD};
}
signed main()
{
    fastio;
    cin >> q >> p >> x;
    pinv = modpow(p, MOD-2, MOD);
    srt.pb({-1, -1});
    for(int i = 0; i < q; i++)
    {
        int y;
        char c;
        cin >> c;
        if(c=='A' || c=='D')
        {
            cin >> y;
            srt.pb({y, i});
        }
        if(c=='H') qarr[i] = {'H', -1};
        else qarr[i] = {c, y};
    }
    sort(srt.begin(), srt.end());
    int curri = 0;
    for(int i = 1; i < srt.size(); i++)
    {
        if(srt[i].F != srt[i-1].F) curri = i;
        pos[srt[i].S] = curri;
    }
    for(int i = 0; i < 4*N; i++)
    {
        lazy[i] = 1;
    }
    for(int i = 0; i < q; i++)
    {
        pii ret;
        if(qarr[i].F == 'A')
        {
            ret = query(1, 1, q, 1, pos[i]);
            int curr = (qarr[i].S * modpow(p, ret.F, MOD))%MOD;
            update(1, 1, q, pos[i], 1, curr);
            updmult(1, 1, q, pos[i], q, p);
        }
        else if(qarr[i].F == 'D')
        {
            pii chk = query(1, 1, q, pos[i], pos[i]);
            if(chk.F==0)
            {
                continue;
            }
            ret = query(1, 1, q, 1, pos[i]);
            int curr = (qarr[i].S * modpow(p, ret.F, MOD))%MOD;
            curr = (MOD - curr)%MOD;
            update(1, 1, q, pos[i], -1, curr);
            updmult(1, 1, q, pos[i], q, pinv);
        }
        else
        {
            ret = query(1, 1, q, 1, q);
            ans.pb(ret.S);
        }
    }
    int v = 1;
    for(auto elem: ans)
    {
        v = (v * modpow(x, elem, MOD)) % MOD;
    }
    cout << v;
}