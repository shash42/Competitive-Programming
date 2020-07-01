#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;
const int N=1e5+5;
int n, ent[N], ex[N], mn=N, ov=0;
signed main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		ent[x]=i;
	}
	for(int i = 1; i <= n; i++) cin >> ex[i];
	for(int i = n; i >= 1; i--)
	{
		if(ent[ex[i]]>mn)
		{
		//	cout << ex[i] << endl;
			ov++;
		}
		else
		{
			mn=ent[ex[i]];
		}
	}
	cout << ov;
}