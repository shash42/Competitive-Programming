#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=17, M=70000;
int a[N][N], n, F[M];
void precomp(int x)
{
	for(int i = 0; i < n; i++)
	{
		if((x & (1<<i)) == 0LL) continue;
		for(int j = 0; j < n; j++)
		{
			if(x & (1<<j))
			{
				F[x]+=a[i][j];
			}
		}
	}
	F[x]/=2;
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
	for(int i = 0; i < (1<<n); i++)
	{
		precomp(i);
		for(int j = i; j > 0; j = (j-1)&i)
		{
			F[i]=max(F[i], F[j] + F[i^j]);
		}
	}
	cout << F[(1<<n)-1];
}