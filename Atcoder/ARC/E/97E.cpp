#include<bits/stdc++.h>

using namespace std;

const int N=2e3+4, INF=1e9;
int pos[2][N], dp[N][N], cb[N][N], cw[N][N], n;
int main()
{
	cin >> n;
	for(int i = 1; i <= 2*n; i++)
	{
		char c; int x;
		cin >> c >> x;
		pos[(c=='W')][x]=i;
	}
	for(int i = 1; i <= n; i++)
	{
		int bb=0;
		for(int j = 1; j < i; j++)
		{
			if(pos[0][j]>pos[0][i]) bb++;
		}
		cb[i][0]=bb;
		for(int j = 1; j <= n; j++)
		{
			cb[i][j]=cb[i][j-1]  + (pos[1][j]>pos[0][i]);
		}
	}
	for(int i = 1; i <= n; i++)
	{
		int ww=0;
		for(int j = 1; j < i; j++)
		{
			if(pos[1][j]>pos[1][i]) ww++;
		}
		cw[i][0]=ww;
		for(int j = 1; j <= n; j++)
		{
			cw[i][j]=cw[i][j-1] + (pos[0][j]>pos[1][i]);
		}
	}
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= n; j++)
		{
			dp[i][j]=INF;
		}
	}
	dp[0][0]=0;
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= n; j++)
		{
			if(i!=0) dp[i][j]=min(dp[i][j], dp[i-1][j] + cb[i][j]);
			if(j!=0) dp[i][j]=min(dp[i][j], dp[i][j-1] + cw[j][i]);
		}
	}
	cout << dp[n][n];
}