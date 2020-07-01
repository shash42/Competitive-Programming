#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;
const int N=1003;
int k, n, arr[N];
signed main()
{
	cin >> k;
	while(k--)
	{
		int ans=-1e9, mn=1e9;
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr+n);
		for(int i = n-1; i >= 0; i--)
		{
			mn=min(mn, arr[i]);
			int curr=min(mn, n-i);
			ans=max(ans, curr);
		}
		cout << ans << endl;
	}	
}