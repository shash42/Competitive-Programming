#include<bits/stdc++.h>
#define int long long
#define lint long long
using namespace std;

const int N=2e5+5, MOD=998244353;
int dp[N], p[N];
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
signed main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> p[i];
		p[i]*=modpow(100, MOD-2);
		p[i]%=MOD;
	}
	dp[0]=0;
	for(int i = 1; i <= n; i++)
	{
		dp[i]=(dp[i-1]+1)*modpow(p[i-1], MOD-2);
		dp[i]%=MOD;
	}
	cout << dp[n];
}