#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define debug(a) cout << a
#define debug(a, b) cout << a << " " << b << endl
#define debug(a, b, c) cout << a << " - " << b << " " << c << endl
#define debug(a, b, c, d) cout << a << " " << b << " - " << c << " " << d << endl
#define debug(a, b, c, d, e) cout << a << " " << b << " - " << c << " " << d << " " << e << endl

using namespace std;
const int N=1e5+5;
int n, m, col[N], cnt[4];

vector<int> adj[N];
vector< pii > edges;
signed main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
		edges.pb(mp(x, y));
	}
	for(int i = 1; i <= n; i++)
	{
		col[i]=1;
	}
	for(auto v: adj[1])
	{
		col[v]=2;
	}
	for(int i = 2; i <= n; i++)
	{
		if(col[i]==2)
		{
			for(auto v: adj[i])
			{
				if(col[v]==2) col[v]=3;
			}
			break;
		}
	}
	for(auto e: edges)
	{
		if(col[e.first]==col[e.second])
		{
			cout << -1;
			return 0;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		cnt[col[i]]++;
	}
	if(cnt[2]==0 || cnt[3]==0)
	{
		cout << -1;
		return 0;
	}
	if(cnt[1]*cnt[2] + cnt[2]*cnt[3] + cnt[1]*cnt[3] != m)
	{
		cout << -1;
		return 0;
	}
	for(int i = 1; i <= n; i++)
	{
		cout << col[i] << " ";
	}
}