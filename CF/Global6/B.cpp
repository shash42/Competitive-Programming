#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define F first
#define S second

using namespace std;

const int N = 1e5+5;

int a[N], n;

signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		if(n<=14) {cout << "NO\n"; continue;}
		n%=14;
		if(1<=n && n<=6) cout << "YES\n";
		else cout << "NO\n";
	}	
}