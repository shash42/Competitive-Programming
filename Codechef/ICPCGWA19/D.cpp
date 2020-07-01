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
int n, m, cmpcnt=0, cmpof[N], condejcnt=0, vis[N], in[N], out[N]; //cmpcnt = no. of components and condejcnt = number of edges in condensation graph (DAG)
vector< int > adj[N], dfsord, radj[N], cadj[N]; //radj is reversed adjacency list and cadj is condensation graph adjacency list
vector < vector < int > > comps;
vector<int> path;
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
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i])
		{
			dfs1(i);
		}
	}
	memset(vis, 0, sizeof(vis));
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
			cadj[cmpof[edges[i].u]].pb(compof[edges[i].v]);
			in[compof[edges[i].v]]++;
			out[compof[edges[i].u]]++;
		}
	}
}
void rest()
{
	path.clear();
	cmpcnt=0;
	for(int i = 1; i <= n; i++)
	{
		in[i]=out[i]=cmpof[i]=0;
		vis[i]=0;
		adj[i].clear(); radj[i].clear(); cadj[i].clear();
	}
	for(auto v: comps)
	{
		comps[v].clear()
	}
	comps.clear();
}
void findpath(int i, int j)
{
	
}
void dfscc(int u)
{
	int nxt=-1;
	if(cadj[u].size()) nxt=cadj[u][0];
	int rt = comps[u][0];
	for(auto ci : comps[u])
	{
		if(!vis[ci])
		{
			findpath(rt, ci);
			findpath(ci, rt);
		}
	}
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		rest();
		cin >> n >> m;
		for(int i = 0; i < m; i++)
		{
			cin >> edges[i].u >> edges[i].v >> edges[i].w;
			adj[u].pb(i);
			radj[v].pb(i);
		}
		SCC();	
		Condense();
		int st=0, en=0, sts=0, ens=0;
		bool flag=true;
		for(int i = 0; i < cmpcnt; i++) //check linear chain
		{
			if(in[i]>1 || out[i]>1)
			{
				flag=false;
				break;
			}
			if(in[i]==0)
			{
				st=i;
				sts++;
			}
			if(out[i]==0)
			{
				en=i;
				ens++;
			}
		}
		if(!flag || sts!=0 || en!=0)
		{
			cout << -1 << endl;
			continue;
		}
		memset(vis, 0, sizeof(vis));
		dfscc(st);
	}
}