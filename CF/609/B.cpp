#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;
const int N=3e5+5;
int dp[N][2], n, a[N], tot=0;
signed main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		tot+=a[i];
	}
	dp[0][0]=(a[0]%2==1);
	dp[0][1]=(a[0]%2==0);
	for(int i = 1; i < n; i++)
	{
		if(a[i]%2==1)
		{
			dp[i][0]=min(dp[i-1][1], dp[i-1][0]+1);
			dp[i][1]=min(dp[i-1][0], dp[i-1][1]+1);
		}
		else
		{
			dp[i][0]=min(dp[i-1][0], dp[i-1][1]+1);
			dp[i][1]=min(dp[i-1][1], dp[i-1][0]+1);
		}
		cout << i << " - " << dp[i][0] << " " << dp[i][1] << endl;
	}
	//cout << dp[n-1][0] << endl;
	//cout << tot << endl;
	assert((tot-dp[n-1][0])%2==0);
	cout << (tot - dp[n-1][0])/2;
}