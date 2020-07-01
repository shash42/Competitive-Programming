#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int N=1e5+5;
int n, vis[N], ans, cnt, x, y;
vector<int> pts[N], ony[N];
vector<int> adj[N];
set<int> ys;
void dfs(int u)
{
	vis[u]=1;
	cnt++;
	for(auto p: pts[u])
	{
		ys.insert(p);
	}
	for(auto v: adj[u])
	{
		if(!vis[v])
		{
			dfs(v);
		}
	}
}
signed main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> x >> y;
		ony[y].pb(x);
		pts[x].pb(y);
	}
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < (int) ony[i].size()-1; j++)
		{
			adj[ony[i][j]].pb(ony[i][j+1]);
			adj[ony[i][j+1]].pb(ony[i][j]);
		}
	}
	for(int i = 0; i < N; i++)
	{
		if(!vis[i]) dfs(i);
		ans+=ys.size()*cnt;
		ys.clear();
		cnt=0;
	}
	cout << ans-n;
}v 