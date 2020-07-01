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
	depth[v] = height ;
	par[v] = p ; 
	for(int u : adj[v])
		if(u != p)
			dfs(u, v, height + 1);
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
	}
}

lint ans[N][62], ans2[N];

int mx = 1e9 ; 

void upd(int x, int y)
{
	for(int z = y; z >= 0; z--)
		_add(ans[x][z], pwr[y]) ; 

	int p = par[x] ;
	while(p != -1)
	{
		lint here = pwr[--y] ; 
		_add(ans2[p], here) ; //update(1, 1, n, timeMin[p][0], timeMax[p][0], here);
		p = par[p] ;
		if(y <= 0) break ; 
	}

}

lint get(int v)
{

	int p = par[v] ; int k = 1 ; lint here = ans2[v] ; 
	_add(here, ans[v][0]);
	while(p != -1)
	{
		if(ans[p][k]) _add(here, (ans[p][k] * inverse[k]) % MOD );
		p = par[p] ;
		k++ ; 
		if(k > 60) break ;
	}
	return here ; 
}

void clean()
{
	for(int i = 0; i <= n; i++) {
		adj[i].clear();
		depth[i] = 0;
		par[i] = -1 ; 
		for(int j = 0; j < 61; j++) ans[i][j] = ans2[i] = 0 ; // timeMin[i][j] = 1e9, timeMax[i][j] = 0 ; 

	}
	// cleanTree(1, 1, n);
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
		dfs(1, -1, 1);
		while(q--)
		{
			cin >> qt >> x ;
			if(qt == 1)
			{
				cin >> y ;
				upd(x, y); 
			}
			else {
				cout << get(x) << "\n" ; 
			}
		}
	}	
	
}