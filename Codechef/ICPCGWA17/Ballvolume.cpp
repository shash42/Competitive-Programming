#include<bits/stdc++.h>

using namespace std;

const int N=1e3+3;
int v[N];
int main()
{
	cout << setprecision(25);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	for(int i = 0; i < n; i++)
	{
		double ans=1;
		for(int j = 0; j < n; j++)
		{
			if(i==j) continue;
			ans+= (double) v[j]/(v[i]+v[j]);
		}
		cout << ans << " ";
	}
}