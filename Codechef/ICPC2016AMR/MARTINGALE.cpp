#include<bits/stdc++.h>

using namespace std;

const int N=2e6+6, logN=22;
double dp[N][logN];
int n;
double solve(int i, int j)
{
	if(i>=2*n) return 0;
	if(i<=0) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	dp[i][j]=1.0 + 0.5*(solve( i + (1<<j), 0) + solve(i - (1<<j), j+1));
	return dp[i][j];
}
int main()
{
	cout << setprecision(15);
	cin >> n;
	for(int i = 0; i < N; i++) for(int j = 0; j < logN; j++) dp[i][j]=-1;
	cout << solve(n, 0);
}