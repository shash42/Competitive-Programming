#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define int long long
#define f first
#define s second

using namespace std;

const int N = 1e3+5, inf=1e9, mod=1e9+7;
const lint INF = 1e18;

int n, dist[N][N];
int squaresum(point a, point b)
{
	return (b.F - a.F)*(b.F - a.F) + (b.S - a.S)*(b.S - a.S);
}
struct point
{
	int F, S, ind;
} pt[N];
int adj[N][N];
map<int, vector < pii > > M;
signed main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> pt[i].F >> pt[i].S;
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = i+1; j <= n; j++)
		{
			if(i==j) continue;
			dist[i][j]=squaresum(pt[i], pt[j]);
			M[dist[i][j]].insert({i, j});
		}
	}
	for(auto it: M)
	{
		if(it.size()>=2)
		{
			for(int i = 0; i < it.size(); i++)
			{
				adj[it.F][it.S]+=1;
				adj[it.S][it.F]+=1;
			}
		}
		else
		{
			cout << 2 << endl;
			cout << it[0].F << " " << it[0].S ;
			return 0;
		}
	}
	for(auto it: M)
	{
		bool chk=true;
		for(auto i : it)
		{
			for(auto i L)
		}
	}
}