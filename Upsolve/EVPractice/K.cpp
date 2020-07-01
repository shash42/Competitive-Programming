#include<bits/stdc++.h>

using namespace std;

const int N=102, I=100002;
const double pr = 1e-8;
int n1, n2, m1, m2;
double p;
double dp[I][N];
double solve(int it, int p1)
{
	int p2 = m1 + m2 - p1;
	if(it>=I) return (double) p1/(m1+m2);
	if(p1<0) return 0;
	if(p2<0) return 1;
	if(dp[it][p1]+1>0.5) return dp[it][p1];
	dp[it][p1]=p*solve(it+1, p1-n1) + (1-p)*solve(it+1, p1+n2);
	return dp[it][p1];
}
int main()
{
	cout << setprecision(25);
	for(int i = 0; i < I; i++)
	{
		for(int j = 0; j < N; j++)
		{
			dp[i][j]=-1;
		}
	}
	cin >> n1 >> n2 >> m2 >> m1 >> p;
	p/=100;
	cout << 1-solve(0, m1);
}