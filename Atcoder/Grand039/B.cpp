#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair

using namespace std;
const int N=202;
int n, ans, lvl[N];
char mat[N][N];
queue<int> q;
signed main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cin >> mat[i][j];
		}
	}
	for(int i = 1; i <= n; i++)
	{
		bool flag=true;
		for(int j = 1; j <= n; j++)
		{
			lvl[j]=N;
		}
		while(q.size()) q.pop();
		lvl[i]=1;
		q.push(i);
		while(q.size())
		{
			int u = q.front();
			for(int j = 1; j <= n; j++)
			{
				if(mat[u][j]=='1')
				{
					if(lvl[j]==N)
					{
						lvl[j]=lvl[u]+1;
						q.push(j);
					}
					else if(lvl[j]!=lvl[u]-1 && lvl[j]!=lvl[u]+1)
					{
				//		cout << i << " - " << u << " " << j << endl;
						flag=false;
						break;
					}
				}
			}
			q.pop();
			if(!flag) break; 
		}
		if(!flag) continue;
		for(int j = 1; j <= n; j++)
		{
			if(lvl[j]==N) break;
			ans=max(ans, lvl[j]);
		}
	//	cout << i << " - " << ans << endl;
	}
	if(ans==0) cout << -1;
	else cout << ans;
}