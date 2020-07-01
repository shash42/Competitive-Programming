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
int a, b, q, k;
ordered_set<int> mods;

int comp(int x)
{
    int ret = 0;
    ret = mods.size() * (x/k);
    int curr = (x/k) * k;
    int lol = x - curr;
    int num = mods.order_of_key(lol + 1);
    ret += num;
    return ret;
}
signed main()
{
    fastio;
    int t;
    cin >> t;
    while(t--)
    {
        mods.clear();
        cin >> a >> b >> q;
        k = (a*b)/__gcd(a, b);
        for(int i = 1; i < k; i++)
        {
            if((i%b)%a != (i%a)%b)
            {
                mods.insert(i);
            }
        }
        for(int i = 0; i < q; i++)
        {
            int l, r;
            cin >> l >> r;
            int ans = comp(r);
            ans -= comp(l-1);
            cout << ans << " ";
        }
        cout << endl;
    }
}