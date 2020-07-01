#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define F first
#define S second

using namespace std;

const int N = 2e5+5;

int a[N], n, c[N], q, ans=0;
map< pii, int > St;
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		ans+=a[i];
	}
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		int s, t, u;
		cin >> s >> t >> u;
		if(St.find(mp(s, t))!=St.end())
		{
			int nu = St[mp(s, t)];
			St.erase(mp(s, t));
			c[nu]--;
			if(c[nu]<a[nu])
			{
				ans++;
			}
			if(u!=0)
			{
				St[mp(s, t)]=u;
				c[u]++;
				if(c[u]<=a[u])
				{
					ans--;
				}
			}
		}
		else
		{
			St[mp(s, t)]=u;
			c[u]++;
			if(c[u]<=a[u])
			{
				ans--;
			}
		}
		cout << ans << endl;
	}
}