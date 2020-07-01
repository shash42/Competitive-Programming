#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair

using namespace std;

string s;
int cnt, lst, ttcnt, comp0=1, lstcmp=1, ans, k;
signed main()
{
	cin >> s;
	cin >> k;
	int l = s.length();
	if(l==1)
	{
		cout << k/2;
		return 0;
	}
	for(int i = 1; i < l; i++)
	{
	//	cout << i << endl;
		int j = i;
		ttcnt=1;
		while(j<l && s[j]==s[j-1])
		{
			ttcnt++;
			j++;
		}
		if(i==1 && s[i]==s[i-1])
		{
			comp0=ttcnt;
			if(comp0==l)
			{
				cout << (l*k)/2;
				return 0;
			}
		}
		else if(j==l)
		{
			lstcmp=ttcnt;
		}
		else
		{
		//	cout << i << " " << j << " - " << ttcnt << endl;
			cnt+=ttcnt/2;
		}
		if(ttcnt!=1) i=j-1;
	}
	ans+=cnt*k;
	if(s[0]==s[l-1])
	{
	//	cout << comp0 << " " << lstcmp << " " << cnt << endl;
		ans+=(comp0/2)+(lstcmp/2);
		ans+=(k-1)*((comp0+lstcmp)/2);
	}
	else
	{
		ans+=k*(comp0/2);
		ans+=k*(lstcmp/2);
	}
	cout << ans;
}