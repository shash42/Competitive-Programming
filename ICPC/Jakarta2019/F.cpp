#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define F first
#define S second

using namespace std;

const int N = 4e3+3;

int n, subt[N], par[N], cand[N], forests[N], mrk;
vector<int> adj[N];

void dfs1(int u)
{
	subt[u]=1;
	for(auto v: adj[u])
	{
		if(v!=par[u])
		{
			par[v]=u;
			dfs1(v);
			subt[u]+=subt[v];
		}
	}
	int chk=n-subt[u];
	cand[u]=-1;
	for(auto v: adj[u])
	{
		if(v!=par[u])
		{
			if(cand[u]==-1) cand[u]=1;
			if(subt[v]!=chk) cand[u]=0;
		}
	}
	if(cand[u]==-1) cand[u]=0;
	if(cand[u])
	{
		forests[u]=adj[u].size();
	}
}
signed main()
{
	cin >> n;
	for(int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(i);
	}
	dfs1(1);
	for(int i = 1; i <= n; i++)
	{
		if(cand[i]!=1) continue;
		mrk=i;
		mp1=
	}
}