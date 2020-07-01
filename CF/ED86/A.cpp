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

int n, a[N];

signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if(x*y < 0)
        {
            cout << (abs(x)+abs(y))*a << endl;
            continue;
        }
        int cost1 = 0, cost2 = 0;
        x = abs(x);
        y = abs(y);
        if(x>y) swap(x, y);
        cost1 = (y-x)*a + x*b;
        cost2 = (x+y)*a;
        cout << min(cost1, cost2) << endl;
    }
}