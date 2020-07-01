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

const int N = 2e5 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int ans;
int f(int a, int d, int n)
{
    int ret = 2*a + (n-1)*d;
    ret*=n;
    ret/=2;
    return ret;
}
pii solve2(int big, int sm)
{
    int a1, lo = 0, hi = 2e9, x = sm;
    while(true)
    {
        if(hi-lo<=1)
        {
            if(f(ans+2, 2, hi)<=x)
            {
                a1=hi;
            }
            else a1 = lo;
            break;
        }
        int mid = (lo+hi)/2;
        if(f(ans+2, 2, mid)<=x)
        {
            lo=mid;
        } else{
            hi=mid-1;
        }
    }
    big -= f(ans+1, 2, a1);
    sm -= f(ans+2, 2, a1);
    ans += a1*2;
    if(big-(ans+1)>=0)
    {
        big -= ans+1;
        ans++;
    }
    return {big, sm};
}
void solve()
{
    int l, r;
    ans=0;
    cin >> l >> r;
    int a1, lo = 0, hi = 2e9, x = max(l, r)-min(l, r);
    while(true)
    {
        if(hi-lo<=1)
        {
            if(f(1, 1, hi)<=x)
            {
                a1=hi;
            }
            else a1 = lo;
            break;
        }
        int mid = (lo+hi)/2;
        if(f(1, 1, mid)<=x)
        {
            lo=mid;
        } else{
            hi=mid-1;
        }
    }
    if(l>=r) l-=f(1, 1, a1);
    else r-=f(1, 1, a1);
    if(l>=r)
    {
        ans+=a1;
        pii ret = solve2(l, r);
        cout << ans << " " << ret.F << " " << ret.S;
    }
    else
    {
        ans+=a1;
        pii ret = solve2(r, l);
        cout << ans << " " << ret.S << " " << ret.F;
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