#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair

using namespace std;
using namespace __gnu_pbds;

template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N=103;
struct teams
{
	int a, d, idx;
} team[N];
struct ossrt
{
	bool operator()(const pii &a, const pii &b)
	{
		if(a.first==b.first) return a.second < b.second;
		return a.first > b.first;
	}
};
ordered_set< pii> ranks;
int n, ans;
vector < teams > pve, nve;
struct teamsrt1
{
	bool operator()(const teams &t1, const teams &t2)
	{
		if(t1.a==t2.a) return t1.idx>t2.idx;
		return t1.a>t2.a;
	}
};
struct nsrt
{
	bool operator()(const teams &t1, const teams &t2)
	{
		if(t1.a+t1.d==t2.a+t2.d) return t1.idx>t2.idx;
		return t1.a+t1.d > t2.a+t2.d;
	}
};
struct psrt
{
	bool operator()(const teams &t1, const teams &t2)
	{
		if(t1.a+t1.d==t2.a+t2.d) return t1.idx<t2.idx;
		return t1.a+t1.d < t2.a+t2.d;
	}
};
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> team[i].a >> team[i].d;
		team[i].idx=-i;
	}
	sort(team, team+n, teamsrt1());
	for(int i = 0; i < n; i++)
	{
		ranks.insert(mp(team[i].a, team[i].idx));
		if(team[i].d<0) nve.pb(team[i]);
		else pve.pb(team[i]);
	}
	sort(pve.begin(), pve.end(), psrt());
	sort(nve.begin(), nve.end(), nsrt());
	for(auto v: pve)
	{
	//	cout << v.idx << " - ";
		int rnk1=ranks.order_of_key(mp(v.a, v.idx));
		//cout << rnk1 << endl;
		ranks.erase(mp(v.a, v.idx));
		ranks.insert(mp(v.a+v.d, v.idx));
		int rnk2=ranks.order_of_key(mp(v.a+v.d, v.idx));
		ans+=abs(rnk1-rnk2);
	}
	for(auto v: nve)
	{
		//cout << v.idx << endl;
		int rnk1=ranks.order_of_key(mp(v.a, v.idx));
		ranks.erase(mp(v.a, v.idx));
		ranks.insert(mp(v.a+v.d, v.idx));
		int rnk2=ranks.order_of_key(mp(v.a+v.d, v.idx));
		ans+=abs(rnk1-rnk2);
	}

	cout << ans;
}