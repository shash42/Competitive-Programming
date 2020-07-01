#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int> 

using namespace std;
string s;
int n, sum1, sum2, a1, a2;
void swap(int &x, int &y)
{
	x+=y;
	y=x-y;
	x-=y;
}
signed main()
{
	cin >> n;
	cin >> s;
	for(int i = 0; i < n; i++)
	{
		if(s[i]=='?')
		{
			if(i<n/2) a1++;
			else a2++;
			continue;
		}
		if(i<n/2)
		{
			sum1+=s[i]-'0';
		}
		else sum2+=s[i]-'0';
	}
	if(sum1==sum2)
	{
		if(a1==a2)
		{
			cout << "Bicarp";
			return 0;
		}
		cout << "Monocarp";
		return 0;
	}
	if((sum1>sum2 && a1>=a2) || (sum2>sum1 && a2>=a1))
	{
		cout << "Monocarp";
		return 0;
	}
	if(sum1>sum2)
	{
		swap(a1, a2);
		swap(sum1, sum2);
	}
	if(sum2-sum1>9)
	{
		cout << "Monocarp";
		return 0;
	}
	if(a1%2)
	{
		cout << "Bicarp";
	}
	else cout << "Monocarp";
}
