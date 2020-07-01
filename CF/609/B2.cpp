#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;
const int N=3e5+5;
int n, a[N], tot, cnt2s, cnt1s, tt, prevv;
signed main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		tt+=a[i];
		if(a[i]>=3) prevv=a[i]%2;
		if(a[i]>=3) tot+=a[i];
		if(a[i]==2) cnt2s++;
		if(a[i]==1) cnt1s++;
	}
	int ans;
	if(tot%2)
	{
		if(cnt2s%2==0)
		{
			ans = 1-(cnt1s%2);
		}
		else
		{
			ans = 1 + (cnt1s%2);
			if(ans==2 && prevv==0) ans=0;
		}
	}
	else
	{
		ans = cnt1s%2;
	}
	cout << (tt-ans)/2;
}