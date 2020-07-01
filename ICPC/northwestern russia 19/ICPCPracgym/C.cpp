#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;
int f(int x, int n, int m)
{
	int lol=x*(n-m+1);
	if(lol%n) return x - (x*(n-m+1))/n;
	else return x - 1 - (x*(n-m+1))/m;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;

	}			
}