#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define f first
#define lint long long
#define mp make_pair
#define pii pair<int, int>
#define pll pair<lint, lint>
#define ld long double
#define inlld(x) scanf("%lld", &x)
#define ind(x) scanf("%d", &x)
#define vi vector<int>

const int N=2e5+5;
const int MOD=1e9+7;
const lint INF=1e18;


using namespace std;
using namespace __gnu_pbds;

lint one = 1, zero = 0 ; 


lint _add(lint &x, lint y)
{
	x += y ; x %= MOD ;
	if(x < zero) x += MOD ; 
}

lint _mult(lint &x, lint y)
{
	x %= MOD ; y %= MOD ;
	x *= y ; x %= MOD ; 
	// while(x < zero) x += MOD ; 
}

lint modpow(lint x, lint y)
{
	lint res = 1 ; 
	while(y)
	{
		if(y & one) _mult(res, x) ;
		_mult(x, x);
		y >>= one ; 
	}
	return res ; 
}

int n = N-1 , q;
vi adj[N] ;
int depth[N] ; int par[N] ;
lint pwr[N], inverse[N] ;
int tin[N], tout[N] ;
int timer = 0 ;

void dfs(int v, int p, int height) {
	tin[v] = ++timer ;
	depth[v] = height ;
	par[v] = p ; 
	for(int u : adj[v])
		if(u != p)
			dfs(u, v, height + 1);
	tout[v] = timer ;
	// cout << v << " : " << p << endl ; 
}

void pre()
{
	pwr[0] = 1 ; inverse[0] = modpow(1, MOD - 2);
	for(int i = 1; i < N; i++)
	{
		pwr[i] = pwr[i-1] ; inverse[i] = 1;
		_mult(pwr[i], 2);
		inverse[i] = modpow(pwr[i], MOD - 2); 
		// if(i < 60)
			// cout << i << " : " << pwr[i] << " : " << inverse[i] << endl ; 
	}
}

lint t[N*4] ;
int st[N*4] ;

void push(int v, int i, int j)
{
	if(i != j)
	{
		_add(t[v*2], t[v]);
		_add(t[v*2 + 1], t[v]); 
		t[v] = 0 ; 
	}
}

void update(int v, int i, int j, int l, int r, lint val)
{
	if(t[v]) push(v, i, j);
	if(i > r or j < l) return ;
	if(i >= l and j <= r)
	{
		_add(t[v], val) ;
		return ; 
	}
	int mid = i+j >> 1;
	update(v*2, i, mid, l, r, val); update(v*2 + 1, mid + 1, j, l, r, val);
}

lint query(int v, int i, int j, int l)
{
	if(t[v]) push(v, i, j);
	if(i == j and j == l) return t[v] ;
	int mid = i+j >> 1 ;
	if(l <= mid) return query(v*2, i, mid, l);
	else return query(v*2 + 1, mid + 1, j, l); 
}




void push2(int v, int i, int j)
{
	if(i != j)
	{
		 st[v*2] = max(st[v*2],  st[v]);
		 st[v*2 + 1] = max(st[v*2 + 1], st[v]); 
		 st[v] = 0 ; 
	}
}

void update2(int v, int i, int j, int l, int r, int val)
{
	if(st[v]) push2(v, i, j);
	if(i > r or j < l) return ;
	if(i >= l and j <= r)
	{
		st[v] = max(st[v], val);
		return ; 
	}
	int mid = i+j >> 1;
	update2(v*2, i, mid, l, r, val); update2(v*2 + 1, mid + 1, j, l, r, val);
}

int query2(int v, int i, int j, int l)
{
	if(st[v]) push2(v, i, j);
	if(i == j and j == l) return st[v] ;
	int mid = i+j >> 1 ;
	if(l <= mid) return query2(v*2, i, mid, l);
	else return query2(v*2 + 1, mid + 1, j, l); 
}



int mx = 1e9 ; 

void upd(int x, int y)
{
	update(1, 1, n, timeMin[v][0], timeMax[v][0], pwr[y]);
	for(int k = 1; k <= y; k++)
	{
		if(timeMax[x][k] != 0 and timeMin[x][k] != mx)
			update(1, 1, n, timeMin[x][k], timeMax[x][k], pwr[y - k]);
	}
	// lint here = pwr[y + depth[x]] ; 
	// update(1, 1, n, tin[x], tout[x], here); 
	// update2(1, 1, n, tin[x], tout[x], y + depth[x]);
	
	/// cout << x << " : " << tin[x] << " : " << tout[x] << endl ;
	// cout << x << " : " << here << endl ; 

	int p = par[x] ;
	while(p != -1)
	{
		lint here = pwr[--y] ; 
		// _mult(here, pwr[depth[p]]);
		
		update(1, 1, n, timeMin[p][0], timeMax[p][0], here);
		// update2(1, 1, n, tin[p], tout[p], y + depth[p]);
		p = par[p] ;
		if(y <= 0) break ; 
	}

}

void cleanTree(int v, int i, int j)
{
	t[v] = 0 ; st[v] = 0 ; 
	if(i == j) return ;
	int mid = i+j >> 1;
	cleanTree(v*2, i, mid); cleanTree(v*2 + 1, mid + 1, j); 
}

int timeMax[N][61], timeMin[N][61] ;
int visited[N] ;

void bfs(int v)
{
	int u = v ;
	queue < int > q ;
	q.push(u); timer = 0 ; 
	visited[u] = 1 ;
	while(!q.empty())
	{
		u = q.top(); q.pop();
		timeMax[u][0] = timeMin[u][0] = ++timer ;
		for(int p : adj[u]) 
			if(!visited[p])
				visited[p] = 1, q.push(p) ;
	}	
}

void dfs2(int v)
{
	for(int u : adj[v]) 
		if(u != par[v])
			dfs2(u);

	for(int u : adj[v])
	{
		if(u == par[v]) continue ;
		for(int k = 1; k < 61; k++)
		{
			timeMax[v][k] = max(timeMax[v][k], timeMax[u][k-1]);
			timeMin[v][k] = min(timeMin[v][k], timeMin[u][k-1]);
		}
	}
}


void clean()
{
	timer = 0 ; 
	for(int i = 0; i <= n; i++) {
		tin[i] = 0 ;
		tout[i] = 0;
		adj[i].clear();
		depth[i] = 0;
		par[i] = -1 ; 
		for(int j = 0; j < 61; j++) timeMin[i][j] = 1e9, timeMax[i][j] = 0 ; 
	}
	cleanTree(1, 1, n);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); int qt, u, v, y, x ; 
	pre();
	int t ; cin >> t ; 
	while(t--)
	{
		clean(); // CLEAR
		cin >> n >> q ;
		for(int i = 1; i < n; i++)
		{
			cin >> u >> v ;
			adj[u].pb(v); adj[v].pb(u);
		}
		// cout << "TIme for dfs " << endl ; 
		dfs(1, -1, 1);
		bfs(1);
		dfs2(1);
		// cout << "TIme for queries !" << endl ;
		while(q--)
		{
			cin >> qt >> x ;
			if(qt == 1)
			{
				cin >> y ;
				upd(x, y); 
			}
			else {
				lint here = query(1, 1, n, timeMax[x][0]);
				// _mult(here, inverse[depth[x]]);
				// int mxDepth = query2(1, 1, n, tin[x]);
				// if(depth[x] > mxDepth) cout << 0 << endl ;
				// else 
				cout << here << endl ; 
			}
		}
		// clean(); 
	}	
	
}