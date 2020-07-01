#include<bits/stdc++.h>

using namespace std;

string s, t;
int n, m;
int main()
{
	cin >> s >> t;
	n = s.length(), m=t.length();
	if(n<m)
	{
		cout << 0;
		return 0;
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(s[i-1]==t[j])
			{
				dp[i][j]=dp[i-1][j-1];
			}
			else
			{
				dp[i][j]=-1;
			}
		}
	}
}