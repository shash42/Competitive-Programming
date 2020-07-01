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
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N=2e5+5, MOD=1e9+7;
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
int n, k, c, suff[N];
string s;
vi ans;
signed main()
{
    cin >> n >> k >> c;
    cin >> s;
    for(int i = n-1; i >= max(0LL, n-1-c); i--)
    {
        int curr;
        if(s[i]=='o') curr=1;
        suff[i] = max(curr, suff[i+1]);
    }
    for(int i = n-c-2; i >= 0; i--)
    {
        int curr = 1 + suff[i+c+1];
        if(s[i]=='x') curr = 0;
        suff[i] = max(suff[i+1], curr);
    }
    if(suff[0]>k)
    {
        return 0;
    }
    int curr = 0, jmps=0;
    while(jmps<k)
    {
        while(s[curr]=='x')
        {
            curr++;
        }
        if(curr==n-1)
        {
            ans.pb(curr+1);
        }
        else if(suff[curr+1]<suff[curr])
        {
            ans.pb(curr+1);
        }
        curr+=c+1;
        jmps++;
    }
    for(auto v: ans)
    {
        cout << v << endl;
    }
}