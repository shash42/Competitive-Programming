#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, a, b, INF=1e18;
signed main()
{
	cin >> n >> a >> b;
	if(a>b) swap(a, b);
	int mn = INF;
	if(a%2LL==b%2LL)
	{
		mn=min(mn, (b-a)/2LL);
	}
	else
	{
		int d = (b-a-1)/2;
		d+=a;
		mn=min(mn, d);
		int c = (b-a-1)/2;
		c+=(n-b+1);
		mn=min(mn, c);
	}
	cout << mn;
}