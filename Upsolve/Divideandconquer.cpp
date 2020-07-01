#include <bits/stdc++.h>

using namespace std;

const int N=5005;
int n, k, h[N], dp[N][2], cnt2[N][N], cnt1[N][N];

int cost(int i, int j)
{
	int ret=cnt2[i][j];
	return ret;
}
void DC(int l, int r, int optl, int optr)
{
	int mid=(l+r)/2, opt1=-1, opt2=-1;
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
			opt1=i;
		}
		if(currans <= dp[mid][1]) opt2=i;
	}
	if(l==r) return;
	if(r-l>1) DC(l, mid-1, optl, opt2);
	DC(mid+1, r, opt1, optr);
}
int main(void) {
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> h[i];
		dp[i][0]=dp[i][1]=1e9;
	}
	for(int i = 1; i <= n; i++)
	{
		cnt1[i][i]=0;
		for(int j = i+1; j <= n; j++)
		{
			cnt1[i][j]=cnt1[i][j-1]+(h[j]>h[i]);
		}
	}
	for(int j = 1; j <= n; j++)
	{
		cnt2[j][j]=0;
		for(int i=j-1; i >= 0; i--)
		{
			cnt2[i][j]=cnt2[i+1][j]+cnt1[i][j];
		}
	}
	dp[0][0]=0;
	for(int i = 1; i <= k; i++)
	{
	//	cout << "k = " << i << endl;
		DC(1, n, 1, n);
		for(int j = 1; j <= n; j++)
		{
	//		cout << dp[j][1] << " ";
			dp[j][0]=dp[j][1];
			dp[j][1]=1e9;
		}
	//	cout << endl;
	}
	cout << dp[n][0];
	return 0;
}