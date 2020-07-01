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
const int N=1e3+3;
int n, a[N][N], arr[N], gcds[N];
vector<int> fctrz;
int fgcd(int x, int y)
{
	if(y==0)
		return x;
	return fgcd(y, x%y);
}
void makefor(int gcd0)
{
	arr[0]=gcd0;
	for(int j = 1; j < n; j++)
	{
		arr[j]=a[0][j]/gcd0;
	}
}
bool chk()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i==j) continue;
			if(a[i][j]!=arr[i]*arr[j])
				return false;
		}
	}
	return true;
}
signed main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < n; i++)
	{
		gcds[i]=fgcd(a[i][0], a[i][1]);
		for(int j = 2; j < n; j++)
		{
			gcds[i]=fgcd(gcds[i], a[i][j]);
		}
	}
	for(int i = 1; i*i<=gcds[0]; i++)
	{
		if(gcds[0]%i) continue;
		fctrz.pb(i);
		if(i*i!=gcds[0]) fctrz.pb(gcds[0]/i); 
	}
	for(auto &x: fctrz)
	{
		makefor(x);
		if(chk())
		{
			for(int i = 0; i < n; i++)
			{
				cout << arr[i] << " ";
			}
		}
	}
}