#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int, int>

using namespace std;

const int N=102, INF=1e3;
int dp[N][N][N][2];
int a[N], n;
signed main()
{
	int t = 1;
//	cin >> t;
	while(t--)
	{
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				for(int k = 0; k < N; k++)
				{
					dp[i][j][k][0]=dp[i][j][k][1]=INF;
				}
			}
		}
		cin >> n;
		int eve = n/2;
		int odd = n-eve;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if(a[i]==0) a[i]=-1;
			else if(a[i]%2==0)
			{
				a[i]=0;
				eve--;
			}
			else
			{
				a[i]=1;
				odd--;
			}
		}
		if(a[1]!=-1) dp[1][odd][eve][a[1]]=0;
		else
		{
			dp[1][odd-1][eve][1]=0;
			dp[1][odd][eve-1][0]=0;
		}
		for(int i = 2; i <= n; i++)
		{
			for(int j = 0; j <= odd; j++)
			{
				for(int k = 0; k <= eve; k++)
				{
					if(a[i]==0)
					{
						dp[i][j][k][0]=min(dp[i-1][j][k][1]+1, dp[i-1][j][k][0]);
					}
					else if(a[i]==1)
					{
						dp[i][j][k][1]=min(dp[i-1][j][k][0]+1, dp[i-1][j][k][1]);
					}
					else
					{
						dp[i][j][k][0]=min(dp[i-1][j][k+1][0], dp[i-1][j][k+1][1]+1);
						dp[i][j][k][1]=min(dp[i-1][j+1][k][1], dp[i-1][j+1][k][0]+1);
					}
				}
			}
		}
		cout << min(dp[n][0][0][0], dp[n][0][0][1]);
	}	
}