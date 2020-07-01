#include<bits/stdc++.h>
#define lint long long
#define pb push_back
//#define int long long
#define pll pair<lint, lint>
#define mp make_pair
#define pii pair<int, int>
#define F first
#define S second

using namespace std;

const int N=5e3+5, INF=2e9;

int n, m, w, np=1, q, vis[N];
vector<int> adj[N], pvec;
vector< pii > shovs[N];
set<int> prices;
map<int, int> pidx;
queue< pii > Q;
pii segt[4*N];
void build(int idx, int l, int r)
{
	if(l==r)
	{
		segt[idx]=mp(0, 0);
		return;
	}
	int mid = (l+r)/2;
	build(idx*2, l, mid);
	build(idx*2+1, mid+1, r);
	segt[idx]=mp(0, 0);

}
void update(int idx, int l, int r, int x, int val)
{
	if(x<l || x>r) return;
	if(l==r)
	{
		segt[idx].F += val;
		segt[idx].S = segt[idx].F * pvec[x];
		return;
	}
	int mid=(l+r)/2;
	if(x <= l) update(idx*2, l, mid, x, val);
	else update(idx*2+1, mid+1, r, x, val);
	segt[idx].F = segt[idx*2].F + segt[idx*2+1].F;
	segt[idx].S = segt[idx*2].S + segt[idx*2+1].S;
}
pii query(int idx, int l, int r, int s, int e)
{
	if(s > r || e < l) return mp(0, 0);
	if(l >= s && r <= e)
	{
		return segt[idx];
	}
	int mid=(l+r)/2;
	pii retl = query(idx*2, l, mid, s, e);
	pii retr = query(idx*2+1, mid+1, r, s, e);
	return mp(retl.F + retr.F, retl.S + retr.S);
}

pll bit[N] ;


pll query2(int s)
{
	pll ans = {0, 0} ;
	for(int i = s; i > 0; i -= i & -i)
		ans.F += bit[i].F, ans.S += bit[i].S ;
	return ans ; 
}


void update1(int x, int val1, int val2)
{
	for(int i = x; i < N; i += i & -i)
		bit[i].F += val1, bit[i].S += val2 ; 
}

void pre()
{
	for(int i = 0; i  < N; i++) bit[i] = {0, 0} ;
}

int chk(int pidxptr, int tm, int r, int a)
{
	pll ans = {INF, INF};
	while(pidxptr)
	{
		pll ret;
		ret = query2(pidxptr);
		//cout << pidxptr << " " << ret.F << " " << ret.S << endl;
		if(ret.F>= (lint) r)
		{
			ans = ret;
			if(pidxptr==1)
			{
				ret.S -= pvec[pidxptr]*(ret.F-r);
				if(ret.S<= (lint) a) return tm;
				else break;
			}
			pidxptr--;
		}
		else
		{
			pidxptr++;
			if(pidxptr<=np)
			{
				ans.S -= pvec[pidxptr]*(ans.F-r);
				if(ans.S<= (lint) a)
				{
					return tm;
				}
			}
			else
			{
				pidxptr--;
			}
			break;
		}
	}
	return -1;
}
int bfs(int g, int r, int a)
{
	while(Q.size()) Q.pop();
	int pidxptr=np;
	for(int i = 1; i <= n; i++)
	{
		vis[i]=0;
	}
	Q.push(mp(g, 0));
	int tm=0;
	vis[g]=1;
	while(Q.size())
	{
		int u = Q.front().F;
		int t = Q.front().S;
		//cout << u << " - " << t << endl;
		Q.pop();
		if(t!=tm)
		{
			int flag = chk(pidxptr, tm,r , a);
			if(flag!=-1) return flag;
			tm++;
		}
		for(auto sh: shovs[u])
		{
		//	cout << "upd: " << pidx[sh.F] << " " << sh.S << endl;
			update1(pidx[sh.F], sh.S, (lint)sh.S*sh.F);
		}
		for(auto v: adj[u])
		{
			if(vis[v]) continue;
			vis[v]=1;
			Q.push(mp(v, t+1));
		}
	}
	int flag = chk(pidxptr, tm, r, a);
	if(flag!=-1) return flag;
	return -1;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	cin >> w;
	for(int i = 0; i < w; i++)
	{
		int c, k, p;
		cin >> c >> k >> p;
		shovs[c].pb(mp(p, k));
		prices.insert(p);
	}
	pvec.pb(-1);
	for(auto it: prices)
	{
		pvec.pb(it);
		pidx[it]=np;
		np++;
	}
	np--;
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		//cout << endl << endl;
		//build(1, 1, np);
		pre();
		int g, r, a;
		cin >> g >> r >> a;
		int ans = bfs(g, r, a);
		cout << ans << endl;
	}
}