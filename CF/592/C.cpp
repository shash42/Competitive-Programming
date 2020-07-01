#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define pii pair<int, int>
#define pb push_back
#define mp make_pair

using namespace std;

int modpow(int x, int y, int mod)
{
    if(y==0)
        return 1LL;
    if(y==1)
        return x;
    int ret=modpow(x, y/2, mod);
    ret=ret*ret;
    ret%=mod;
    if(y%2)
        ret*=x;
    ret%=mod;
    return ret;
}

int _gcd(int x, int y)
{
	if(y==0) return x;
	return _gcd(y, x%y);
}

signed main()
{
	int n, p, w, d;
	cin >> n >> p >> w >> d;
	int gc=_gcd(w, d);
	if(p%gc!=0)
	{
		cout << -1;
		return 0;
	}
	int pmod=p%w;
	int y = 0;
	while(true)
	{
		if(pmod==(y*d)%w) break;
		y++;
	}
	int x=(p-y*d)/w;
	if(x+y>n)
	{
		cout << -1;
		return 0;
	}
	int z=n-x-y;
	cout << x << " " << y << " " << z;
}