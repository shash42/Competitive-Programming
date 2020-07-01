#define gc() getchar()

using namespace std;

const int N=4005;
int n, k, dp[N][2];

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
	for(int i = 1; i <= n; i++)
	{
		dp[i][0]=dp[i][1]=1e9;
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