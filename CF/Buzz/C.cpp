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
int a, b, k, ax, ay;
signed main()
{
	cin >> a >> b >> k;
	if(k<a)
	{
		cout << k+1 << " " << 1;
		return 0;
	}
	int pd = b-1;
	int x = k-a;
	ax= a - (x/pd);
	if((a-ax)%2==0)
	{
		cout << ax << " " << 2 + x%pd;
	}
	else
	{
		cout << ax << " " << b - x%pd;
	}
}