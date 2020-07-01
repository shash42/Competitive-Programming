#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

const int N=21, K=18;
int n, k, g, mat[N][N], tot;
ll cliq[N][1<<K], dp[N][1<<K]; //stores for special city i, how much would clique w bits on cities would cost.
ll comp(int u, vector<int> grp)
{
	ll ret=0;
	int l = grp.size();
	for(int i = 0; i < l; i++)
	{
		for(int j = i+1; j < l; j++)
		{
			ret+=mat[grp[i]][grp[j]];
		}
		ret+=mat[u][grp[i]];
	}
	return ret;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		tot = 0;
		cin >> n >> k;
		g = n-k;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				cin >> mat[i][j];
				if(j>i) tot+=mat[i][j];
			}
		}
		for(int i = 0; i < (1<<g); i++)
		{
			for(int j = 0; j < k; j++)
			{
				vector<int> v;
				for(int it = 0; it < g; it++)
				{
					if(i&(1<<it)) v.pb(k+it);
				}
				cliq[j][i]=comp(j, v);
			}
		}
		for(int i = 0; i < (1<<g); i++)
		{
			dp[0][i]=cliq[0][i];
		}
		for(int i = 1; i < k; i++)
		{
			for(int j = 0; j < (1<<g); j++)
			{
				dp[i][j]=cliq[i][j];
				for(int sub = j; sub > 0; sub-=1, sub&=j)
				{
					dp[i][j]=max(dp[i][j], dp[i-1][sub] + cliq[i][j^sub]);
				}
			}
		}
		cout << tot - dp[k-1][(1<<g)-1] << endl;
	}
}