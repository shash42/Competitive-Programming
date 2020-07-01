#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define F first
#define S second

using namespace std;

const int N=2e5+5;

struct prob
{
	int diff, t=0, pref=0, suff0=0, suff1=0;
} p[N];
struct psrt
{
	bool operator()(const prob &a, const prob &b)
	{
		if(a.t==b.t) return a.diff > b.diff;
		return a.t<b.t;
	}
};
int n, T, d[2];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int m;
	cin >> m;
	while(m--)
	{
		int ans = 0;
		cin >> n >> T >> d[0] >> d[1];
		for(int i = 1; i <= n; i++)
		{
			cin >> p[i].diff;
		}
		for(int i = 1; i <= n; i++)
		{
			cin >> p[i].t;
		}
		p[n+1].t = T;
		p[n+1].diff=-1;
		sort(p+1, p+n+2, psrt());
		for(int i = 1; i <= n; i++)
		{
			p[i].pref=p[i-1].pref + d[p[i].diff];
		//	if(m==0) cout << p[i].pref << " " << d[p[i].diff] << endl;
		}
		p[n+1].suff0=p[n+1].suff1=0;
		for(int i = n; i >= 1; i--)
		{
			p[i].suff0=p[i+1].suff0 + (p[i].diff==0);
			p[i].suff1=p[i+1].suff1 + (p[i].diff==1);
		}
		for(int i = 0; i <= n; i++)
		{	
		//	if(p[i].pref>p[i].t) break;
		//	if(i!=n && p[i+1].t==p[i].t) continue;
			int tot = i;
			int currt = p[i].pref;
		//	if(m==0) cout << p[i+1].t << " " << currt << endl;
			int rem = p[i+1].t - currt;
			if(i!=n) rem--;
			//cout << i << " " << rem << endl;
			if(rem<0LL) continue;
		//	if(m==0) cout << i << " " << p[i].t << endl;
			if(rem >= p[i+1].suff0*d[0])
			{
				rem-=p[i+1].suff0*d[0];
				tot+=p[i+1].suff0;
				tot+= min(p[i+1].suff1, rem / d[1]);
			}
			else
			{
				tot += rem / d[0];
			}
			ans = max(ans, tot);
		}
		cout << ans << endl;
	}
}