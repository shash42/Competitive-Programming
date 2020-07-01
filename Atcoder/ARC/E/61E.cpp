#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

const int N=1e5+5;
int n, m, dist[N];

struct djknd
{
	int w, u, c;
};
struct djsrt
{
	bool operator()(const djknd &a, const djknd &b)
	{
		if(a.w==b.w) return a.u > b.u;
		return a.w > b.w;
	}
};
priority_queue< djknd, vector < djknd >, djsrt> pq;
set<int> opr8r[N];
bool vis[N];
map<int, vector<int> > adjm[N];
vector< pii > adj[N];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) dist[i]=1e9;
	for(int i = 0 ; i < m; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].pb(mp(v, c));
		adj[v].pb(mp(u, c));
		adjm[u][c].pb(v);
		adjm[v][c].pb(u);
	}
	pq.push({0, 1, 0});
	dist[1]=0;
	while(pq.size())
	{
		if(dist[pq.top().u]!=pq.top().w || opr8r[pq.top().u].find(pq.top().c)!=opr8r[pq.top().u].end())
		{
			pq.pop();
			continue;
		}
		djknd curr = pq.top();
		pq.pop();
		if(curr.u==n)
		{
			cout << curr.w;
			return 0;
		}
		if(!vis[curr.u])
		{
			for(auto V: adj[curr.u])
			{
				dist[V.F]=min(dist[V.F], curr.w+1);
				pq.push({curr.w+1, V.F, V.S});
			}
			vis[curr.u]=true;
		}
		opr8r[curr.u].insert(curr.c);
		for(auto V: adjm[curr.u][curr.c])
		{
			if(opr8r[V].find(curr.c)==opr8r[V].end() && curr.w<=dist[V])	pq.push({curr.w, V, curr.c});
			dist[V]=min(dist[V], curr.w);
		}
	}
	cout << -1;
}