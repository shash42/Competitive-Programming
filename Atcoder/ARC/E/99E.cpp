#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second

using namespace std;

const int N = 702;
int n, m, vis[N], cnt[N][3], cmpcnt, dp[N][N], mat[N][N], mn=1e6;
vector<int> g[N];
bool ret=true;
void dfs(int u, int col)
{
	//cout << u << " - " << col << endl;
	cnt[cmpcnt][col]++;
	vis[u]=col;
	for(auto v: g[u])
	{
		if(vis[v]==col)
		{
		//	cout << v << endl;
			ret=false;
		}
		else if(!vis[v]) dfs(v, 3-col);
	}
}
int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		mat[x][y]=mat[y][x]=1;
	}	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(!mat[i][j] && i!=j) g[i].pb(j);
		}
	}
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i])
		{	
			cmpcnt++;
			cnt[cmpcnt][1]=0;
			cnt[cmpcnt][2]=0;
			dfs(i, 1);
		}
	}
	if(!ret)
	{
		cout << -1;
		return 0;
	}
	dp[0][0]=1;
	for(int i = 1; i <= cmpcnt; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			dp[i][j]|=dp[i-1][j-cnt[i][1]];
			dp[i][j]|=dp[i-1][j-cnt[i][2]];
		}
	}
	for(int i = 1; i <= n; i++)
	{
		if(dp[cmpcnt][i])
		{
			int curr = (i*(i-1))/2 + ((n-i)*(n-i-1))/2;
			mn = min(mn, curr);
		}
	}	
	cout << mn;
}