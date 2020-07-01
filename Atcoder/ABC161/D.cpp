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

const int N=1e5+5, MOD=1e9+7, B=12;
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
int x, dp[B][10], pw[B], dig[B];
int solve(int k)
{
    int ans = 0, curr=0, prv, itr=-1;
    for(int i = B-1; i >= 1; i--)
    {
        if(dig[i-1] >= k)
        {
            continue;
        }
        curr += dig[i-1];
        bool flag=false;
        for(int j = 1; j < 10; j++)
        {
            if(curr + dp[i][j] >= k)
            {
                prv = j;
                itr = i-1;
                ans += pw[i]*j;
                flag=true;
                break;
            }
            else
            {
                //cout << i << " " << j << " " << curr << " " << dp[i][j] << endl;
                curr += dp[i][j];
            }
        }
        if(flag) break;
    }
    //cout << itr << " " << prv << " - " << ans << endl;
    if(itr==-1)
    {
        return k;
    }
    int i = itr;
    while(i>=0)
    {
        for(int j = max(0LL, prv-1); j <= min(prv+1, (int) 9); j++)
        {
            if(curr + dp[i][j] >= k)
            {
                prv = j;
                itr = i-1;
                ans += pw[i]*j;
                break;
            }
            else
            {
                curr += dp[i][j];
            }
        }
        i--;
    }
    return ans;
}
signed main()
{
    pw[0]=1;
    for(int i = 1; i < B; i++)
    {
        pw[i] = pw[i-1]*10;
    }
    for(int i = 0; i < 10; i++)
    {
        dp[0][i]=1;
    }
    dig[0] = 9;
    for(int i = 1; i < B; i++)
    {
        dp[i][0] = dp[i-1][1] + dp[i-1][0];
        dp[i][9] = dp[i-1][8] + dp[i-1][9];
        dig[i] = dp[i][9] + dig[i-1];
        for(int j = 1; j < 9; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j+1];
            dig[i] += dp[i][j];
        }
    }
    cin >> x;
    cout << solve(x);
}