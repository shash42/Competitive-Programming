#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;
const int N=5e4+5, INF=1e9;
struct pt
{
	int x, y, z, idx;
};
struct ptsrt
{
	bool operator()(const pt &a, const pt&b)
	{
		if(a.x==b.x)
		{
			if(a.y==b.y) return a.z<b.z;
			return a.y<b.y;
		}
		return a.x<b.x;
	}
};
pt arr[N];
int n, cnt=0, taken[N];
vector < pt > v[N];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		arr[i].idx=i;
		cin >> arr[i].x >> arr[i].y >> arr[i].z;
	}
	arr[0]={INF, INF, INF, 0};
	sort(arr+1, arr+n+1, ptsrt());
	for(int i = 1; i <= n; i++)
	{
		if(arr[i].x==arr[i-1].x)
		{
			v[cnt].pb(arr[i]);
		}
		else
		{
			cnt++;
			v[cnt].pb(arr[i]);
		}
	}
	for(int i = 1; i <= cnt; i++)
	{
		if(v[i].size()%2==0)
		{
			for(int j = 0; j < v[i].size(); j++)
			{
				if(taken[v[i][j].idx]) continue;
				for(int it=1; it+j < v[i].size(); j++)
				{
					if(taken[v[i][j+it].idx]) continue;
					if(v[i][j+it].y!=v[i][j].y)
				{
					int k;
					bool flag=false;
					for(k = j+it; k < v[i].size(); k++)
					{
						if(v[i][k].y != v[i][j].y) break;
						if(v[i][k].z > v[i][j].z)
						{
							taken[v[i][k].idx]=1;
							taken[v[i][j].idx]=1;
							cout << v[i][j].idx << " " << v[i][k].idx << endl;
							flag=true;
							break;
						}
					}
					if(!flag)
					{
						k--;
						taken[v[i][k].idx]=1;
						taken[v[i][j].idx]=1;
						cout << v[i][j].idx << " " << v[i][k].idx << endl;
						flag=true;
					}
				}
					else
					{
						cout << v[i][j].idx << " " << v[i][j+it].idx << endl;
						taken[v[i][j].idx]=1;
						taken[v[i][j+it].idx]=1;
					}

				}

			}
		}
		else
		{
			for(int j = 0; j < v[i].size()-1; j++)
			{
				if(taken[v[i][j].idx]) continue;
				for(int it=1; it+j < v[i].size()-1; j++)
				{
					if(taken[v[i][j+it].idx]) continue;
					if(v[i][j+it].y!=v[i][j].y)
				{
					int k;
					bool flag=false;
					for(k = j+it; k < v[i].size()-1; k++)
					{
						if(v[i][k].y != v[i][j].y) break;
						if(v[i][k].z > v[i][j].z)
						{
							taken[v[i][k].idx]=1;
							taken[v[i][j].idx]=1;
							cout << v[i][j].idx << " " << v[i][k].idx << endl;
							flag=true;
							break;
						}
					}
					if(!flag)
					{
						k--;
						taken[v[i][k].idx]=1;
						taken[v[i][j].idx]=1;
						cout << v[i][j].idx << " " << v[i][k].idx << endl;
						flag=true;
					}
				}
					else
					{
						cout << v[i][j].idx << " " << v[i][j+it].idx << endl;
						taken[v[i][j].idx]=1;
						taken[v[i][j+it].idx]=1;
					}

				}

			}			pt curr=v[i][v[i].size()-1];
			int mnarea=INF*INF, mnind=-1, mnsperi=INF;
			for(int j = 0; j < v[i+1].size(); j++)
			{
				int currarea=llabs(curr.y-v[i+1][j].y) * llabs(curr.z - v[i+1][j].z);
				if(currarea < mnarea)
				{
					mnsperi=llabs(curr.y-v[i+1][j].y) + llabs(curr.z - v[i+1][j].z);
					mnarea=currarea;
					mnind=j;
				}
				else if(currarea==mnarea)
				{
					int currperi=llabs(curr.y-v[i+1][j].y) + llabs(curr.z - v[i+1][j].z);
					if(currperi<mnsperi)
					{
						mnsperi=currperi;
						mnind=j;		
					}
				}
			}
			//cout << v[i+1][mnind].y << " " <<v[i+1][mnind].z << endl;
			cout << curr.idx << " " << v[i+1][mnind].idx << endl;
			v[i+1].erase(v[i+1].begin() + mnind);
		}
	}
}