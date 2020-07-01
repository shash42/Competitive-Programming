#include<bits/stdc++.h>

using namespace std;

const int N=5e3+5;
int dp[N][N], s, b, tot[N], pref[N], mod=1e9+7;
int main()
{
	cin >> s >> b;
	for(int i = 1; i <= b; i++)		dp[i][i]=1;
	for(int i = 1; i <= b; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			if(i==j) continue;
			pref[i-j]=(pref[i-j]+dp[i-j][j])%mod;
			tot[i-j]=(tot[i-j]+pref[i-j])%mod;
			dp[i][j]=tot[i-j];
		}
	}
	cout << dp[b][s];
}