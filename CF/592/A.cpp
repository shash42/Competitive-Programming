#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define pii pair<int, int>
#define pb push_back
#define mp make_pair

using namespace std;

signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		int pens=a/c + (a%c!=0);
		int pencils=b/d + (b%d!=0);
		if(pens+pencils<=k)
		{
			cout << pens << " " << pencils << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}	
}