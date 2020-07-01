#include<bits/stdc++.h>

using namespace std;

int cnt2[26], cnt[26];
void solve()
{
	string p, h;
	cin >> p >> h;
	int n = p.length(), l = h.length();
	for(int i = 0; i < 26; i++) cnt2[i]=0;
	for(int i = 0; i < n; i++) cnt2[p[i]-'a']++;
	for(int i = 0; i < l; i++)
	{
		if(i+n-1>=l) break;
		for(int j = 0; j < 26; j++) cnt[j]=0;
		for(int j = i; j < i+n; j++)
		{
			cnt[h[j]-'a']++;
		}
		for(int j = 0; j < 26; j++)
		{
			if(cnt[j]!=cnt2[j])
			{
				break;
			}
			if(j==25)
			{
				cout << "YES\n";
				return;
			}
		}
	}
	cout << "NO\n";
}
int main()
{
	int t;
	cin >> t; 
	while(t--)
	{
		solve();
	}
}