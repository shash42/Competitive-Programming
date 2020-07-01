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
vector<int> primes;
const int M=1e9+7;
int x, n, ans=1, tmpx, ppow[65];
int fstpow(int num, int pow)
{
    int test;
    for(test = 1; pow; pow >>= 1)
    {
        if (pow & 1)
            test = ((test % M) * (num % M)) % M;
        num = ((num % M) * (num % M)) % M;
    }
    return test;
}
signed main()
{
	cin >> x >> n;
	tmpx=x;
	for(int i = 2; i*i <= x; i++)
	{
		if(tmpx%i==0) primes.pb(i);
		while(tmpx%i==0)
		{
			tmpx/=i;
		}
	}
	if(tmpx>1) primes.pb(tmpx);
	for(auto p: primes) //cuberoot(x)
	{
		int curr=1; //p^cnt
		int cnt=0; //stores power of p, faltu for now
		while(curr<=n) //logN
		{
			if(curr > n/p) //fixed for overflow
			{
				break;
			}
			else
			{
				curr*=p;
				cnt++;
				ppow[cnt]=curr;
			}
		}
		for(int i = 1; i <= cnt; i++)
		{
			int raiz=n/ppow[i];
			if(i!=cnt) raiz-=n/ppow[i+1];
			ans*=fstpow(ppow[i], raiz);
			ans%=M;	
		}
	}
	cout << ans;
}