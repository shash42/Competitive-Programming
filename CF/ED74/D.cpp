#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;

string s;
const int N=3e5+5;
int n, fnd[N][2][2], ans;
signed main()
{
	cin >> n;
	cin >> s;
	ans=n*(n+1)/2;
	int curra=-1, currb=-1;
	for(int i = 0; i < n; i++)
	{
	//	cout << i << " " << curra << " " << currb << endl;
		fnd[i][0][0]=curra;
		fnd[i][0][1]=currb;
		if(s[i]=='A')
		{
			curra=i;
		}
		else if(s[i]=='B')
		{
			currb=i;
		}
	}
	curra=n, currb=n;
	for(int i = n-1; i >= 0; i--)
	{
	//	cout << i << " " << curra << " " << currb << endl;
		fnd[i][1][0]=curra;
		fnd[i][1][1]=currb;
		if(s[i]=='A')
		{
			curra=i;
		}
		else if(s[i]=='B')
		{
			currb=i;
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(s[i]=='A') ans-=i-fnd[i][0][0];
		else ans-=i-fnd[i][0][1];
	//	cout << i << " " << ans << " ";
		if(s[i]=='A') ans-=fnd[i][1][0]-i;
		else ans-=fnd[i][1][1]-i;
	//	cout << ans << endl;
	}
	ans+=n;
	for(int i = 1; i < n; i++)
	{
		if(s[i]!=s[i-1]) ans++;
	}
	cout << ans;
}	