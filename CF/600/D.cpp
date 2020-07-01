#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define F first
#define S second

using namespace std;

const int N=2e5+3;

int n, m;
int sz[N], par[N], mx[N], vis[N]; 
vector<int> adj[N];

int findPar(int v)
{
    return par[v] == v ? v : par[v] = findPar(par[v]);
}
 
int doUnion(int u, int v)
{
    int parU = findPar(u), parV = findPar(v);
    if(parU == parV) return parU;
 
    if(sz[parU] < sz[parV])
        par[parU] = parV, sz[parV] += sz[parU], mx[parV] = max(mx[parV], mx[parU]) ;
    else
        par[parV] = parU, sz[parU] += sz[parV], mx[parU] = max(mx[parU], mx[parV]) ;
 
    return par[parU] ;
}

void dfs(int u, int p)
{
	doUnion(p, u);
	vis[u]=true;
	for(auto v: adj[u])
	{
		if(!vis[v])
		{
			dfs(v, p);
		}
	}
}
signed main()
{
	int ans = 0;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for(int i = 1; i <= n; i++)
	{
		par[i]=i;
		sz[i]=1;
		mx[i]=i;
	}
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i])
		{
			dfs(i, i);
		}
	}
	int currnd, currmx=0;
	for(int i = 0; i <= n; i++)
	{
		if(i==currmx)
		{
			currnd=i+1;
			currmx=mx[findPar(currnd)];
			continue;
		}
		if(findPar(i)!=findPar(currnd))
		{
			doUnion(currnd, i);
			currmx=mx[findPar(currnd)];
			ans++;
		}
	}
	cout << ans;
}