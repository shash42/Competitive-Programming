#include<bits/stdc++.h>
#define pii pair<int, int>
#define ppii pair<int, pii >
#define mp make_pair
#define pb push_back
#define F first
#define S second

using namespace std;

const int N=1e5+5;
const double pr = 1e-8;

priority_queue< ppii, vector < ppii >, greater < ppii > > pq;
int n, m, cost[N];
vector< pii > adj[N];
vector<int> adj2[N], adj3[N], topo;
bool vis[N];
long double dpo[N], dpi[N];
int main()
{
	cout << setprecision(10);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) dpo[i]=dpi[i]=0;
	for(int i = 0; i < m; i++)
	{
		int a, b, l;
		cin >> a >> b >> l;
		adj[a].pb(mp(b, l));
		adj[b].pb(mp(a, l));
	}
	pq.push(mp(0, mp(1, 0)));
	while(pq.size())
	{
		while(pq.size() && vis[pq.top().S.F])
		{
			if(cost[pq.top().S.F]==pq.top().F) adj2[pq.top().S.F].pb(pq.top().S.S), adj3[pq.top().S.S].pb(pq.top().S.F);
			pq.pop();
		}
		if(!pq.size()) break;
		int u = pq.top().S.F, p = pq.top().S.S, dist = pq.top().F;
	//	cout << u << " " << p << " " << dist << endl;
		cost[u]=dist;
		vis[u]=true;
		topo.pb(u);
		pq.pop();
		adj2[u].pb(p); adj3[p].pb(u);
		for(auto v: adj[u])
		{
			if(!vis[v.F])
			{
				pq.push(mp(dist+v.S, mp(v.F, u)));
			}
		}
	}
	dpi[1]=1;
	for(auto u: topo)
	{
		for(auto v: adj3[u])
		{
			dpi[v]+=dpi[u];
			if(dpi[v]<0) return 7;
		}
	}
	reverse(topo.begin(), topo.end());
	dpo[n]=1;
	for(auto u: topo)
	{
		for(auto v: adj2[u])
		{
			dpo[v]+=dpo[u];
			if(dpo[v]<0) return 7;
		}
	}
//	if(dp[1]*2-2.0>pr) return 7;
	for(int i = 1; i <= n; i++)
	{
		cout << 2*(((double)dpi[i]* dpo[i])/ (double) dpo[1]) << " ";
	}
}