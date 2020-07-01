#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define F first
#define S second

using namespace std;

const int N = 2e3+3;

int n, k, vis[N], excl, currsz=0;
map<int, vector<int> > matroad, matworker;
set<int> matcheck;
vector<int> materials, notbrij;
vector< pii > adj[N];

struct road
{
	int u, v;
	vector<int> m;
} roads[N];

int dfs(int u)
{
	vis[u]=1;
	currsz++;
	for(auto v: adj[u])
	{
		if(!vis[v.F] && v.S!=excl)
		{
			dfs(v.F);
		}
	}
}
signed main()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		adj[a].pb(mp(i, i));
		adj[i].pb(mp(a, i));
		roads[i].u=i, roads[i].v=a;
		int b;
		cin >> b;
		for(int i = 0; i < b; i++)
		{
			int mi;
			cin >> mi;
			if(matcheck.find(mi)==matcheck.end())
			{
				matcheck.insert(mi);
				materials.pb(mi);
			}
			roads[i].m.pb(mi);
			matroad[mi].pb(i);
		}
	}
	for(int i = 1; i <= k; i++)
	{
		int x;
		cin >> x;
		matworker[x].pb(i);
	}
	for(int i = 1; i <= n; i++)
	{
		bool flag=true;
		for(int j = 1; j <= n; j++)
		{
			vis[j]=0;
		}
		excl=i;
		currsz=0;
		dfs(1);
		if(currsz!=n) notbrij.pb(i);
	}
}