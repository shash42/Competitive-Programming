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
using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int c, h, tt;
int f(int d)
{
    return d*c + (d+1)*h;
}
int g(int d)
{
    return (2*d+1);
}
void solve()
{
    cin >> h >> c >> tt;
    int avg = (c+h)/2;
    if(tt >= h)
    {
        cout << 1 << endl;
        return;
    }
    if(tt <= avg)
    {
        cout << 2 << endl;
        return;
    }
    int numm = tt-h;
    int denom = c+h-2*tt;
    int d = numm/denom + (numm%denom!=0);
    /*int lo = 1, hi = 1e12, d=hi+1;
    while(true)
    {
        if(hi-lo<=1)
        {
            if(f(lo) <= g(lo)*tt)
            {
                d=lo;
            } else{
                d = hi;
            }
            break;
        }
        int mid = (lo+hi)/2;
        if(f(mid) <= g(mid)*tt)
        {
            hi = mid;
        }
        else
        {
            lo = mid+1;
        }
    }*/
    int numd, dend, numdp, dendp;
    numd = abs(f(d) - g(d)*tt);
    dend = g(d);
    numdp = abs(f(d-1) - g(d-1)*tt);
    dendp = g(d-1);
    if(numd*dendp < numdp*dend)
    {
        cout << 2*d + 1 << endl;
        return;
    }
    cout << 2*d - 1 << endl;
}
signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}