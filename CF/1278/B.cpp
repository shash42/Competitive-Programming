#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5;

void solve()
{
	int a, b;
	cin >> a >> b;
	int d = abs(a-b);
	for(int i = 0; i < N; i++)
	{
		int k = (i*(i+1))/2;
		if(k<d) continue;
		if(k%2 != d%2) continue;
		cout << i << endl;
		break;
	}
}
signed main()
{
	int t;
	cin >> t;
	while(t--) solve();
}