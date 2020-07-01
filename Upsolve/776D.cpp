#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define F first
#define S second

using namespace std;

const int N=1e5+5; //change to Number of vars
int num, cmpcnt, cmpof[2*N], vis[2*N]; //cmpcnt = no. of components
vector< int > adj[2*N], dfsord, radj[2*N];//radj is reversed adjacency list

void dfs1(int u)
{
	vis[u]=true;
	for(auto v: adj[u])	if(!vis[v])	dfs1(v);
	dfsord.pb(u);
}
void dfs2(int v)
{
	vis[v]=1;
	cmpof[v]=cmpcnt;
	for(auto u: radj[v]) if(!vis[u]) dfs2(u);
}
void SCC()
{
	for(int i = 0; i < num; i++) if(!vis[i]) dfs1(i);
	for(int i = 0; i < num; i++) vis[i]=0;
	for(auto v: dfsord) {
		if(!vis[v]) {
			cmpcnt++;
			dfs2(v);
		}
	}
}
vector< pii > terms;
bool assn[N]; //stores the final assignment
int NOT(int x) { return x^1; }
int var(int x) { return x<<1; }
bool SAT2(int numvar)
{
	num = 2*numvar;
	for(auto it: terms)
	{
		adj[NOT(it.F)].pb(it.S);
		adj[NOT(it.S)].pb(it.F);
		radj[it.S].pb(NOT(it.F));
		radj[it.F].pb(NOT(it.S));
	}
	SCC();
	for(int i = 0; i < numvar; i++)
	{
		if(cmpof[var(i)] > cmpof[NOT(var(i))]) assn[i]=false;
		else if(cmpof[var(i)] < cmpof[NOT(var(i))]) assn[i]=true;
		else return false;
	}
	return true;
}
int door[N];
pii ds[N];
int main()
{
	int n, numvar;
	cin >> n >> numvar;
	for(int i = 1; i <= n; i++)
	{
		cin >> door[i];
		ds[i]=mp(-1, -1);
	}
	for(int i = 0; i < numvar; i++)
	{
		int x;
		cin >> x;
		for(int j = 0; j < x; j++)
		{
			int y;
			cin >> y;
			if(ds[y].F==-1) ds[y].F=i;
			else ds[y].S=i;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		if(door[i]==0) { terms.pb(mp(var(ds[i].F), var(ds[i].S))); terms.pb(mp(NOT(var(ds[i].F)), NOT(var(ds[i].S)))); }
		else { terms.pb(mp(NOT(var(ds[i].F)), var(ds[i].S))); terms.pb(mp(var(ds[i].F), NOT(var(ds[i].S)))); }
	//	cout << ds[i].F << " " << ds[i].S << endl;
	}
	bool exists = SAT2(numvar); //pass number of variables, returns true if exists
	if(exists) cout << "YES";
	else cout << "NO";
}