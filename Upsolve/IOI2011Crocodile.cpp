#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

const int N=1e5+5, M=1e6+6, INF=1e18, MAXX=1e14+14;
int n, m, k, escs[N], vis[N], blocked[N], dist[N];
vector< pii > adj[N];
struct compr
{
	bool operator()(const pii &a, const pii &b)
	{
		return a.F > b.F;
	}
};
priority_queue< pii, vector< pii >, compr > pq;
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
	{
		dist[i]=INF;
	}
	for(int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].pb(mp(v, w));
		adj[v].pb(mp(u, w));
	}
	for(int i = 0; i < k; i++)
	{
		cin >> escs[i];
		pq.push(mp(0, escs[i]));
		blocked[escs[i]]=1;
	}
	while(pq.size())
	{
		if(vis[pq.top().S])
		{
			pq.pop();
			continue;
		}
		if(!blocked[pq.top().S])
		{
			blocked[pq.top().S]=1;
			pq.pop();
			continue;
		}
		int u=pq.top().S;
		dist[u]=pq.top().F;
	//	cout << u << " " << dist[u] << endl;
		pq.pop();
		vis[u]=1;
		for(auto v: adj[u])
		{
			if(!vis[v.F])
			{
				pq.push(mp(v.S+dist[u], v.F));
			}
		}
	}
	if(dist[0]>MAXX) dist[0]=-1;
	cout << dist[0];
}