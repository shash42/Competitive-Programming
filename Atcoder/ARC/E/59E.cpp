#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=404, MOD=1e9+7;
int n, a[N], b[N], dp[N][N], pref[N][N], c;
signed main()
{
	cin >> n >> c;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> b[i];
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = a[i]; j<=b[i]; j++)
		{
			int curr=1;
			for(int k = 0; k <= c; k++)
			{
				pref[i][k]+=curr;
				pref[i][k]%=MOD;
				curr*=j;
				curr%=MOD;
			}
		}
		// for(int k = 0; k <= c; k++)
		// {
		// 	cout << i << " " << k << " - " << pref[i][k] << endl;
		// }
	}
	for(int j = 0; j <= c; j++)
	{
		dp[1][j]=pref[1][j];
	}
	for(int i = 2; i <= n; i++)
	{
		dp[i][0]=(dp[i-1][0]*pref[i][0])%MOD;
		for(int j = 1; j <= c; j++)
		{
			for(int k = 0; k <= j; k++)
			{
				dp[i][j]+=(dp[i-1][k]*pref[i][j-k])%MOD;
				dp[i][j]%=MOD;
			}
		//	cout << i << " - " << j << " " << dp[i][j] << endl; 
		}
	}
	cout << dp[n][c];
}