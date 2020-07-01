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

string a;
int cnt[5], n;
signed main()
{
	cin >> n;
	cin >> a;
	for(int i = 0; i < n; i++)
	{
		if(a[i]=='z') cnt[0]++;
		if(a[i]=='e') cnt[1]++;
		if(a[i]=='r') cnt[2]++;
		if(a[i]=='o') cnt[3]++;
		if(a[i]=='n') cnt[4]++;
	}
	for(int i = 0; i < cnt[4]; i++)
	{
		cout << 1 << " ";
	}
	for(int i = 0; i < cnt[0]; i++)
	{
		cout << 0 << " ";
	}
}