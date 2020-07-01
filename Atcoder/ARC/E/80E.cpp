#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int, int>
#define f first
#define s second
using namespace std;

const int N=2e5+5, INF=1e9;

int n, a[N];
set<int> S;
vector<int> v;

struct node
{
	pii val[2];
	int lzy=0;
} segt[4*N];
void combine(int idx, int par)
{
	if(segt[idx*2].val[par].f < segt[idx*2+1].val[par].f)
	{
		segt[idx].val[par] = segt[idx*2].val[par];
		return;
	}
	segt[idx].val[par] = segt[idx*2+1].val[par];
}
void build(int idx, int l, int r)
{
	if(l==r)
	{
		segt[idx].val[l%2]={a[l], l};
		segt[idx].val[1-l%2]={INF, -1};
		//cout << idx << " " << l << " - " << segt[idx].val[1].f << endl;
		return;
	}
	int mid = (l+r)/2;
	build(idx*2, l, mid);
	build(idx*2+1, mid+1, r);
	combine(idx, 0); combine(idx, 1);
}
void lazify(int idx, int l, int r)
{
	if(segt[idx].lzy==0) return;
	else segt[idx].lzy = 0;
	swap(segt[idx].val[0], segt[idx].val[1]);
	if(l==r) return;
	segt[idx*2].lzy=1-segt[idx*2].lzy;
	segt[idx*2+1].lzy=1-segt[idx*2+1].lzy;
}
pii findmin(int idx, int ll, int rr, int ss, int ee, int pr = 0)
{
	lazify(idx, ll, rr);
	if(ll>ee || rr<ss) return {INF, -1};
	if(ll>=ss && ee>=rr)
	{
		if(pr) cout << ll << " " << rr << " - " << segt[idx].val[1].f << endl;
		return segt[idx].val[1];
	}
	int mid = (ll+rr)/2;
	pii lftnode = findmin(idx*2, ll, mid, ss, ee, pr);
	pii rtnode = findmin(idx*2+1, mid+1, rr, ss, ee, pr);
	if(lftnode.f < rtnode.f) return lftnode;
	return rtnode;
}
void flip(int idx, int ll, int rr, int ss, int ee)
{
	lazify(idx, ll, rr);
	if(ll>ee || rr<ss) return;
	if(ll>=ss && ee>=rr)
	{
		segt[idx].lzy=1-segt[idx].lzy;
		lazify(idx, ll, rr);
		return;
	}
	int mid = (ll+rr)/2;
	flip(idx*2, ll, mid, ss, ee);
	flip(idx*2+1, mid+1, rr, ss, ee);
	combine(idx, 0); combine(idx, 1);
}
void assign(int idx, int ll, int rr, int pos)
{
	lazify(idx, ll, rr);
	if(ll>pos || rr<pos) return;
	if(ll==rr)
	{
		segt[idx].val[0]=segt[idx].val[1] = {INF, -1};
		return;
	}
	int mid = (ll+rr)/2;
	assign(idx*2, ll, mid, pos);
	assign(idx*2+1, mid+1, rr, pos);
	combine(idx, 0); combine(idx, 1);
}
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	S.insert(n+1);
	build(1, 1, n);
	for(int i = 0; i < n/2; i++)
	{
		pii xx = findmin(1, 1, n, 1, n);
		int x = xx.first;
	//	cout << x << " ";
		S.insert(xx.s);
		flip(1, 1, n, xx.s+1, n);
		assign(1, 1, n, xx.s);
		auto itr = S.upper_bound(xx.s);
		int r = *itr;
	//	cout << xx.s << " " << r << " - " ;
	//	int pr = (xx.s==4);
		pii yy = findmin(1, 1, n, xx.s+1, r-1);
		int y = yy.first;
		//cout << y << endl;
		S.insert(yy.s);
		if(yy.s!=n) flip(1, 1, n, yy.s+1, n);
		assign(1, 1, n, yy.s);
		v.pb(x);
		v.pb(y);
	}
	for(auto it: v)
	{
		cout << it << " ";
	}
}