#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define F first
//#define S second

using namespace std;

const int N=1e5+5;

int n, p[N], a[N];
set<int> S;
signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		S.clear();
		cin >> n;
		bool flag=true;
		for(int i = 1; i <= n; i++)
		{
			cin >> p[i];
			S.insert(i);
		}
		for(int i = 1; i <= n; i++)
		{
			if(p[i]!=p[i-1])
			{
				if(S.find(p[i])==S.end())
				{
					cout << -1 << endl;
					flag=false;
					break;
				}
				S.erase(p[i]);
				a[i]=p[i];
				continue;
			}
			int t = *(S.begin());
			if(t>p[i])
			{
				cout << -1 << endl;
				flag=false;
				break;
			}
			a[i]=t;
			S.erase(t);
		}
		if(!flag) continue;
		for(int i = 1; i <= n; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
	}	
}