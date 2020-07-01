#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define F first
#define S second
#define lint long long

using namespace std;

const int N = 1e5+5, inf=1e9, mod=1e9+7;
const lint INF = 1e18;

int n, a[N];
signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		lint x = 0;
		lint s = 0;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			x^=a[i];
			s+=a[i];
		}
		cout << 2 << endl;
		cout << x << " " << s+x << endl;
	}
}