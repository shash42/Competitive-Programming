#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define F first
#define S second
#define lint long long

using namespace std;

const int N = 3e5+5;
int MOD;
lint a[N];
signed main()
{
	int n;
	cin >> n >> MOD;
	a[0]=0;
	a[1]=1;
	for(int i = 2; i <= n; i++)
	{
		a[i]=(6*a[i-1] - 4*a[i-2])%MOD;
		if(a[i]<0) a[i]+=MOD;
	}
	cout << a[n];
}