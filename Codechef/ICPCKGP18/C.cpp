#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define F first
#define S second
#define lint long long
#define int long long
#define mp make_pair
#define pii pair<int, int>
#define pll pair<lint, lint>
#define ld long double
#define inlld(x) scanf("%lld", &x)
#define ind(x) scanf("%d", &x)
#define vi vector<int>

const int N=1e5+5;
const int MOD=1e9+7;
const lint INF=1e18;

using namespace std;
using namespace __gnu_pbds;

template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct edge
{
	int u, v, w, val;
} edges[2*N];
bool canuse[2*N];
vi adj[N];
int n, m, s, t, k, mask=0, ans=INF, dist[N];
priority_queue< pii, vector < pii >, greater < pii > > pq;
void resetdij()
{
	while(pq.size()) pq.pop();
	for(int i = 1; i <= n; i++) dist[i]=INF;
}
void dijkstra()
{
	pq.push(mp(0, s));
	while(pq.size())
	{
		if(dist[pq.top().S]!=INF)
		{
			pq.pop();
			continue;
		}
		int u = pq.top().S;
		dist[u]=pq.top().F;
		pq.pop();
		if(u==t)
		{
	//		cout << dist[u];
			ans=min(dist[u], ans);
			return;
		}
		for(auto it: adj[u])
		{
			if(!canuse[it]) continue;
			pq.push(mp(dist[u]+edges[it].w, edges[it].v));
		}
	}
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> edges[2*i].u >> edges[2*i].v >> edges[2*i].w >> edges[2*i].val;
		edges[2*i+1]=edges[2*i];
		swap(edges[2*i+1].u, edges[2*i+1].v);
		adj[edges[2*i].u].pb(2*i);
		adj[edges[2*i].v].pb(2*i+1);
	}
	cin >> s >> t >> k;
	for(int i = 30; i >= 0; i--)
	{
		int pow=(1<<i);
		if(k&pow)
		{
			mask+=pow;
			continue;
		}
		for(int j = 0; j < 2*m; j++)
		{
			if((edges[j].val & (mask+pow)) == mask+pow) canuse[j]=true;
			else canuse[j]=false;
		}
	//	cout << i << " ";
		resetdij();
		dijkstra();
	//	cout << endl;
	}
	for(int i = 0; i < 2*m; i++)
	{
		if((edges[i].val & mask)==mask) canuse[i]=true;
		else canuse[i]=false;
	}
	resetdij();
	dijkstra();
	if(ans==INF)
	{
		cout << -1;
	}
	else
	{
		cout << ans;
	}
}