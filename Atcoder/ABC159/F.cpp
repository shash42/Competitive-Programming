#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
using namespace std;
const int N = 3003, mod = 998244353;
int a[N], dp[2][N], n, s, ans;
int M(int x)
{
    int ret = x%mod;
    ret+=mod;
    ret%=mod;
    return ret;
}
signed main()
{
    cin >> n >> s;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        dp[i%2][a[i]]=i;
        for(int j = 1; j <= s; j++)
        {
            if(j!=a[i]) dp[i%2][j]=0;
            dp[i%2][j] += dp[1 - (i%2)][j];
            dp[i%2][j] = M(dp[i%2][j]);
            if(j>=a[i]) dp[i%2][j] += dp[1 - (i%2)][j-a[i]];
            dp[i%2][j] = M(dp[i%2][j]);
         //   cout << dp[i%2][j] << " ";
        }
      //  cout << endl;
        ans += M((dp[i%2][s] - dp[1 - (i%2)][s]) * (n-i+1));
        ans = M(ans);

    }
    cout << ans;
}