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
	int par=0, parcnt=0, prv=0, ans=0, tot=0;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		tot+=a[i];
		if(a[i]%2!=par)
		{
			par=1-par;
			if(prv%2 && parcnt%2)
			{
				ans++;
			}
			prv=parcnt;
			parcnt=1;
		}
		else
		{
			parcnt++;
		}
	}
	if(prv%2 && parcnt%2) ans++;
	cout << (tot-ans)/2;
}