#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;
using namespace __gnu_pbds;

template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N=5e5+5;
int n, ej;
pii segs[N];
set< pii > rpts;
vector<int> adj[N];
bool vis[N];
bool flag;
bool dfs(int u, int p)
{
	vis[u]=true;
	flag=true;
	for(auto v: adj[u])
	{
		if(v==p) continue;
		if(vis[v])
		{
			return false;
		}
		else
		{
			flag=dfs(v, u);
		}
	}
	return flag;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> segs[i].F >> segs[i].S;
	}	
	sort(segs, segs+n);
	rpts.insert(mp(segs[0].S, 0));
	for(int i = 1; i < n; i++)
	{
		//cout << i << endl;
		auto it=rpts.upper_bound(mp(segs[i].F, 0));
		auto r = rpts.upper_bound(mp(segs[i].S, 0));
		if(r==it)
		{
			rpts.insert(mp(segs[i].S, i));
			continue;
		}
		r--;
	//	cout << i << " - " << (*it).S << " " << (*r).S << endl;
		while(it!=r)
		{
			adj[(*it).S].pb(i);
			adj[i].pb((*it).S);
	//		cout << (*it).S << " " << i << endl;
			it++;
			ej++;
		}
		adj[(*r).S].pb(i);
		adj[i].pb((*r).S);
	//	cout << (*r).S << " " << i << endl;
		ej++;
		if(ej>=n)
		{
			cout << "NO";
			return 0;
		}
		rpts.insert(mp(segs[i].S, i));
	}
	if(ej!=n-1) 
	{
		cout << "NO";
		return 0;
	}
	bool ans = true;
	for(int i = 0; i < n; i++) if(!vis[i]) ans &= dfs(i, i);
	if(ans)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}