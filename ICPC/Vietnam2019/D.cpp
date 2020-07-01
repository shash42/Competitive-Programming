#include<bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

const int N=52, NN=2500, INF=2e18;
vector< string > mat;
vector<int> adj[N];
int val[N], r, c, K, dp[N][N][NN], bestin[N][NN], bestout[N][NN], best[N][2*NN];
bool vis[N][N];

void dfs(int i, int j)
{
	vis[i][j]=true;
	if(mat[i][j]=='X') return;
	if(mat[i][j]=='.')
	{
		if(i!=(r-1) && !vis[i+1][j]) dfs(i+1, j);
		return;
	}
	if(mat[i][j]!='R')
	{
		if(j!=0 && !vis[i][j-1]) dfs(i, j-1);
	}
	if(mat[i][j]!='L')
	{
		if(j!=c-1 && !vis[i][j+1]) dfs(i, j+1);
	}
}
void compadj()
{
	for(int i = 0; i < c; i++)
	{
		for(int j = 0; j < r; j++)
		{
			for(int k = 0; k < c; k++)
			{
				vis[j][k]=false;
			}
		}
		dfs(0, i);
		for(int j = 0; j < c; j++)
		{
			if(vis[r-1][j] && mat[r-1][j]=='.')
			{
				adj[i].pb(j);
			}
		}
	}
}

int cyc(int u, int v, int l)
{
	if(l==0)
	{
		if(u!=v)	return -INF;
		else return 0LL;
	}
	if(dp[u][v][l]!=-INF)
	{
		return dp[u][v][l];
	}
	for(auto cu: adj[u])
	{
		dp[u][v][l]=max(dp[u][v][l], cyc(cu, v, l-1) + val[v]);
	}	
	return dp[u][v][l];
}
signed main()
{
	cin >> r >> c >> K;
	for(int i = 0; i < r; i++)
	{
		string s;
		cin >> s;
		mat.pb(s);
	}
	for(int i = 0; i < c; i++)
	{
		cin >> val[i];
	}
	compadj();
	for(int i = 0; i < c; i++)
	{
		for(int j = 0; j < c; j++)
		{
			for(int k = 0; k < NN; k++)
			{
				dp[i][j][k]=-INF;
			}
		}
	}
	for(int i = 0; i < c; i++)
	{
		for(int j = 0; j < c; j++)
		{
			for(int k = 0; k < NN; k++)
			{
				dp[i][j][k]=cyc(i, j, k);
			}
		}
	}
	for(int len = 0; len < NN; len++)
	{
		for(int i = 0; i < c; i++)
		{
			bestin[i][len]=bestout[i][len]=-INF;
			for(int j = 0; j < c; j++)
			{
				bestout[i][len]=max(bestout[i][len], dp[i][j][len]);
				bestin[i][len]=max(bestin[i][len], dp[j][i][len]);
			}
			best[i][2*len]=best[i][2*len+1]=-INF;
		}
	}
	for(int len1 = 1; len1 < NN; len1++)
	{
		for(int len2 = 0; len2 < NN; len2++)
		{
			for(int i = 0; i < c; i++)
			{
				best[i][len1+len2]=max(best[i][len1+len2], bestin[i][len1] + bestout[i][len2]);
			}
		}
	}
 	int ans = 0LL;
 	for(int stlen = 1; stlen < min((K+1), 2*NN); stlen++)
 	{
 	 	int req = K - stlen;
 		vector<int> J;
 		for(int j = 1; j < N; j++)
 		{
 			if(req%j==0) J.pb(j);
 		}
 		for(int i = 0; i < c; i++)
 		{
 			int curr = best[i][stlen];
 			int curr2 = 0;
 			for(auto j : J)
 			{
 				if(dp[i][i][j]<0LL) continue;
 				curr2=max(curr2, (req/j)*dp[i][i][j]);
 			}
 			curr+=curr2;
 			ans=max(ans, curr);
 		}
 	}
	cout << ans;
}