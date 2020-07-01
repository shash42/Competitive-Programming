#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define debug(a) cout << a
#define debug(a, b) cout << a << " " << b << endl
#define debug(a, b, c) cout << a << " - " << b << " " << c << endl
#define debug(a, b, c, d) cout << a << " " << b << " - " << c << " " << d << endl
#define debug(a, b, c, d, e) cout << a << " " << b << " - " << c << " " << d << " " << e << endl

using namespace std;
string s;
char smol='z', cursmol='z';
int l;
signed main()
{
	cin >> s;
	l=s.length();
	for(int i = 0; i < l; i++)
	{
		if(s[i]<smol) smol=s[i];
	}
	for(int i = 0; i < l; i++)
	{
		if(s[i]<cursmol) cursmol=s[i];
		if(s[i]==smol)
		{
			cout << "Mike" << endl;
		}
		else if(s[i]!=cursmol) cout << "Ann" << endl;
		else cout << "Mike" << endl;
 	}
}