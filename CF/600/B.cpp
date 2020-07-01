#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define F first

using namespace std;

const int N=1e5+5, M=1e6+6;

int n, arr[N], cnt;
vector<int> ans;
set<int> S, hc;
signed main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for(int i = 0; i < n; i++)
	{
		cnt++;
		if(arr[i]<0)
		{
			arr[i]=-arr[i];
			if(S.find(arr[i])==S.end())
			{
				cout << -1;
				return 0;
			}
			if(S.find(arr[i])!=S.end())
			{
				S.erase(arr[i]);
			}
			if(S.size()==0)
			{
				ans.pb(cnt);
				cnt=0;
				hc.clear();
			}
			continue;
		}
		if(hc.find(arr[i])!=hc.end())
		{
			cout << -1;
			return 0;
		}
		S.insert(arr[i]);
		hc.insert(arr[i]);
	}
	if(cnt>0)
	{
		cout << -1;
		return 0;
	}
	cout << ans.size() << endl;
	for(auto v: ans)
	{
		cout << v << " ";
	}
}