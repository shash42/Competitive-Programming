#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

const int N=5e5+5, K=8e3+3;
int n, k, team[K], ans=1e12, mxtm=-1;

bool check(int cap, int rides)
{	
	int rptr=k, currR=k;
	for(int i = 1; i <= k; i++)
	{
		while(team[i]+team[rptr]>cap && rptr>i)
		{
			rptr--;
		}
		if(rptr<=i)
		{
			break;
		}
		currR--;
		rptr--;
	}
	if(currR<=rides) return true;
	return false;
}
signed main()
{
	fast_io;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		team[x]++;
	}
	for(int i = 1; i <= k; i++)
	{
		mxtm=max(team[i], mxtm);
	}
	sort(team+1, team+k+1);
	//for(int i = 1; i <= k; i++) cout << team[i] << " ";
	//cout << check(6, 2) << endl;
	int currS=2*n, lastR=k/2+(k%2);
	for(int r = k/2 + (k%2); r<=k; r++)
	{
		int maxT=2*n;
		if(!check(maxT, r))
		{
			continue;
		}
		int lft=mxtm, rt=maxT, t=maxT;
		while(true)
		{
			if(rt-lft<=1)
			{
				if(check(lft, r))
				{
					t=lft;
					break;
				}
				else t=rt;
				break;
			}
			int mid=(lft+rt)/2;
			if(check(mid, r))
			{
				rt=mid;
			}
			else
			{
				lft=mid+1;
			}
		}
	//	cout << r << " " << t << endl;
		ans=min(ans, t*r);
		currS=t;
		lastR=r;
	}
	cout << ans;
}