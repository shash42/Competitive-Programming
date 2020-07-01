#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e9+7;
signed main()
{
	int ans=1;
	for(int i = 1; i <= 70; i++)
	{
		ans*=6;
		ans%=M;
	}
	cout << ans;
}