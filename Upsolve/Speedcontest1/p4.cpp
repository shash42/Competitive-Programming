#include<bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define F first
#define S second
using namespace std;

const int N=3e5+5;
int vis[N], n, k, d, edges[N], dist[N], ans;

vector < pii > adj[N];
vector<int> ansej;
queue<int> q;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k >> d;
	ans=n-1;
	for(int i = 0; i < k; i++)
	{
		int x;
		cin >> x;
		q.push(x);
		vis[x]=1;
		dist[x]=0;
	}
	for(int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].pb({v, i});
		adj[v].pb({u, i});
	}
	while(q.size())
	{
		int u = q.front();
		if(dist[u]==d)
		{
			q.pop();
			continue;
		}
		for(auto v: adj[u])
		{
			if(!vis[v.F])
			{
				vis[v.F]=1;
				q.push(v.F);
				edges[v.S]=1;
				dist[v.F]=dist[u]+1;
			}
		}
		q.pop();
	}
	for(int i = 1; i < n; i++)
	{
		ans-=edges[i];
		if(edges[i]==0) ansej.pb(i);
	}
	cout << ans << endl;
	for(auto x: ansej)
	{
		cout << x << " ";
	}
}