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
		if(taken[i]) continue;
		int mnarea=INF*INF, mnind=-1, mnsperi=INF;
		for(int j = i+1; j <= n; j++)
		{
			if(taken[j]) continue;
			int currarea=llabs(arr[i].y-arr[j].y) * llabs(arr[i].z - arr[j].z);
			if(currarea < mnarea)
			{
				mnsperi=llabs(arr[i].y-arr[j].y) + llabs(arr[i].z - arr[j].z);
				mnarea=currarea;
				mnind=j;
			}
			else if(currarea==mnarea)
			{
				int currperi=llabs(arr[i].y-arr[j].y) + llabs(arr[i].z - arr[j].z);
				if(currperi<mnsperi)
				{
					mnsperi=currperi;
					mnind=j;		
				}
			}
		}
		cout << arr[i].idx << " " << arr[mnind].idx << endl;
		taken[mnind]=1;
		taken[i]=1;
	}
}
	/*for(int i = 1; i <= n; i++)
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
			for(int j = 1; j < v[i].size(); j++)
			{
				cout << v[i][j-1].idx << " " << v[i][j].idx << endl; 
			}
		}
		else
		{
			for(int j = 1; j < v[i].size()-1; j++)
			{
				cout << v[i][j-1].idx << " " << v[i][j].idx << endl; 
			}
			pt curr=v[i][v[i].size()-1];
			//cout << arr[mnind].y << " " <<arr[mnind].z << endl;
		}
	}*/