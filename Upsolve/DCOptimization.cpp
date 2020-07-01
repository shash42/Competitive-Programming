#include<bits/stdc++.h>
#define lint long long

using namespace std;

const lint N=1e5+5, INF=1e18;
lint dp[N][2];

lint cost(int i, int j) //cost from index i to j (1-indexed)
{
}
void DC(int l, int r, int optl, int optr)
{
	int mid=(l+r)/2, opt=-1;
	int tmpoptl=min(mid, optl); int tmpoptr=min(mid, optr); 
	for(int i = tmpoptl; i<=tmpoptr; i++)
	{
		lint currans = dp[i-1][0] + cost(i, mid);
		if(currans < dp[mid][1] )
		{
			dp[mid][1]=currans;
			opt=i;
		}
	}
	if(l==r) return;
	if(r-l>1) DC(l, mid-1, optl, opt);
	DC(mid+1, r, opt, optr);
}
lint solveDC(int n, int k, lint dp[N][2])
{
	for(int i = 1; i <= n; i++)
	{
		dp[i][0]=dp[i][1]=INF;
	}
	dp[0][0]=0;
	for(int i = 1; i <= k; i++)
	{
		DC(1, n, 1, n);
		for(int j = 1; j <= n; j++)
		{
			dp[j][0]=dp[j][1];
			dp[j][1]=INF;
		}
	}
	return dp[n][0];
}
