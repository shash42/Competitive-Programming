#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=1e5+5+5, K=11, INF=1e18;
int n, k, dp[N][2], w[N], wi[N], wp[N];

int cost(int i, int j)
{
	return (wi[j] - wi[i-1]) - (wp[j]-wp[i-1])*i;
}
void DC(int l, int r, int optl, int optr)
{
	int mid=(l+r)/2, opt=-1;
	int tmpoptl=min(mid, optl);
	int tmpoptr=min(mid, optr); 
	for(int i = tmpoptl; i<=tmpoptr; i++)
	{
		int currans = dp[i-1][0] + cost(i, mid);
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
signed main()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> w[i];
		wp[i]=wp[i-1]+w[i];
		wi[i]=wi[i-1]+w[i]*i;
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
	printf("%lld", dp[n][0]);
}