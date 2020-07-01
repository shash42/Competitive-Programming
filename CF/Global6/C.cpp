#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define F first
#define S second

using namespace std;

const int N = 505;

int a[N][N], r, c;

signed main()
{
	cin >> r >> c;
	if(r==c && r==1)
	{
		cout << 0;
		return 0;
	}
	for(int i = 1; i <= c; i++)
	{
		a[1][i]=i+1;
	}
	if(c==1)
	{
		for(int j = 1; j <= r; j++)
		{
			cout << j+1 << endl;
		}
		return 0;
	}
	for(int i = 2; i <= r; i++)
	{
		for(int j = 1; j <= c; j++)
		{
			a[i][j]=(c+i)*(j+1);
		}
	}
	for(int i = 1; i <= r; i++)
	{
		for(int j = 1; j <= c; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}