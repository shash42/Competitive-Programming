#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define F first
#define S second

using namespace std;

const int N = 1e5+5;

int net[N], n, m;
struct flows
{
	int u, v, c;
};
vector < flows > ans;
set< pii > s;
void solve()
{
	for(int i = 1; i <= n; i++)
	{
		//cout << net[i] << endl;
		if(net[i]!=0)
		{
			s.insert(mp(net[i], i));
		}
	}
	while(s.size())
	{
		set< pii > :: iterator it = s.end();
		pii mn = *s.begin();
		s.erase(mn);
		it--;
		//cout << mn.F << " ";
		pii mx = *it;
		s.erase(it);
		//cout << mx.F << endl;
		if(-mn.F < mx.F)
		{
			mx.F+=mn.F;
			if(mx.F!=0) s.insert(mx);
			ans.pb({mn.S, mx.S, -mn.F});
		}
		else
		{
			mn.F+=mx.F;
			if(mn.F!=0) s.insert(mn);
			ans.pb({mn.S, mx.S, mx.F});
		}
	}
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		net[u]+=-c;
		net[v]+=c;
	}
	solve();
	cout << ans.size() << endl;
	for(auto o: ans)
	{
		cout << o.u << " " << o.v << " " << o.c << endl;
	}
}