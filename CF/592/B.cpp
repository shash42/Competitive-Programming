#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define pii pair<int, int>
#define pb push_back
#define mp make_pair

using namespace std;

signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		string s;
		cin >> n >> s;
		int fst=n, lst=-1;
		for(int i = 0; i < n; i++)
		{
			if(s[i]=='1')
			{
				fst=min(fst, i);
				lst=max(lst, i);
			}
		}
		int ans=n;
		ans=max(ans, 2*(lst+1));
		ans=max(ans, 2*(n-fst));
		cout << ans << endl;
	}	
}