#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;
const int N=2e5+5;
int p[N];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q;
	cin >> q;
	while(q--)
	{
		int h, n, cnt=0;
		cin >> h >> n;
		for(int i = 0; i < n; i++)
		{
			cin >> p[i];
		}
		p[n]=0;
		int i=0;
		while(i<n-1)
		{
			if(p[i+1]-p[i+2]!=1)
			{
				cnt++;
				i++;
			}
			else
			{
				i+=2;
			}
		}
		cout << cnt << endl;
	}
}