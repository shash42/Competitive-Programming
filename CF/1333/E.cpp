#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define int long long
#define F first
#define S second
#define lint long long
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define SET(x, val) memset(x, val, sizeof(x))
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int N=5e5+5, MOD=1e9+7;
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

int n, m, a[N], lf[N], cnt[N];
int p[N];
signed main()
{
    cin >> n;
    for(int i = 2; i <= n; i++)
    {
        for(int j = i*2; j <= n; j+=i)
        {
            if(lf[j]==0)
            {
                lf[j]=j/i;
                cnt[j/i]++;
                p[j]=j/i;
            }
        }
    }
    sort(p+1, p+n+1);
    for(int i = 1; i <= n; i++)
    {
        if(p[i]==0) p[i]=1;
    }
    for(int i = 2; i <= n; i++)
    {
        cout << p[i] << " ";
    }
    /*int c=n;
    a[c]=n/2;
    for(int i = n/2; i >= 2; i--)
    {
        for(int j = c-1; j >= c-cnt[i]; j--)
        c-=cnt[i];
        for(int j = )
    }*/
}