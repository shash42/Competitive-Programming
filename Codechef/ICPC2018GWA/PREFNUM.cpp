#include<bits/stdc++.h>
#define int long long

using namespace std;
int x, y, z;
signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> x >> y;
		if(x%y==0)
		{
			cout << x << endl;
			continue;
		}
		int m1 = x%y;
		int p10=10, p=1;
		bool flag=false;
		while(x*p10 <= 1e18 && x*p10>0)
		{
			//cout << p10 << endl;
			int k = y - ((m1*p10)%y);
			if(k==y) k = 0;
			if(k < p10)
			{
				z = x*p10 +  (k);
				if(z>1e18 || z<0)
				{
					break;
				}
				cout << z << endl;
				flag=true;
				break;
			}
			p10*=10;
		}
		if(!flag) cout << -1 << endl;
	}
}