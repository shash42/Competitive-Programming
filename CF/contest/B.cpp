#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;
int a[26];
signed main()
{
	int q;
	cin >> q;
	while(q--)
	{
		bool flag=false;
		memset(a, 0, sizeof(a));
		string s, t;
		cin >> s >> t;
		for(int i = 0; i < s.length(); i++)
		{
			a[s[i]-'a']=1;
		}
		for(int i = 0; i < t.length(); i++)
		{
			if(a[t[i]-'a']==1)
			{
				cout << "YES\n";
				flag=true;
				break;
			}
		}
		if(flag) continue;
		cout << "NO\n";
	}
}