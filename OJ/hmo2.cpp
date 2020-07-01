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

ordered_set< pii > os;
map<int, int> cnt;
int q, p, x;
int v = 1;

inline int modpow(lint base, int exp, int modulo) {
    base %= modulo;
    lint result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % modulo;
        base = (base * base) % modulo;
        exp >>= 1;
    }
    return result;
}
signed main()
{
    cin >> q >> p >> x;
    for(int i = 0; i < q; i++)
    {
        char tp; int y;
        cin >> tp;
        if(tp=='A')
        {
            cin >> y;
            cnt[y]++;
            os.insert({y, cnt[y]});
        }
        if(tp=='D')
        {
            cin >> y;
            os.erase({y, cnt[y]});
            cnt[y]--;
        }
        if(tp=='H')
        {
            int h = 0;
            for(auto dem: os)
            {
              //  cout << dem.F << " - " << os.order_of_key({dem.F+1, -1}) << endl;
                h += dem.F*modpow(p, os.order_of_key({dem.F+1, -1}), MOD1);
                h%=MOD1;
            }
            //cout << h << endl;
            v*=modpow(x, h, MOD1);
            v%=MOD1;
        }
    }
    cout << v;
}