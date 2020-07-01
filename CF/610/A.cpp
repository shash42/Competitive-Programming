#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define F first
#define S second

using namespace std;

const int N=1e5+5;

signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int a, b, c, r;
		cin >> a >> b >> c >> r;
		if(a>b) swap(a, b);
		int ll = c-r, rr = c+r;
		//ll=max(0LL, ll);
		if(ll > b || rr < a)
		{
			cout << b-a << endl;
			continue;
 		}
		int ansr = b-rr;
		int ansl = ll - a;
		ansl = max(0LL, ansl);
		ansr = max(0LL, ansr);
		cout << ansl+ansr << endl;
	}
}