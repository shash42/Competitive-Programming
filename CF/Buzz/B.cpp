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
int a, b, x[6], md[3], ans[3], idx;
int mn=9e17;
int M(int x, int y)
{
	x+=mn;
	return x%y;
}
signed main()
{
	cin >> a >> b;
	for(int i = 0; i < 6; i++)
	{
		cin >> x[i];
		md[M(x[i], 3)]++;
		//cout << x[i]%3 << endl;
	}
	ans[0]=(md[1]+md[2])*min(a, b);
	ans[1]=(md[0]+md[2])*min(a, b);
	ans[2]=(md[1]+md[0])*min(a, b);
	for(int i = 0; i < 3; i++)
	{
		if(ans[i]<mn)
		{
			idx=i;
			mn=ans[i];
		}
	}
	cout << mn << endl << idx;
}