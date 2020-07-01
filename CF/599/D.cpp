#include<bits/stdc++.h>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;
const int N=1e5+5;

int n, m;
set<pair<int, int> > st;
set<int> nodes;

void dfs(int u)
{
	nodes.erase(u);
	bool flag=true;
	while(flag)
	{
		flag=false;
		for(auto i: nodes)
		{
			if(st.find({u, i})==st.end())
			{
				flag=true;
				dfs(i);
				break;
			}
		}
	}
}
 
int main()
{
	cin >> n >> m;
	for(int i=1; i<=n; i++)
	{
		nodes.insert(i);
	}
	for(int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		st.insert({x, y});
		st.insert({y, x});
	}
	int ans=0;
	for(int i=1; i<=n; i++)
	{
		if(nodes.find(i)!=nodes.end())
		{
			ans++;
			dfs(i);
		}
	}
	cout << ans-1;
}