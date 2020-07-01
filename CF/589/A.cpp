#include<bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define debug(a) cout << a
#define debug(a, b) cout << a << " " << b << endl
#define debug(a, b, c) cout << a << " - " << b << " " << c << endl
#define debug(a, b, c, d) cout << a << " " << b << " - " << c << " " << d << endl
#define debug(a, b, c, d, e) cout << a << " " << b << " - " << c << " " << d << " " << e << endl
using namespace std;
set<int> S;
bool diff(int x)
{
	while(x>0)
	{
		if(S.find(x%10)!=S.end()) return false;
		S.insert(x%10);
		x/=10;
	}
	return true;
}
signed main()
{
	int l, r;
	cin >> l >> r;
	for(int i = l; i <= r; i++)
	{
		S.clear();
		if(diff(i))
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << -1;	
}
