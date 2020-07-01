#include<bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

const int N=1e5+5;
int n, m, par[N], dp[N], ans;
vector<int> adj[N];

void dfs(int u)
{
	dp[u]=1;
	for(auto v: adj[u])
	{
		if(v==par[u]) continue;
		par[v]=u;
		dfs(v);
		dp[u]*=dp[v]+1;
		dp[u]%=m;
	}
}
signed main()
{
	cin >> n >> m;
	for(int i = 0; i < n-1; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	par[1]=1;
	dfs(1);
	for(int i = 1; i <= n; i++)
	{
		ans+=dp[i];
		ans%=m;
	}
	cout << ans;
}
