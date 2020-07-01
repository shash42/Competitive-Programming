#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e3+3;
int a[N*N], pref[N*N];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n, q;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			pref[i]=pref[i-1]+a[i];
		}
		for(int i = n+1; i < N*N; i++)
		{
			a[i]=(pref[i-1]-pref[i-n-1])/n;
			pref[i]=pref[i-1]+a[i];
		}
		cin >> q;
		for(int i = 0; i < q; i++)
		{
			int x;
			cin >> x;
			if(x>=N*N) cout << a[N*N-1] << endl;
			else cout << a[x] << endl;
		}
	}	
}