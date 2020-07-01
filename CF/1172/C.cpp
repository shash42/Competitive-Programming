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
inline int modpow(lint base, int exp, int modulo) {
  base %= modulo;  lint result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulo;
    base = (base * base) % modulo; exp >>= 1;
  }
  return result;
}
using namespace std;
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N=2e5+5, MOD=998244353;
const lint INF=1e18;

int n, w[N], a[N], tot, m;

int inv(int x)
{
    return modpow(x, MOD-2LL, MOD);
}
signed main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> w[i];
        tot+=w[i];
    }
    for(int i = 1; i <= m; i++)
    {
        int k = 0;
        for(int j = 1; j <= n; j++)
        {
            int del = w[j]*inv(tot);
            del%=MOD;
       //     cout << i << " " << j << " - " << w[j] << " " << inv(tot) << " " << del << endl;
            if(a[j])
            {
                w[j] += del;
                k += del;
                w[j]%=MOD; k%=MOD;
            }
            else
            {
                w[j] -= del - MOD;
                k -= del - MOD;
                w[j]%=MOD; k%=MOD;
            }
        }
        tot += k;
        tot %= MOD;
    }
    for(int i = 1; i <= n; i++)
    {
        cout << w[i] << endl;
    }
}