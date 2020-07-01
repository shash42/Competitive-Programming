#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=505, INF=1e18;

int n, s1, s2, dp[2][N][N];

struct quest
{
	int x1, t1, y1, r1;
} arr[N];

struct qsrt
{
	bool operator()(const quest &a, const quest &b)
	{
		return a.x1 < b.x1;
	}
};

int recurse(int idx, int l1, int l2)
{
	//printf("%lld\n", idx);
	//cout << idx << " - " << l1 << " " << l2 << endl;
	l2=min(l2, s2);
	if(idx==n+1) return dp[idx][l1][l2];
	if(dp[idx][l1][l2]<INF) return dp[idx][l1][l2];
	int takel1, takel2, donttake = recurse(idx+1, l1, l2);
	dp[idx][l1][l2]=min(dp[idx][l1][l2], donttake);
	if(arr[idx].x1 + l1 > s1)
	{
		takel1 = recurse(idx+1, s1, l2 + arr[idx].x1 + l1 - s1) + arr[idx].t1;
	}
	else
	{
		takel1 = recurse(idx+1, l1+arr[idx].x1, l2) + arr[idx].t1;
	}
	dp[idx][l1][l2]=min(dp[idx][l1][l2], takel1);
	takel2 = recurse(idx+1, l1, l2+arr[idx].y1) + arr[idx].r1;
	dp[idx][l1][l2]=min(dp[idx][l1][l2], takel2);
	return dp[idx][l1][l2];
}
signed main()
{
	cin >> n >> s1 >> s2;
	for(int i = 1; i <= n+1; i++)
	{
		if(i<=n) cin >> arr[i].x1 >> arr[i].t1 >> arr[i].y1 >> arr[i].r1;
		for(int j = 0; j <= s1; j++)
		{
			for(int k = 0; k <= s2; k++)
			{
				dp[i%2][j][k]=INF;
			}
		}
	//	cout << i << endl;
	}
	sort(arr+1, arr+n+1, qsrt());
	dp[(n+1)%2][s1][s2]=0;
	for(int idx = n; idx >= 1; idx--)
	{
		//cout << idx << endl;
		for(int l1 = 0; l1 <= s1; l1++)
		{
			for(int l2 = 0; l2 <= s2; l2++)
			{
				dp[idx%2][l1][l2]=INF;
				int takel1 = INF , takel2 = INF , donttake = dp[(idx+1)%2][l1][l2];
				dp[idx%2][l1][l2]=min(dp[idx%2][l1][l2], donttake);
				if(l1 < s1)
				{

					if(arr[idx].x1 + l1 >= s1)
					{
						takel1 = dp[(idx+1)%2][s1][min(s2, l2 + arr[idx].x1 + l1 - s1)] + arr[idx].t1;
					}
					else
					{
						takel1 = dp[(idx+1)%2][l1+arr[idx].x1][l2] + arr[idx].t1;
					}	
				dp[idx%2][l1][l2]=min(dp[idx%2][l1][l2], takel1);

				}
				// dp[idx%2][l1][l2]=min(dp[idx%2][l1][l2], takel1);
				takel2 = dp[(idx+1)%2][l1][min(s2, l2+arr[idx].y1)] + arr[idx].r1;
				dp[idx%2][l1][l2]=min(dp[idx%2][l1][l2], takel2);
				// cout << idx << " " << l1 << " " << l2 << " : " << donttake << " : " << takel1 << " : " << takel2 << endl ; 
			}
		}	
	}
	//int ans = recurse(1, 0, 0);
	int ans = dp[1][0][0];
	if(ans>=INF) cout << -1;
	else cout << ans;
}