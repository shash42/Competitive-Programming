#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second

using namespace std;

const int N=1e5+5;
struct ej
{
	int x, int y;
};
ej edges[N];
map<int, vector< pii >> adj;

void dfs(int u)
{
	vis[u]=1;
	for(auto v: adj[u])
	{
		
	}
}
signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			int x, y;
			cin >> x >> y;
			edges[i]={x, y};
			adj[x].pb(mp(y, i));
			adj[y].pb(mp(x, i));
		}
		for(auto u: adj)
		{
			if(!vis[u.F])
			{
				dfs(u.F);
			}
		}
	}	
}