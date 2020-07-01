#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define F first
#define S second
using namespace std;
const int N=2e5+5;
int n=0, m, col[N], vis[N];
vector<int> adj[N];
pii edges[N];
bool flag=true;
string ans="";
void dfs(int u, int x)
{
	col[u]=x;
	vis[u]=1;
	for(auto v: adj[u])
	{
		if(vis[v])
		{
			if(col[v]==x)
			{
				flag=false;
			}
		}
		else
		{
			dfs(v, 1-x);
		}
	}
}
signed main()
{
	memset(col, -1, N);
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> edges[i].F >> edges[i].S;
		adj[edges[i].F].pb(edges[i].S);
		adj[edges[i].S].pb(edges[i].F);
	}
	dfs(1, 0);
	if(!flag)
	{
		cout << "NO";
		return 0;
	}
	for(int i = 0; i < m; i++)
	{
		ans+=('0' + (col[edges[i].F]==1));
	}
	cout << "YES\n";
	cout << ans;
}