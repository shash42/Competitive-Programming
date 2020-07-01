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
string s;
signed main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int cnt0=0, cntev=0, sum=0;
		cin >> s;
		for(int j = 0; j < s.length(); j++)
		{
			if(s[j]-'0'==0) cnt0++;
			else if((s[j]-'0')%2==0) cntev++;
			sum+=s[j]-'0';
		}
		if(!cnt0 || sum%3) cout << "cyan\n";
		else if(cnt0>=2 || cntev) cout << "red\n";
		else cout << "cyan\n";
	}
}