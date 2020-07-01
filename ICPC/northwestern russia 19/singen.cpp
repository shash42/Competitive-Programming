#include<bits/stdc++.h>

using namespace std;

int main()
{
	cout << fixed << setprecision(25);
	int ans;
	long double mn = 1e8;
	for(int i = 1; i <= 20000; i++)
	{
		long double lol = M_PI*i;
		if(lol-floor(lol)-mn<0.0)
		{
			ans=lol;
			mn = lol-floor(lol);
		}
		if(ceil(lol)-lol-mn<0.0)
		{
			ans=lol;
			mn = ceil(lol)-lol;
		}
	}
	cout << ans << " " << mn << endl;
}