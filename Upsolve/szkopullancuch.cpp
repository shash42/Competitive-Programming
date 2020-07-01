#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define F first
#define S second
using namespace std;
const int N=5e5, logN=20;
int n, m, nodes[N][logN], par[N], sz[N], cnt=0;
set< pii > adj[logN][N];
set<int> ans;
void merge(int x, int y)
{
	if(sz[x]>sz[y]) swap(x, y);
	par[x]=y;
	sz[y]+=sz[x];
	sz[x]=0;
}
int find(int x)
{
	if(par[x]==x) return x;
	return par[x]=find(par[x]);
}
pii finddiff(int pwi, int a, int b)
{
	for(int i = pwi; i >= 0; i--)
	{
		if(adj[i][a].find(mp(i, b))!=adj[i][a].end())
		{
			a+=(1<<i);
			b+=(1<<i);
		}
	}
	return mp(a, b);
}
void pushup(int i, int x, int y)
{
	if(i==logN-1) return;
	if(x!=0 && adj[i][x-1].find(mp(i, y-1))!=adj[i][x-1].end())
	{
		adj[i+1][x-1].insert(mp(i+1, y-1));
		pushup(i+1, x-1, y-1);
	}
	if(x!=n && adj[i][x+1].find(mp(i, y+1))!=adj[i][x+1].end())
	{
		adj[i+1][x].insert(mp(i+1, y));
		pushup(i+1, x, y);
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		par[i]=i;
		sz[i]=1;
	}
	for(int i = 0; i < m; i++)
	{
		int A, B, L;
		cin >> A >> B >> L;
		//cout << A << " " << B << " " << L << endl;
		int a=A, b=B, l=L;
		for(int j = logN-1; j >= 0; j--)
		{
			int pw = 1<<j;
			if(pw <= l)
			{
				bool flag=true;
				for(int i = j; i < logN; i++)
				{
					
				}
				if(adj[j][a].find(mp(j, b))!=adj[j][a].end())
				{
					a+=pw;
					b+=pw;
					l-=pw;
					continue;	
				}
				else
				{
					pii R = finddiff(j, a, b);
					if(find(R.F)!=find(R.S))
					{
						merge(find(R.F), find(R.S));
						cnt++;
					}
		//			cout << l << " " << a << " " << b << " - " << R.F << " " << R.S << endl;
					if(cnt==n-1) break;
					adj[j][R.F].insert(mp(j, R.S));
					adj[j][R.S].insert(mp(j, R.F));
					pushup(j, R.F, R.S);
					l-=(R.F-a+1);
					//cout << R.F << " " << a << " - " << l << endl;
					a=R.F+1;
					b=R.S+1;
					j++;
				}
			}
		}
		if(cnt==n-1) break;
	}
	for(int i = 1; i <= n; i++)
	{
		ans.insert(find(i));
		//cout << i << " - " << find(i) << endl;
	}
	cout << ans.size();
}