#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+5, INF=1e9, off=4e5;

int n, red, bl, ld[2*off+5], rd[2*off+5], l[N], r[N];
void solve()
{
	red=0;
	bl=0;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> l[i];
		if(l[i]==1) red++;
		else bl++;
	}
	for(int j = 0; j < n; j++)
	{
		cin >> r[j];
		if(r[j]==1) red++;
		else bl++;
	}
	int d = bl-red;
	int cd = 0;
	ld[off]=rd[off]=0;
	for(int i = n-1; i >= 0; i--)
	{
		if(l[i]==1) cd--;
		else cd++;
		ld[cd+off]=min(ld[cd+off], n-i);
	}
	cd = 0;
	for(int i = 0; i < n; i++)
	{
		if(r[i]==1) cd--;
		else cd++;
		rd[cd+off]=min(rd[cd+off], i+1);
	}
	int ans = INF;
	for(int i = -2*n; i <= 2*n; i++)
	{
		//cout << i << " " << ld[off+i] << " " << rd[off+d-i] << endl;
 		ans=min(ans, ld[off+i] + rd[off+d-i]);
		ld[off+i]=INF;
		rd[off+d-i]=INF;
	}
	cout << ans << endl;
}
signed main()
{
	for(int i = 0; i <= 2*off; i++)
	{
		ld[i]=rd[i]=INF;
	}
	int t;
	cin >> t;
	while(t--) solve();
}