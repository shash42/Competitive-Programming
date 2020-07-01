#include<bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define pii pair<int, int>
#define F first
#define S second

using namespace std;

const int N=5e4+5, M=1e5+5;

int n, m, t;

pii edge[M];
set<int> comp;
string ans;
int main()
{
	srand(time(NULL));
	cin >> n >> m >> t;
	for(int i = 1; i <= m; i++)
	{
		ans+='.';
	}
	for(int i = 1; i <= m; i++)
	{
		cin >> edge[i].F >> edge[i].S;
	}	
	int sink = edge[m].F;
	ans[m-1]='^';
	comp.insert(edge[m].F); comp.insert(edge[m].S);
	for(int i = m-1; i >= 1; i--)
	{
		if(comp.find(edge[i].F)!=comp.end())
		{
			comp.insert(edge[i].S);
			ans[i-1]='^';
		}
		else if(comp.find(edge[i].S)!=comp.end())
		{
			ans[i-1]='v';
			comp.insert(edge[i].F);
		}
		else
		{
			int lol=rand()%2;
			if(lol)
			{
				ans[i-1]='^';
			}
			else
			{
				ans[i-1]='v';
			}
		}
	}
	if(comp.size()==n)
	{
		cout << ans;
	}
	else cout << -1;
}
