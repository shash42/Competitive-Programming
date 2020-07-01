#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define F first
#define S second
#define lint long long

using namespace std;

const int N = 2e5+5, inf=1e9, mod=1e9+7;
const lint INF = 1e18;

int n, a[N];
signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		int mn=inf, mx=-inf, l=-1, r=-1;
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
			if(i!=0 && abs(a[i]-a[i-1])>=2)
			{
				l = i-1;
				r=i;
			}
		}
		if(l!=-1)
		{
			cout << "YES\n";
			cout << l+1 << " " << r+1 << "\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
}