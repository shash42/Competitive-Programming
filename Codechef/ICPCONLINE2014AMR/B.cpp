#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define mp make_pair
using namespace std;
const int MOD=1e9+7;
const int N=1e4+5;
pii M[N];
int ans=0, digleft[N], dp[N], m;
int add(int a, int b)
{
	return (a+b)%MOD;
}
int subtract(int a, int b)
{
	return (a-b+MOD)%MOD;
}
int oneblock(int l, int d)
{
	int ret1=(d%MOD)*(((((l%MOD)*((l+1)%MOD))%MOD)/2)%MOD)%MOD;
	int ret2=((d%MOD)*(l%MOD))%MOD;
	int ret3=(((((d%MOD)*((d-1+MOD)%MOD))/2)%MOD)*(l%MOD))%MOD;
	int ret4=(((45*(l%MOD))%MOD)*(l%MOD))%MOD;
	int ret5=(45*(l%MOD))%MOD;
	ret5=((ret5*((l+1)%MOD))/2)%MOD;
	int x=subtract(ret1, ret2);
	x=add(x, ret3);
	x=add(x, ret4);
	x=subtract(x, ret5);
	return x;
}
int gpsum(int l, int d)
{
	int ret=0;
	int mult=1;
	for(int i = 1; i <= l; i++)
	{
		
	}
}
signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
	cin >> m;
	for(int i = 0; i <= m; i++)
	{
		dp[i]=digleft[i]=0;
	}
	digleft[m]=0;
	for(int i = 0; i < m; i++)
	{
		cin >> M[i].first >> M[i].second;
	}
	cout << endl;
	for(int i = m-1; i >= 0; i--)
	{
		digleft[i]=(digleft[i+1]+M[i].first)%MOD;
	}
	dp[m-1]=oneblock(M[m-1].first, M[m-1].second) + (M[m-1].first*M[m-1].second)%MOD;
	dp[m-1]%=MOD;
	cout << m-1 << " - " << dp[m-1] << endl;
	for(int i = m-2; i >= 0; i--)
	{
		int Fi=oneblock(M[i].first, M[i].second);
		dp[i]=45;
		dp[i]*=(digleft[i+1]*(digleft[i+1]+1)/2)%MOD;
		dp[i]%=MOD;
		dp[i]*=
		dp[i]+=Fi
		dp[i]%=MOD;
		dp[i]+=(((M[i].first*M[i].second)%MOD)*dp[i+1])%MOD;
		cout << i << " - " << Fi << " " << dp[i] << endl;
	}
	cout << dp[0] << endl;
	}	
}	