#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

const int N=5e5+5;
int n, k, dp[N][2], par[N], parej[N], delta[N];
vector< pii > adj[N];

struct chcomp
{
	bool operator()(const pii &a, const pii &b)
	{
		return delta[a.F] > delta[b.F];
	}
};
void dfs(int u)
{
	dp[u][0]=dp[u][1]=0;
	vector< pii > kids;
	for(auto c: adj[u])
	{
		if(c.F!=par[u])
		{
			int v=c.F;
			par[v]=u;
			parej[v]=c.S;
			dfs(v);
			delta[v]=dp[v][1]+parej[v]-dp[v][0];
			dp[u][0]+=dp[v][0];
			kids.pb(c);
		}
	}
	dp[u][1]=dp[u][0];
	sort(kids.begin(), kids.end(), chcomp());
	int cnt=0, dsum=0;
	for(auto c: kids)
	{	
		cnt++;
		dsum+=delta[c.F];
		if(cnt==k-1)
		{
			dp[u][1]+=dsum;
		}
		else if(cnt==k)
		{
			dp[u][0]+=dsum;
			break;
		}
	}
	if(cnt<k)
	{
		dp[u][0]+=dsum;
	}
	if(cnt < k-1)
	{
		dp[u][1]+=dsum;
	}
	kids.clear();
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q;
	cin >> q;
	while(q--)
	{
		cin >> n >> k;
		for(int i = 0; i < n-1; i++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			adj[u].pb(mp(v, w));
			adj[v].pb(mp(u, w));
		}
		par[1]=0;
		parej[1]=0;
		dfs(1);
		cout << dp[1][0] << endl;
		for(int i = 1; i <= n; i++)
		{
			adj[i].clear();
			dp[i][0]=dp[i][1]=par[i]=parej[i]=delta[i]=0;
		}
	}
}