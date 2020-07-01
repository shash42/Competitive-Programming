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
int num, m, cmpcnt, cmpof[N], condejcnt, vis[N]; //cmpcnt = no. of components and condejcnt = number of edges in condensation graph (DAG)
vector< int > adj[N], dfsord, radj[N], cadj[N]; //radj is reversed adjacency list and cadj is condensation graph adjacency list
vector < vector < int > > comps; //reverse toposorted list of components

void dfs1(int u)
{
	vis[u]=true;
	for(auto it: adj[u]) if(!vis[edges[it].v]) dfs1(edges[it].v);
	dfsord.pb(u);
}
void dfs2(int v)
{
	vis[v]=1;
	cmpof[v]=cmpcnt;
	comps[cmpcnt].pb(v);
	for(auto it: radj[v]) if(!vis[edges[it].u])	dfs2(edges[it].u);
}
void resetscc()
{
	cmpcnt=condejcnt=0;
	for(int i = 1; i <= num; i++)
	{
		vis[i]=cmpof[i]=0;
		radj[i].clear();
		cadj[i].clear();
	}
	for(auto cc: comps) cc.clear();
	comps.clear();
	dfsord.clear();
}
void SCC()
{
	resetscc();
	for(int i = 1; i <= num; i++) for(auto it: adj[i])	radj[edges[it].v].pb(i);
	for(int i = 1; i <= num; i++) if(!vis[i]) dfs1(i);
	for(int i = 1; i <= num; i++) vis[i]=0;
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
			cadj[cmpof[edges[i].u]].pb(condejcnt);
			cedges[condejcnt]={cmpof[edges[i].u], cmpof[edges[i].v], edges[i].w};
			condejcnt++;
		}
	}
}
int main()
{
	cin >> num >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
		adj[edges[i].u].pb(i);
	}
	SCC();
	Condense();
}