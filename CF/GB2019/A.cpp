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

int n, k1, k2, a[N], b[N];
signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> k1 >> k2;
		bool p1=false;
		for(int i = 0; i < k1; i++)
		{
			cin >> a[i];
			if(a[i]==n)
			{
				p1=true;
			}
		}
		for(int i = 0; i < k2; i++)
		{
			cin >> b[i];
		}
		if(p1) cout << "YES\n";
		else cout << "NO\n";
	}
}