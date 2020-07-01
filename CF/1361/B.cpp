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

const int N = 1e6 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

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
inline int npow(lint base, int exp) {
    lint result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base);
        base = (base * base);
        exp >>= 1;
    }
    return result;
}
int n, p, k[N], cnt[N];
set<int> pt;
vi powz;

void rest()
{
    for(auto kk: powz)
    {
        cnt[kk]=0;
    }
    powz.clear(); pt.clear();
}
int ansfor(int lst)
{
    int ans = modpow(p, powz[lst], MOD1);
    for(int i = lst-1; i >= 0; i--)
    {
        int red = cnt[powz[i]]*modpow(p, powz[i], MOD1);
        red%=MOD1;
        ans = (ans - red + MOD1)%MOD1;
    }
    return ans;
}

void solve()
{
    rest();
    cin >> n >> p;
    int bested = 0, tmp = n, need=0, lst=-1;
    for(int i = 0; i < n; i++)
    {
        cin >> k[i];
        cnt[k[i]]++;
        pt.insert(k[i]);
    }
    for(auto pp: pt)
    {
        powz.pb(pp);
    }
    sort(powz.begin(), powz.end());
    if(p==1)
    {
        cout << n%2 << endl;
        return;
    }
    while(tmp)
    {
        tmp/=p;
        bested++;
    }
    int l = powz.size();
    //cout << l << endl;
    for(int i = l-1; i >= 0; i--)
    {
        // cout << i << " " << powz[i] << " " << need << endl;
        int x = powz[i];
        if(lst==-1)
        {
            if(cnt[x]%2==1)
            {
                lst = i;
                need = 1;
            }
            continue;
        }
        if((powz[i+1] - x) >= bested)
        {
            //cout << "chacha" << bested << endl;
            cout << ansfor(lst) << endl;
            return;
        }
        int n_need = need*npow(p, powz[i+1]-x);
        // cout << n_need << endl;
        if(cnt[x] >= n_need)
        {
            cnt[x] -= n_need;
            lst = -1; need = 0;
            if(cnt[x]%2==1)
            {
                lst = i;
                need = 1;
            }
            continue;
        }
        if(n_need > n)
        {
            cout << ansfor(lst) << endl;
            return;
        }
        need = n_need - cnt[x];
    }
    if(lst!=-1) cout << ansfor(lst) << endl;
    else cout << 0 << endl;
}
signed main()
{
    fastio;
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
