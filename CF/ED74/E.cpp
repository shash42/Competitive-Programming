#include<bits/stdc++.h>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;

const int N=3e5+5;
int par[N], sz[N], in[N], in2[N], out[N], bc[N];
vector<int> adj[N];
void dfs(int u)
{
	sz[u]=1;
	for(auto v: adj[u])
	{
		if(v!=par[u])
		{
			par[v]=u;
			dfs(v);
			sz[u]+=sz[v];
			if(in[v]>in[u])
			{
				in2[u]=in[u];
				bc[u]=v;
				in[u]=in[v];
			}
			else if(in[v]>in2[u])
			{
				in2[u]=in[v];
			}
		}
	}
	in[u]+=adj[u].size();
	in2[u]+=adj[u].size();
	if(u!=1)
	{
		in[u]--; in2[u]--;
	}
}
void dfs2(int u)
{	
	int parl=adj[par[u]].size()-1;
	if(par[u]>1) parl--;
	if(bc[par[u]]==u) out[u]=max(out[par[u]]+parl, in2[par[u]] + (par[u]>1));
	else out[u]=max(out[par[u]]+parl, in[par[u]] + (par[u]>1));
	for(auto v: adj[u])
	{
		if(v!=par[u])
		{
			dfs2(v);
		}
	}
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q;
	cin >> q;
	while(q--)
	{
		int n, mx=0;
		cin >> n;
		for(int i = 0; i < n-1; i++)
		{
			int x, y;
			cin >> x >> y;
			adj[x].pb(y);
			adj[y].pb(x);
		}
		out[0]=in[0]=in2[0]=0;
		dfs(1);
		dfs2(1);
		for(int u = 1; u <= n; u++)
		{
		//	cout << u << " - " << in[u] << " " << in2[u] << " " << out[u] << endl;
			vector<int> v1;
			v1.pb(0); v1.pb(0);
			v1.pb(out[u]);
			for(auto v: adj[u])
			{
				if(v!=par[u]) v1.pb(in[v]);
			}
			sort(v1.begin(), v1.end());
			int l=adj[u].size();
			if(u!=1) l--;
			mx=max(mx, v1[v1.size()-1]+v1[v1.size()-2]+l);
		//	cout << mx << endl;
			v1.clear();
		}
		for(int i = 1; i <= n; i++)
		{
			par[i]=sz[i]=in[i]=in2[i]=out[i]=0;
			adj[i].clear();
		}
		cout << mx+1 << endl;
	}
}