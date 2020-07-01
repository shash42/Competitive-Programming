#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5, K=3e6, INF=2e9;

int n, lb, ub, arr[N], q, pref[N];

struct node
{	
	int xu, xl, yu, yl;
} segt[4*N];

int simulate(int x, int l, int r)
{
	for(int a=l; a<=r; a++)
	{
		x+=arr[a];
		if(x>ub)
			x=ub;
		if(x<lb)
			x=lb;
	}
	return x;
}
int findxu(int val, int l, int r) //find last x such that f(x)==val. If not found return ub+1
{
	int hi=ub+1, lo=lb-1;
	int ans=lb-1;
	while(hi>=lo)
	{
		int mid=(hi+lo)/2;
		int here=simulate(mid, l, r);
		if(here==val)
		{
			ans=mid;
			lo=mid+1;
		}
		else if(here>val)
			hi=mid-1;
		else
			lo=mid+1;
	}
	return ans;
}

int findxl(int val, int l, int r) //find first x such f(x)==val. If not found return lb-1
{
	int hi=ub+1, lo=lb-1;
	int ans=ub+1;
	while(hi>=lo)
	{
		int mid=(hi+lo)/2;
		int here=simulate(mid, l, r);
		if(here==val)
		{
			ans=mid;
			hi=mid-1;
		}
		else if(here>val)
			hi=mid-1;
		else
			lo=mid+1;
	}
	return ans;
}

void build(int idx, int s, int e)
{
	segt[idx].yu = simulate(ub, s, e);
	segt[idx].yl = simulate(lb, s, e);
	segt[idx].xu = findxu(segt[idx].yu-1, s, e);
	segt[idx].xl = findxl(segt[idx].yl+1, s, e);
	if(s==e) return;
	int mid=(s+e)/2;
	build(idx*2, s, mid);
	build(idx*2+1, mid+1, e);
}

int query(int idx, int l, int r, int s, int e, int x)
{
//	cout<<l<<" "<<r<<" "<<s<<" "<<e<<" "<<x << " - " << segt[idx].xl << " " << segt[idx].xu << " " << segt[idx].yl << " " << segt[idx].yu <<endl;
	int ret=-INF;
	if(l>e || r<s) return ret;
	if(l>=s && r<=e)
	{
		if(x<segt[idx].xl)
		{
			return segt[idx].yl;
		}
		else if(x>segt[idx].xu)
		{
			return segt[idx].yu;
		}
		else
		{
			ret=x+pref[r]-pref[l-1];
			return ret;
		}
	}
	int mid=(l+r)/2;
	int l1 = query(idx*2, l, mid, s, e, x);
	if(l1==-INF)
	{
		return query(idx*2+1, mid+1, r, s, e, x);
	}
	int r1 = query(idx*2+1, mid+1, r, s, e, l1);
	if(r1==-INF) return l1;
	return r1;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> lb >> ub;
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		pref[i]=pref[i-1]+arr[i];
	}
	build(1, 1, n);
	cin>>q;
	for(int i = 1; i <= q; i++)
	{
		int b, e, x, pass;
		cin >> b >> e >> x;
		pass=x+arr[b];
		if(x+arr[b]>ub) pass=ub;
		else if(x+arr[b]<lb) pass=lb;
		if(b==e)
		{
			cout << pass << endl;
			continue;
		}
		int ans = query(1, 1, n, b+1, e, pass);
		cout << ans << endl;
	}
}