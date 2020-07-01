#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define F first
#define S second

using namespace std;

const int N=1e5+5, INF=2e9;

pii arr[N];
signed main()
{
	int t, n;
	cin >> t;
	while(t--)
	{
		int mxst=-INF, mned=INF;
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			cin >> arr[i].F >> arr[i].S;
			mned=min(mned, arr[i].S);
			mxst=max(mxst, arr[i].F);
		}
		cout << max(0LL, mxst - mned) << endl;
	}	
}