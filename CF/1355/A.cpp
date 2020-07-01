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

int a, k;
pii itr(int x)
{
    int mx = 0, mn = 9;
    while(x)
    {
        mx=max(mx, x%10);
        mn=min(mn, x%10);
        x/=10;
    }
    return {mx, mn};
}
void solve()
{
    cin >> a >> k;
    int cnt = 1;
    while(true)
    {
        if(cnt==k) break;
        pii ret = itr(a);
        if(ret.F==0 || ret.S==0) break;
        cnt++;
        a += ret.F*ret.S;
    }
    cout << a << endl;
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