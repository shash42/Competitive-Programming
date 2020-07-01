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

set<int> st;
int n, f[N], g[N], h[N], idx[N];
vector<int> s;
signed main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> f[i];
        st.insert(f[i]);
    }
    int m = st.size();
    s.pb(-1);
    for(auto p: st)
    {
        s.pb(p);
        idx[p] = s.size()-1;
    }
    for(int i = 1; i <= m; i++)
    {
        h[i] = s[i];
    }
    for(int i = 1; i <= n; i++)
    {
        g[i] = idx[f[i]];
    }
    bool chk = true;
    for(int i = 1; i <= n; i++)
    {
        if(i<=m && g[h[i]]!=i) chk = false;
        if(h[g[i]]!=f[i]) chk = false;
    }
    if(chk)
    {
        cout << m << endl;
        for(int i = 1; i <= n; i++)
        {
            cout << g[i] << " ";
        }
        cout << endl;
        for(int i = 1; i <= m; i++)
        {
            cout << h[i] << " ";
        }
    }
    else
    {
        cout << -1;
    }
}
