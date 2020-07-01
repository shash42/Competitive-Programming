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
const int N=1e3+3, M=1e9+7;
int h, w, mat[N][N], r[N], c[N], pow2[N*N];
signed main()
{
	pow2[0]=1;
	for(int i = 1; i < N*N; i++)
	{
		pow2[i]=pow2[i-1]*2;
		pow2[i]%=M;
	}
	cin >> h >> w;
	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < w; j++)
		{
			mat[i][j]=-1;
		}
	}
	for(int i = 0; i < h; i++)
	{
		cin >> r[i];
		for(int j = 0; j < r[i]; j++)
		{	
			mat[i][j]=1;
		}
		if(r[i]!=w) mat[i][r[i]]=0;
	}
	for(int i = 0; i < w; i++)
	{
		cin >> c[i];
		for(int j = 0; j < c[i]; j++)
		{
			if(mat[j][i]==0)
			{
				cout << 0;
				return 0;
			}
			else
			{
				mat[j][i]=1;
			}
		}
		if(c[i]!=h)
			{
				if(mat[c[i]][i]==1)
				{
					cout << 0;
					return 0;
				}
				else mat[c[i]][i]=0;
			}
	}
	int cnt=0;
	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < w; j++)
		{
			if(mat[i][j]==-1)cnt++;
		}
	}
	cout << pow2[cnt];
}