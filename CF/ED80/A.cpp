#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define f first
#define s second
#define lint long long
#define mp make_pair
#define pii pair<int, int>
#define pll pair<lint, lint>
#define ld long double
#define inlld(x) scanf("%lld", &x)
#define ind(x) scanf("%d", &x)
#define vi vector<int>
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define SET(x, val) memset(x, val, sizeof(x))
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define reMin(a, b) a = min(a, b)
#define reMax(a, b) a = max(a, b)
const int N=1e5+5, MOD=1e9+7;
const lint INF=1e18;
lint _add(lint x, lint y) {
    lint ret=x+y;
    while(ret<0LL) ret+=MOD;
    return ret;
}
lint _mult(lint x, lint y) {
    x%=MOD; y%=MOD;
    lint ret=x*y;
    ret%=MOD;
    while(ret<0LL) ret+=MOD;
    return ret;
}
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
int n, d;
signed main()
{
  int t;
  cin >> t;
  while(t--)
  {
    cin >> n >> d;
    if(d<=n)
    {
      cout << "YES\n";
      continue;
    }
    int mn = 1e9;
    for(int i = 1; i*i <= 2*n; i++)
    {
      int dv = i+1;
      mn = min(mn, i + (d/dv + (d%dv!=0)));
    }
    if(mn<=n)
    {
      cout << "YES\n";
      continue;
    }
    else
    {
     // cout << mn;
      cout << "NO\n";
    }
  }
}