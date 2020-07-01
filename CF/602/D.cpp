#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
//#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define F first
#define S second

using namespace std;
using namespace __gnu_pbds;
 
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const int N=2e5+5;

struct qr
{
	int idx, k, pos;
} qry[N];
struct qrysrt
{
	bool operator()(const qr &a, const qr &b)
	{
		return a.k < b.k;
	}
};
struct psrt
{
	bool operator()(const pii &a, const pii &b)
	{
		if(a.F==b.F)
			return a.S > b.S;
		return a.F < b.F;
	}
};
int n, m, a[N], ans[N]; 
pii b[N];
ordered_set O;

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i].F=a[i];
		b[i].S = i;
	}
	cin >> m;
	sort(b, b+n, psrt());
	for(int i = 0; i < m; i++)
	{
		cin >> qry[i].k >> qry[i].pos;
		qry[i].idx=i;
	}
	sort(qry, qry+m, qrysrt());
	int ptr=0;
	for(int i = 1; i <= n; i++)
	{
	//	cout << b[n-i].S << endl;
		O.insert(b[n-i].S);
		while(qry[ptr].k==i && ptr<m)
		{
//			cout << qry[ptr].idx << " " << qry[ptr].k << endl;
			ans[qry[ptr].idx]=a[*(O.find_by_order(qry[ptr].pos-1))];
			ptr++;
		}
	}
	for(int i = 0; i < m; i++)
	{
		cout << ans[i] << endl;
	}
}