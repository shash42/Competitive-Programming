#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define debug(a) cout << a << endl;
#define debug(a, b) cout << a << " " << b << endl;
#define debug(a, b, c) cout << a << " - " << b << " " << c << endl;
#define debug(a, b, c, d) cout << a << " " << b << " - " << c << " " << d << endl; 
#define debug(a, b, c, d, e) cout << a << " " << b << " - " << c << " " << d << " " << e << endl;

using namespace std;
int x, y;
string L="Dhasu is broke", W = "Dhasu Single is ready to mingle";
signed main()
{
	cin >> x >> y;
	if(y%3)
	{
		if(x%3==0)
		{
			cout << L;
		}
		else
		{
			cout << W;
		}
		return 0;
	}
	int pd = y+1;
	int chk = x % pd;
	if(chk==y)
	{
		cout << W;
		return 0;
	}
	if(chk%3==0)
	{
		cout << L;
	}
	else
	{
		cout << W;
	}
}