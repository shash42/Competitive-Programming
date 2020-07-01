#include<bits/stdc++.h>
#define pb push_back

using namespace std;
const int N=6e5;
int n, m, ndl[4*N], segvis[4*N], sz[N], par[N];
set<int> S;
vector<int> adj[4*N];
void merge(int x, int y)
{
	if(sz[x]>sz[y])
	{
		swap(x, y);
	}
	par[x]=y;
	sz[y]+=sz[x];
	sz[x]=0;
}
int find(int x)
{
	if(par[x]==x) return x;
	return par[x]=find(par[x]);
}
void dfs(int u, int szseg)
{
	segvis[u]=1;
	for(auto v: adj[u])
	{
		if(!segvis[v])
		{
			for(int i = 0; i < szseg; i++)
			{
				int vi = ndl[v]+i;
				int ui = ndl[u]+i;
				if(find(vi)!=find(ui)) merge(find(vi), find(ui));
			}
			dfs(v, szseg);
		}
	}
}
void build(int nd, int l, int r, int mode)
{
	if(mode==0) ndl[nd]=l;
	else if(mode==1 && segvis[nd]==0) dfs(nd, r-l+1);
	if(l==r) return;
	int mid=(l+r)/2;
	build(2*nd, l, mid, mode);
	build(2*nd+1, mid+1, r, mode);
}
void update(int nd1, int nd2, int l1, int r1, int l2, int r2, int st1, int en1, int st2, int en2, bool stop1, bool stop2)
{
//	cout << "abc;";
	if(st1>r1 || en1<l1 || st2>r2 || en2<l2) return;
	//cout << l1 << " " << r1 << " -- " << l2 << " " << r2 << endl;
	if(stop1 || l1>=st1 && r1<=en1)
	{
		stop1=true;
	}
	if(stop2 || l2>=st2 && r2<=en2)
	{
		stop2=true;
	}
	if(stop1 && stop2)
	{
		adj[nd1].pb(nd2);
		adj[nd2].pb(nd1);
		cout << l1 << " - " << r1 << " --- " << l2 << " - " << r2 << endl;
		return;
	}
	int mid1=(l1+r1)/2;
	int mid2=(l2+r2)/2;
	update(2*nd1, 2*nd2, l1, mid1, l2, mid2, st1, en1, st2, en2, stop1, stop2);
	update(2*nd1, 2*nd2+1, l1, mid1, mid2+1, r2, st1, en1, st2, en2, stop1, stop2);
	update(2*nd1+1, 2*nd2, mid1+1, r1, l2, mid2, st1, en1, st2, en2, stop1, stop2);
	update(2*nd1+1, 2*nd2+1, mid1+1, r1, mid2+1, r2, st1, en1, st2, en2, stop1, stop2);
}
int main()
{
	cin >> n >> m;
	int pown=1;
	while(pown<n)
	{
		pown*=2;
	}
	for(int i = 1; i <= n; i++)
	{
		par[i]=i;
		sz[i]=1;
	}
	build(1, 1, pown, 0);
	for(int i = 0; i < m; i++)
	{
		int a, b, l;
		cin >> a >> b >> l;
		update(1, 1, 1, pown, 1, pown, a, a+l-1, b, b+l-1, 0, 0);
//		cout << a << " | " << b << " | " << l << " done" << endl;
	}
	build(1, 1, pown, 1);
	for(int i = 1; i <= n; i++)
	{
		S.insert(find(i));
		cout << i << " " << find(i) << endl;
	}
	cout << S.size();
}