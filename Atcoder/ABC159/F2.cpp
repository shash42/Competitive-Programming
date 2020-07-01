#include<bits/stdc++.h>
#define lint long long
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
using namespace std;
const int N = 3003, mod = 998244353;
int a[N], dp[N][N], n, s;
lint ans;
int M(lint x)
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
        dp[i][a[i]]=i;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= s; j++)
        {
            dp[i][j] += dp[i-1][j] + dp[i-1][j-a[i]];
            dp[i][j] = M(dp[i][j]);
            cout << dp[i][j] << " ";
        }
        cout << endl;
        ans += M((dp[i][s] - dp[i-1][s]) * ( (lint) n-i+1));
        ans = M(ans);

    }
    cout << ans;
}
