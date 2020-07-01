#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define pii pair<int, int>
#define pb push_back
#define mp make_pair

using namespace std;
const int N=1e5+5;

int n, col[N], c[4][N], par[N], mn=1e18, root, c1, c2, cost=0;
int perms[6][3] = { {1, 2, 3}, {1, 3, 2}, {2, 1 , 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
vector<int> adj[N];

void dfs(int u, int cp, int cpp)
{
	for(int i = 1; i <= 3; i++)
	{
		if(i!=cp && i!=cpp)
		{
			col[u]=i;
			cost+=c[i][u];
		}
	}
	for(auto v: adj[u])
	{
		if(v!=par[u])
		{
			par[v]=u;
			dfs(v, col[u], cp);
		}
	}
}
void build(int i)
{
	for(int j = 1; j <= n; j++) col[j]=0;
	cost=0;
	col[root]=perms[i][0];
	col[c1]=perms[i][1];
	col[c2]=perms[i][2];
	cost += c[col[root]][root] + c[col[c1]][c1] + c[col[c2]][c2];
	for(auto v: adj[c1])
	{
		if(v!=root)
		{
			par[v]=c1;
			dfs(v, col[c1], col[root]);
		}
	}
	for(auto v: adj[c2])
	{
		if(v!=root)
		{
			par[v]=c2;
			dfs(v, col[c2], col[root]);
		}
	}
}
signed main()
{
	cin >> n;
	for(int i = 1; i < 4; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cin >> c[i][j];
		}
	}
	for(int i = 0; i < n-1; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for(int i = 1; i <= n; i++)
	{
		if(adj[i].size()==2)
		{
			root=i;
			break;
		}
	}
	bool flag=true;
	for(int i = 1; i <= n; i++)
	{
		if(adj[i].size()>2)
		{
//			cout << i << endl;
			flag=false;
			break;
		}
	}
	if(!flag)
	{
		cout << -1;
		return 0;
	}
	c1=adj[root][0], c2=adj[root][1];
	par[c1]=root; par[c2]=root;
	int ansind=-1;
	for(int i = 0; i < 6; i++)
	{
		build(i);	
		if(cost<mn)
		{
			mn=cost;
			ansind=i;
		}
	}
	build(ansind);
	cout << mn << endl;
	for(int i = 1; i <= n; i++)
	{
		cout << col[i] << " ";
	}
}