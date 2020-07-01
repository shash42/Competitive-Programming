#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define F first
#define S second
using namespace std;
const int N=203;
int n=0, m, ans=0;
map<string, int> nodes;
vector<int> adj[N];
void dfs(int u, int x)
{
	ans=max(ans, x);
	for(auto v: adj[u])
	{
		dfs(v, x+1);
	}
}
signed main()
{
	cin >> m;
	string P="polycarp";
	nodes[P]=++n;
	for(int i = 0; i < m; i++)
	{
		string u="", r="", v="";
		cin >> u >> r >> v;
		for(int i = 0; i < u.length(); i++) u[i]=tolower(u[i]);
		for(int i = 0; i < v.length(); i++) v[i]=tolower(v[i]);
		if(nodes.find(u)==nodes.end())
		{
			nodes[u]=++n;
		}
		adj[nodes[v]].pb(nodes[u]);
	}
	dfs(1, 1);
	cout << ans;
}