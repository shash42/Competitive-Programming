#include<bits/stdc++.h>

using namespace std;

const int N=503, D=1e3+3; 
double ans=0, ansd;
int n, m, l[N], maxl, h[N][N], pref[N][N], days;
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> l[i];
		maxl=max(l[i], maxl);
		for(int j = 1; j <= l[i]; j++)
		{
			cin >> h[i][j];
		}
	}	
	days = maxl+m;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= days; j++)
		{
			pref[i][j]=pref[i][j-1]+h[i][j];
		}
	}
	for(int i = 1; i <= days; i++)
	{
		ansd=0;
		for(int j = 1; j <= n; j++)
		{
			int curr=pref[j][i];
			if(i>=m)
			{
				curr-=pref[j][i-m];
				//poss=m;
			}
			ansd+=(double) curr;
		}
		cout << i << " " << ansd << endl;
		ans+=ansd*ansd/m;
	}
	cout << ans;
}