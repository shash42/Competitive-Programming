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

set<pii> st;
int n;
pii a[N];
void solve()
{
    st.clear();
    cin >> n;
    for(int i = 0; i < n; i++)
    {
       cin >> a[i].F >> a[i].S;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int xd = a[i].F - a[j].F;
            int yd = a[i].S - a[j].S;
            if(xd*yd>=0) continue;
            int gc = __gcd(xd, yd);
            st.insert({xd/gc, yd/gc});
        }
    }
    cout << st.size() + 1;
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