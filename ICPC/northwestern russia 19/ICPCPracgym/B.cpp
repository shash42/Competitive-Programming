#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

signed main()
{
		int t ; cin >> t ;
		while(t--)
		{
			int x, y ,z ; cin >> x >> y >> z ;
			int cnt = x/2 + 1, cnt2 = x/2 ;
			if(y >= cnt and z >= cnt2)
			{
				printf("YES\n");
			}
			else printf("NO\n");
		}


}
