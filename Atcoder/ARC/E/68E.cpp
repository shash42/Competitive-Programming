#include<bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
#define mp make_pair
using namespace std;

const int N=3e5+5, M=1e5+5;
int n, m;
pii qr[N];
int ans[M], bgr, segt[4*M];

struct qrsrt
{
	bool operator()(const pii &a, const pii &b)
	{
		return b.S-b.F>a.S-a.F;
	}
};
void update(int idx, int l, int r, int x, int val)
{
	if(l>x || r<x) return;
	if(l==r)
	{
		segt[idx]+=val;
		return;
	}
	int mid=(l+r)/2;
	update(idx*2, l, mid, x, val);
	update(idx*2+1, mid+1, r, x, val);
	segt[idx]=segt[idx*2]+segt[idx*2+1];
}
int query(int idx, int l, int r, int st, int en)
{
	if(l>en || r<st) return 0;
	if(l>=st && r<=en) return segt[idx];
	int mid=(l+r)/2;
	return query(idx*2, l, mid, st, en) + query(idx*2+1, mid+1, r, st, en);
}
int main()
{
	cin >> n >> m;
	bgr=n;
	for(int i = 0; i < n; i++)
	{
		cin >> qr[i].F >> qr[i].S;
	}
	sort(qr, qr+n, qrsrt());
	int ptr=0;
	for(int i = 1; i <= m; i++)
	{
		while(ptr<n && qr[ptr].S-qr[ptr].F+1<i)
		{
			bgr--;
			update(1, 1, m, qr[ptr].F, 1);
			update(1, 1, m, qr[ptr].S+1, -1);
			ptr++;
		}
		ans[i]=bgr;
		for(int j = i; j <= m; j+=i)
		{
			ans[i]+=query(1, 1, m, 1, j);
		}
	}
	for(int i = 1; i <= m; i++)
	{
		cout << ans[i] << endl;
	}
}