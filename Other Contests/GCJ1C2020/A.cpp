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

const int N = 1e3 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;


void solve()
{
    int x, y;
    cin >> x >> y;
    string m;
    cin >> m;
    int n = m.length();
    int mn = INF;
    if(x + y <= 0) mn = 0;
    for(int i = 0; i < n; i++)
    {
        if(m[i]=='S') y-=1;
        if(m[i]=='N') y+=1;
        if(m[i]=='E') x+=1;
        if(m[i]=='W') x-=1;
        if(abs(x)+abs(y)<=i+1) mn = min(mn, i+1);
    }
    if(mn==INF)
    {
        cout << "IMPOSSIBLE";
    }
    else cout << mn;
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