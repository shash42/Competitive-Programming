#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define F first
#define S second

using namespace std;

const int N=2e5+5;

int n, m, ans[N], d=1, arr[N], sum[N];
signed main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	sort(arr+1, arr+n+1);
	for(int i = 1; i <= n; i++)
	{
		ans[i]=ans[i-1];
		ans[i]+=arr[i];
		ans[i]+=sum[i%m];
		sum[i%m]+=arr[i];
	}
	for(int i = 1; i <= n; i++)
	{
		cout << ans[i] << " ";
	}
}