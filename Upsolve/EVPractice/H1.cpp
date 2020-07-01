#include<bits/stdc++.h>

using namespace std;

const int N = 502, T = 1002;
int n, m, h[N][N], num[N];
double dp[N][T], one = 1.0;

/*O(N^4)
For each day store dp[i]
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> num[i];
		for(int j = 1; j <= num[i]; j++)
		{
			cin >> h[i][j];
		}
	}
	for(int day = 1; day <= m; day++)
	{
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N*T; j++)
			{
				dp[i][j]=0;
			}
		}
		dp[0][0]=one;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 0; j < n*T; j++)
			{
				dp[i][j]=dp[i][j]
			}
		}
	}
}