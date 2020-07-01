#include<bits/stdc++.h>
#define int long long
#define lint long long
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define F first
#define S second
using namespace std;
const int N=1e6+6, MOD=1e9+7;
int n, ans=1, curr;
lint _add(lint x, lint y)
{
    lint ret=x+y;
    while(ret<0LL)
        ret+=MOD;
    return ret;
}
lint modpow(lint x, lint y, int mod=MOD)
{
    if(y==0)
        return 1LL;
    if(y==1)
        return x;
    lint ret=modpow(x, y/2);
    ret=ret*ret;
    ret%=mod;
    if(y%2)
        ret*=x;
    ret%=mod;
    return ret;
}
signed main()
{
	cin >> n;
	for(int i = 1; i <= n+1; i++)
	{
		ans*=2;
		ans%=MOD;
	}	
	curr=ans;
	curr=_add(curr, -2);
	ans--;
	int subt=n+1;
	for(int i = n+1; i <= 2*n; i++)
	{
		ans+=curr;
		ans%=MOD;
//		cout << i << " " << curr << " - " << ans << endl;
		curr=2*curr;
		curr%=MOD;
		curr=_add(curr, -(2*subt)%MOD);
		subt*=(i+1);
		subt%=MOD;
		subt*=modpow(i+1-n, MOD-2);
		subt%=MOD; 
	}
	ans%=MOD;
	cout << ans << endl;
}