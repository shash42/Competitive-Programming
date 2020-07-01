#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q;
	cin >> q;
	while(q--)
	{
		int n;
		cin >> n;
		if(n<4)
		{
			cout << 4-n << endl;
		}
		else
		{
			cout << n%2 << endl;
		}
	}
}