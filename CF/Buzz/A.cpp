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

signed main()
{
	int l, q1, q2, q3;
	cin >> l >> q1 >> q2 >> q3;
	q1--; q2--; q3--;
	if((q1/l)%2) cout << 'S';
	else cout << 'L';
	if((q2/l)%2) cout << 'S';
	else cout << 'L';
	if((q3/l)%2) cout << 'S';
	else cout << 'L';
}
