#include<bits/stdc++.h>

using namespace std;

string s, ans;
int n, other, freq[26], mx=-1, cnt=0;
char mxc;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> s;
	ans = s;
	n = s.length();
	for(int i = 0; i < n; i++)
	{
		if(freq[s[i]-'a']==0) cnt++;
		freq[s[i]-'a']++;
		if(freq[s[i]-'a']>mx)
		{
			mx=freq[s[i]-'a'];
			mxc=s[i];
		}
	}
	if(cnt==1)
	{
		cout << "NO" << endl;
		return 0;
	}
	if(mx<=n/2)
	{
		sort(ans.begin(), ans.end());
		cout << "YES" << endl << ans;
		return 0;
	}
	if(cnt==2)
	{
		for(int i = 0; i < 26; i++)
		{
			if(freq[i]!=0 && i!=(mxc-'a'))
			{
				other=freq[i];
			}
		}
	}
	for(int i = 0; i < n/2; i++)
	{
		ans[i]=mxc;
	}
	freq[mxc-'a']-=n/2;
	for(int i = 0; i < 26; i++)
	{
		if(i!=(mxc-'a') && freq[i]!=0)
		{
			ans[n/2]='a'+i;
			freq[i]--;
			break;
		}
	}
	int ptr=n/2+1;
	while(freq[mxc-'a'])
	{
		ans[ptr]=mxc;
		ptr++;
		freq[mxc-'a']--;
	}
	for(int i = 0; i < 26; i++)
	{
		while(freq[i])
		{
			ans[ptr]='a'+i;
			freq[i]--;
			ptr++;
		}
	}
	if(cnt>=3)
	{
		cout << "YES\n" << ans;
		return 0;
	}
	if(other<3)
	{
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n" << ans;
}