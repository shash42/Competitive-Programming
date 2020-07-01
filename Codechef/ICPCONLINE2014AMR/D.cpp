#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
using namespace std;
const int N=1e6+6, inf=1e18;
int n, arr[N], lmx[N], rmx[N], lmn[N], rmn[N], ans=0;
stack< pii > mx, mn;
signed main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	mx.push(mp(inf, n+1));
	for(int i = n; i >= 1; i--)
	{
		while(mx.top().F<arr[i])
		{
			mx.pop();
		}
		rmx[i]=mx.top().S;
		mx.push(mp(arr[i], i));
	}
	while(mx.size()) mx.pop();
	mx.push(mp(inf, 0));
	for(int i = 1; i <= n; i++)
	{
		while(mx.top().F<=arr[i])
		{
			mx.pop();
		}
		lmx[i]=mx.top().S;
		mx.push(mp(arr[i], i));
	}
	mn.push(mp(-inf, 0));
	for(int i = 1; i <= n; i++)
	{
		while(mn.top().F>arr[i])
		{
			mn.pop();
		}
		lmn[i]=mn.top().S;
		mn.push(mp(arr[i], i));
	}
	while(mn.size()) mn.pop();
	mn.push(mp(-inf, n+1));
	for(int i = n; i >= 1; i--)
	{
		while(mn.top().F>=arr[i])
		{
			mn.pop();
		}
		rmn[i]=mn.top().S;
		mn.push(mp(arr[i], i));
	}
	for(int i = 1; i <= n; i++)
	{
		//cout << i << " " << arr[i] << " - " << rmx[i] << " " << lmx[i] << " " << rmn[i] << " " << lmn[i] << endl;
		ans+=arr[i]*(i-lmx[i])*(rmx[i]-i);
		ans-=arr[i]*(i-lmn[i])*(rmn[i]-i);
	}
	cout << ans;
}