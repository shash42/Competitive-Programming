#include<bits/stdc++.h>
#define int long long
#define lint long long
#define pb push_back

using namespace std;

const int N=52;
const int MOD=1e9+7;
lint modpow(lint x, lint y, int mod=MOD)
{
    if(y==0LL)
        return 1LL;
    if(y==1LL)
        return x;
    lint ret=modpow(x, y/2LL);
    ret=ret*ret;
    ret%=mod;
    if(y%2LL)
        ret*=x;
    ret%=mod;
    return ret;
}
int inv(int x)
{
	return modpow(x, MOD-2LL);
}
int choose[N][N], ichoose[N][N];
void ncrinit()
{
	choose[0][0]=1;
	for(int i = 1; i < N; i++) choose[0][i]=0;
	for(int i = 1; i < N; i++)
	{
		choose[i][0]=1;
		for(int j = 1; j < N; j++)
		{
			choose[i][j]=(choose[i-1][j-1] + choose[i-1][j])%MOD;
			ichoose[i][j]=inv(choose[i][j]);
		}
	}
}
int dp[N][N][N], n, m, k, ans, a[N][N], fact[2LL*N];
void solve(vector<int> v)
{
	memset(dp, 0, sizeof(dp));
	int sz = v.size()-1LL;
	int vp[N][N];
	for(int i = 1; i <= sz; i++)
	{
		for(int j = 0; j <= k; j++)
		{
			vp[i][j]=modpow(v[i], j);
		}
	}
	for(int i = 0; i <= sz; i++) dp[i][0][0]=1;
	for(int i = 1; i <= sz; i++)
	{
		for(int j = 1; j <= sz; j++)
		{
			int curr[N];
			memset(curr, 0, sizeof(curr));
			for(int pow = 0; pow<=k; pow++)
			{
				for(int powit=0; powit<=pow; powit++)
				{
					curr[pow] += (((dp[i-1][j-1][powit] * choose[pow][powit])%MOD) * vp[i][pow-powit])%MOD;
				}
				dp[i][j][pow]=(dp[i-1][j][pow]*choose[i-1][j] + curr[pow]*choose[i-1][j-1])%MOD;
				dp[i][j][pow]*=ichoose[i][j];
				dp[i][j][pow]%=MOD;
			}
		}
	}
	int contrib=0;
//	cout << dp[1][1][1] << endl;
	for(int i = 1; i <= sz; i++)
	{
	//	cout << i << " " << dp[sz][i][k] << endl;
		int tmp = dp[sz][i][k];
		tmp*=choose[sz][i]; tmp%=MOD;
		tmp*=fact[i]; tmp%=MOD;
		tmp*=fact[sz-i]; tmp%=MOD;
		//contrib+=dp[n][i][k] * choose[n][i] * fact[i] * fact[n-i];
		contrib+=tmp;
		contrib%=MOD;
	}
	contrib*=inv(fact[sz+1]);
	contrib%=MOD;
//	cout << (contrib*24)%MOD << endl;
	ans+=contrib;
	ans%=MOD;
}
signed main()
{
	ncrinit();
	cin >> n >> m >> k;
	fact[0]=1;
	for(int i = 1; i <= n+m; i++)
	{
		fact[i]=(fact[i-1]*i)%MOD;
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= n; i++)
	{
		vector<int> v;
		v.pb(0);
		for(int j = 1; j <= m; j++)
		{
			v.pb(a[i][j]);
		}
		solve(v);
	}
	for(int i = 1; i <= m; i++)
	{
		vector<int> v;
		v.pb(0);
		for(int j = 1; j <= n; j++)
		{
			v.pb(a[j][i]);
		}
		solve(v);
	}
	cout << (ans*fact[n+m])%MOD;
}