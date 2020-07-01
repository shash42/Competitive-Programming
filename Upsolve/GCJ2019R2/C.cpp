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
#define ld long double
const int N = 2e5 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;
const int B = 202;
int n, x, y;
set<pii> st;
vector<pii> v;
pii a[12], tmp[12];
int comp(pii p1)
{
    return p1.F*x + p1.S*y;
}
struct srt
{
    bool operator()(const pii &t1, const pii &t2)
    {
        if(comp(t1)==comp(t2))
        {
            return t1.F*(x-1) + t1.S*y < t2.F*(x-1) + t2.S*y;
        }
        return comp(t1) < comp(t2);
    }
};
struct srt2
{
    bool operator()(const pii &t1, const pii &t2)
    {
        return t1.F*t2.S < t1.S*t2.F;
    }
};
bool check()
{
    for(int i = 1; i < n; i++)
    {
        if(tmp[i] != a[i] || comp(tmp[i]) == comp(tmp[i-1])) return false;
    }
    return true;
}
void solve()
{
    st.clear();
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].F >> a[i].S;
        tmp[i] = a[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int xd = a[i].F - a[j].F;
            int yd = a[i].S - a[j].S;
            if(xd*yd>=0) continue;
            int gc = __gcd(abs(xd), abs(yd));
            st.insert({abs(xd)/gc, abs(yd)/gc});
        }
    }
    if(st.size()==0)
    {
        cout << 1 << " " << 1;
        return;
    }
    for(auto it: st)
    {
        v.pb(it);
    }
    int m = v.size();
    sort(v.begin(), v.end(), srt2());
    x = v[0].F, y = v[0].S*2;
    sort(tmp, tmp+n, srt());
    if(check())
    {
        int e = 1;
        int f = (v[0].S)/v[0].F + 1;
        cout << e << " " << f;
        return;
    }
    x = v[m-1].F*2, y = v[m-1].S;
    sort(tmp, tmp+n, srt());
    if(check())
    {
        int e = v[m-1].F/v[m-1].S + 1;
        int f = 1;
        cout << e << " " << f;
        return;
    }
    for(int i = 1; i < m; i++)
    {
        x = v[i].F, y = v[i].S; //some midway
        sort(tmp, tmp+n, srt());
        if(!check()) continue;
        if(v[i].S/v[i].F != v[i-1].S/v[i-1].F)
        {
            int e = 1;
            int f = v[i].S/v[i].F + 1;
            cout << e << " " << f;
            return;
        }
        ld d1 = ((ld) v[i-1].S)/v[i-1].F;
        ld d2 = ((ld) v[i].S)/v[i].F;
        ld dd = d1 - d2;
        int lol = 1/dd;
        int e = lol + 1;
        int f = (v[i].S*e)/v[i].F + 1;
        cout << e << " " << f;
        return;
    }
    cout << "IMPOSSIBLE";
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
    };
}