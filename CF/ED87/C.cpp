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

int n;
#define PI 3.14159265
void solve()
{
    cin >> n;
    int m = n*2;
    if(n%2==0)
    {
        double ang = (2*PI)/m, cang=0, ans=0;
        for(int i = 2; i <= n; i++)
        {
            cang+=ang;
            ans+=sin(cang);
        }
        cout << ans << endl;
        return;
    }
    double ang = (2*PI)/m, cang=0, ans=0;
    for(int i = 2; i <= n; i++)
    {
        cang+=ang;
        ans+=sin(cang);
    }
    cout << ans << endl;
}
signed main()
{
    cout << setprecision(10);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}