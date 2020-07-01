#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define debug(a) cout << a
#define debug(a, b) cout << a << " " << b << endl
#define debug(a, b, c) cout << a << " - " << b << " " << c << endl
#define debug(a, b, c, d) cout << a << " " << b << " - " << c << " " << d << endl
#define debug(a, b, c, d, e) cout << a << " " << b << " - " << c << " " << d << " " << e << endl

using namespace std;
const int M=1e9+7, N=1e5+5;
int fact[N], ifact[N], t, n, m, k;
int power(int x, int y) 
{ 
    if (y == 0) 
        return 1; 
    int p = power(x, y/2) % M; 
    p = (p * p) % M; 
    if(y%2) p = (x*p)%M;
    return p;
} 
signed main()
{
	fact[0]=1;
	ifact[0]=1;
	for(int i = 1; i < N; i++)
	{
		fact[i]=(fact[i-1]*i)%M;
		ifact[i]=(ifact[i-1]*power(i, M-2))%M;
	}
	cin >> t;
	while(t--)
	{
		int ans=0;
		cin >> n >> m >> k;
		for(int i = k; i <= n; i++)
		{
			int tans=fact[n];
			tans=(tans*ifact[n-i])%M;
			tans=(tans*ifact[i])%M;
			tans=(tans*power(m-1, n-i))%M;
			ans+=tans;
			ans%=M;
		}
		cout << ans << endl;
	}
}