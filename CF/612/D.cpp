#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int, int>

using namespace std;

const int N = 2002;
int n, root, p[N], c[N], tme=1, scale=1e5;
vector<int> g[N];
vector < pii > under[N];
bool ans = true;
void dfs(int u)
{
	if(g[u].size()==0)
	{
		if(c[u]!=0)
		{
			ans=false;
		}
		under[u].pb({tme*scale, u});
		tme++;
		return;
	}
	int prevnum = (tme-1)*scale;
	for(auto v: g[u])
	{
		dfs(v);
	}
	int flag=0;
	int mx = -1;
	for(auto v: g[u])
	{
		for(auto num: under[v])
		{
	//		cout << num.F << endl;
			if(under[u].size()==c[u])
			{
				int addd = prevnum+1;
				if(addd<=mx)
				{
					addd=mx+2;
				}
				under[u].pb({addd, u});
				mx = max(mx, addd);
				flag=1;
			}
			int addd = num.F + flag;
			if(num.F + flag<=mx)
			{
				addd = mx+2;
			}
			under[u].pb({addd, num.S});
			mx = max(addd, mx);
			prevnum=addd;
		}
	}
	if(under[u].size()==c[u])
	{
		int addd = prevnum+1;
		if(prevnum+1<=mx)
		{
			addd = mx+2;
		}
		under[u].pb({addd, u});
		flag=1;
	}
	if(flag==0)
	{
		//cout << u << endl;
		ans = false;
	}
}
struct rootsrt
{
	bool operator()(const pii &a, const pii &b)
	{
		return a.S < b.S;
	}
};
signed main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> p[i] >> c[i];
		if(p[i]==0) root = i;
		g[p[i]].pb(i);
	}
	dfs(root);
	sort(under[root].begin(), under[root].end(), rootsrt());
	if(ans==false)
	{
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	for(auto lol: under[root])
	{
		cout << lol.F << " ";
	}
}