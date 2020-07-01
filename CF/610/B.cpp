#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define F first
#define S second

using namespace std;

const int N=2e5+5;

int n, a[N], p, k, pk[N], pref[N], mn=2e9+5;
signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		mn=0;
		cin >> n >> p >> k;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			pk[i]=pref[i]=0;
		}
		sort(a+1, a+n+1);
		for(int i = 1; i <= n; i++)
		{
			pref[i]=pref[i-1]+a[i];
			if(i>=k) pk[i]=pk[i-k]+a[i];
			int ans = pk[i];
			ans+=pref[i%k];
			if(ans<=p)
			{
				mn=i;
			}
		}
		cout << mn << endl;
	}
}