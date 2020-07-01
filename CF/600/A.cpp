#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define F first
#define S second

using namespace std;

const int N=1e5+5;

int n, a[N], b[N];
signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for(int i = 0; i < n; i++)
		{
			cin >> b[i];
			a[i]-=b[i];
		}
		bool st=false, en=false, ans=true;
		int curr=-3000;
		for(int i = 0; i < n; i++)
		{
			if(a[i]>0)
			{
				ans=false;
				break;
			}
		//	cout << a[i] << " " << st << " " << en << endl;
			if(en && a[i]!=0)
			{
				ans=false;
				break;
			}
			if(st && a[i]==0)
			{
				en=true;
				continue;
			}
			if(st && a[i]!=curr)
			{
				ans=false;
				break;
			}
			if(a[i]!=0 && !st)
			{
				st=true;
				curr=a[i];
				continue;
			}
		}
		if(ans) cout << "YES\n";
		else cout << "NO\n";
	}		
}