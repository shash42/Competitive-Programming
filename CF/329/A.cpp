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
const int N=105, MOD=1e9+7;
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

char mat[N][N];
int n, cnt[2][N], marked[2][N], mcnt;
pii lst[2][N];
vector< pii > ans[2];
signed main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> mat[i][j];
            if(mat[i][j]=='.')
            {
                cnt[0][i]++;
                cnt[1][j]++;
                lst[0][i] = {i, j};
                lst[1][j] = {i, j};
            }
        }
    }
    for(int i = 0; i < 2; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(cnt[i][j]==0)
            {
                break;
            }
            else
            {
                ans[i].pb(lst[i][j]);
            }
        }
    }
    if(ans[0].size()==n)    for(auto v: ans[0])       cout << v.F << " " << v.S << endl;
    else if(ans[1].size()==n)    for(auto v: ans[1])       cout << v.F << " " << v.S << endl;
    else cout << -1;
}