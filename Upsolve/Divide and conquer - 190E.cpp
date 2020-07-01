#include <bits/stdc++.h>
#define gc() getchar()

using namespace std;

const int N=4005;
int n, k, c[N][N], dp[N][2], p[N][N];
int cost(int i, int j)
{
	return (p[j][j]-p[i-1][j]-p[j][i-1]+p[i-1][i-1])/2;
}
void DC(int l, int r, int optl, int optr)
{
	int mid=(l+r)/2, opt=-1;
	int tmpoptl=min(mid, optl);
	int tmpoptr=min(mid, optr);
//	cout << mid << "pe: - " << tmpoptl << " " << tmpoptr << endl; 
	for(int i = tmpoptl; i<=tmpoptr; i++)
	{
		int currans = dp[i-1][0] + cost(i, mid);
		if(currans < dp[mid][1] )
		{
			dp[mid][1]=currans;
			//cout << mid << " " << i << " - " << currans << endl;
			opt=i;
		}
	}
	if(l==r) return;
	if(r-l>1) DC(l, mid-1, optl, opt);
	DC(mid+1, r, opt, optr);
}
inline void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
signed main()
{
	scanint(n);
	scanint(k);
	for(int i = 1; i <= n; i++)
	{
		dp[i][0]=dp[i][1]=1e9;
		for(int j = 1; j <= n; j++)
		{
			scanint(c[i][j]);
		}
	}
	for(int i = 0; i <= n; i++)
	{
		p[i][0]=p[0][i]=0;
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+c[i][j];
		}
	}
	dp[0][0]=0;
	for(int i = 1; i <= k; i++)
	{
		//cout << "k = " << i << endl;
		DC(1, n, 1, n);
		for(int j = 1; j <= n; j++)
		{
		//	cout << dp[j][1] << " ";
			dp[j][0]=dp[j][1];
			dp[j][1]=1e9;
		}
		//cout << endl;
	}
	printf("%d", dp[n][0]);
}