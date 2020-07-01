#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define F first
#define S second

using namespace std;

const int N=1e5+5, M=1e6+6;
struct edge
{
	int u, v, w;
} edges[M], cedges[M]; //edges of normal and condensation graph
int n, m, cmpcnt=0, cmpof[N], condejcnt=0, vis[N]; //cmpcnt = no. of components and condejcnt = number of edges in condensation graph (DAG)
vector< int > adj[N], dfsord, radj[N], cadj[N]; //radj is reversed adjacency list and cadj is condensation graph adjacency list
vector < vector < int > > comps;

void dfs1(int u)
{
	vis[u]=true;
	for(auto it: adj[u])
	{
		if(!vis[edges[it].v])
		{
			dfs1(edges[it].v);
		}
	}	
	dfsord.pb(u);
}
void dfs2(int v)
{
	vis[v]=1;
	cmpof[v]=cmpcnt;
	comps[cmpcnt].pb(v);
	for(auto it: radj[v])
	{
		if(!vis[edges[it].u])
		{
			dfs2(edges[it].u);
		}
	}
}
void SCC()
{
	memset(vis, 0, n+1);
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i])
		{
			dfs1(i);
		}
	}
	memset(vis, 0, n+1);
	vector<int> tmp;
	comps.pb(tmp);
	for(auto v: dfsord)
	{
		if(!vis[v])
		{
			cmpcnt++;
			comps.pb(tmp);
			dfs2(v);
		}
	}
}
void Condense()
{
	for(int i = 0; i < m; i++)
	{
		if(cmpof[edges[i].u]!=cmpof[edges[i].v])
		{
			out[cmpof[edges[i].u]]++;
			cadj[cmpof[edges[i].u]].pb(condejcnt);
			cedges[condejcnt]={cmpof[edges[i].u], cmpof[edges[i].v], edges[i].w};
			condejcnt++;
		}
	}
}
void treset()
{
	for(int i = 1; i <= n; i++)
	{
		adj[i].clear();
		radj[i].clear();
		cmpof[i]=0;
	}
	dfsord.clear();
	for(int i = 0; i <= cmpcnt; i++)
	{
		cadj[i].clear();
		comps[i].clear();
	}
	comps.clear();
	cmpcnt=0;
	condejcnt=0;

}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		for(int i = 0; i < m; i++)
		{
			cin >> edges[i].v >> edges[i].u;
			adj[edges[i].u].pb(i);
			radj[edges[i].v].pb(i);
		}
		SCC();
		Condense();
		treset();
	}
}