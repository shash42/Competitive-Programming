#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define F first
#define S second
#define lint long long

using namespace std;

const int N = 1e5+5, MOD=1e9+7;
int n, a[N];
string s1[22], s2[22];
signed main()
{
	int t=1;
//	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		for(int i = 0; i < n; i++)
		{
			cin >> s1[i];
		}
		for(int i = 0; i < m; i++)
		{
			cin >> s2[i];
		}
		int q;
		cin >> q;
		while(q--)
		{
			int y;
			cin >> y;
			y--;
			cout << s1[y%n] + s2[y%m] << endl;
		}
	}
}