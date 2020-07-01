#include<bits/stdc++.h>
#define int long long
#define lint int
using namespace std;

const int MOD=998244353, K = 5003;
lint modpow(lint x, lint y, int mod=MOD)
{
    if(y==0)
        return 1LL;
    if(y==1)
        return x;
    lint ret=modpow(x, y/2);
    ret=ret*ret;
    ret%=mod;
    if(y%2)
        ret*=x;
    ret%=mod;
    return ret;
}

int n, m, k, dp[K][K];

signed main()
{
	cin >> n >> m >> k;
	int mkinv = modpow(modpow(m, n), MOD-2);
	for(int i = 0; i <= k; i++)
	{
		dp[0][i]=modpow(m, n-i);
	}
	for(int i = 1; i <= k; i++)
	{
		for(int j = 0; j <= k-i; j++)
		{
			dp[i][j]=(j*dp[i-1][j])%MOD;
			dp[i][j]+=((n-j)*dp[i-1][j+1])%MOD; 
			dp[i][j]%=MOD;
		}
	}
	cout << (dp[k][0]*mkinv)%MOD;
}