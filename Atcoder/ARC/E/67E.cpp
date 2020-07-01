#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
const int N=1e3+5, MOD=1e9+7;
using namespace std;
int dp[N][N], n, a, b, c, d, nck[N][N], fact[N], ipw[N][N], ifact[N];
inline int modpow(int base, int exp, int modulo)
{
  base %= modulo;  int result = 1;
  while (exp > 0LL) {
    if (exp & 1LL) result = (result * base) % modulo;
    base = (base * base) % modulo; exp >>= 1;
  }
  return result % modulo;
}
int grp(int gsz, int ng)
{
    int ret = fact[gsz*ng];
    ret *= ipw[gsz][ng];
    ret %= MOD;
    ret *= ifact[ng];
    return ret % MOD;
}
signed main()
{
    fact[0]=1;
    ifact[0]=1;
    for(int i = 0; i < N; i++)
    {
        if(i) fact[i]=(fact[i-1]*i)%MOD;
        if(i) ifact[i] = (ifact[i-1]*modpow(i, MOD-2, MOD))%MOD;
        nck[0][i]=0;
        dp[0][i]=0;
        nck[i][0]=1;
        dp[i][0]=1;
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            ipw[i][j]=modpow(modpow(fact[i], j, MOD), MOD-2, MOD);
        }
    }
    for(int i = 1; i < N; i++)
    {
        for(int j = 1; j < N; j++)
        {
            nck[i][j] = nck[i-1][j-1] + nck[i-1][j];
            nck[i][j] %= MOD;
        }
    }
    cin >> n >> a >> b >> c >> d;
    a--;
    for(int i = 1; i <= b-a; i++)
    {
        for(int j = 1; j <= n; j++)
        {
           // cout << i << " | " << j << endl;
            dp[i][j]=dp[i-1][j];
            for(int k = c; k <= d; k++)
            {
                if(k*(a+i) > j) break;
                int lst = j - (a+i)*k;
                int curr = dp[i-1][lst] * nck[n-lst][(a+i)*k];
                curr %= MOD;
                curr *= grp(a+i, k);
                curr%=MOD;
              //  cout << k << " - " << curr << endl;
                dp[i][j] += curr;
                dp[i][j] %= MOD;
            }
          //  cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    cout << dp[b-a][n];
}