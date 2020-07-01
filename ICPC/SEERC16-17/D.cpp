#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define f first
#define s second
#define inlld(x) scanf("%lld", &x)

using namespace std;

typedef long long ll;

const int N=2e5+5, INF=2e9;

ll L[N], T[N], n, r;
vector<ll>take_potion;

signed main()
{
	inlld(n);inlld(r);
	for(ll a=1; a<=n; a++)
		inlld(L[a]);
	for(ll a=1; a<=n; a++)
	{
		inlld(T[a]);
		if(T[a]<L[a])
		{
			printf("-1\n");
			return 0;
		}
	}
	ll cnt=0, back_time=0, tot=0;
	for(ll a=1; a<=n; a++)
	{
		if(back_time>L[a])
		{
			back_time-=L[a];
			tot+=L[a];
			continue;
		}
		ll l=L[a];
		ll t=T[a];
		tot+=back_time;
		t-=back_time;
		l-=back_time;
		back_time=0;
		if(2*l<=t)
		{
			tot+=2*l;
			continue;
		}
		ll x=2*l-t;
		cnt+=(x+r-1)/r;
		back_time=((x+r-1)/r)*r-x;
		tot+=t;
		if(cnt<=1e5)
		{
			ll drank=tot+back_time-r;
			take_potion.pb(drank);
			ll num=(x+r-1)/r;
			num--;
			while(num)
			{
				drank-=r;
				take_potion.pb(drank);
				num--;
			}
		}
		// printf("%lld %lld\n", a, tot);
	}
	printf("%lld\n", cnt);
	sort(take_potion.begin(), take_potion.end());
	if(cnt<=1e5)
		for(auto x:take_potion)
			printf("%lld ", x);
	printf("\n");
	return 0;
}