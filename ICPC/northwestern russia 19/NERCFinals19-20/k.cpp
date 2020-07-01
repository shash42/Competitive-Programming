#include<bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pii pair<int, int>
#define ind(x) scanf("%d", &x)
#define inlld(x) scanf("%lld", &x)

using namespace std;

typedef long long ll;

ll n, cantake[30], divi, fac[30], rep[30];
vector<ll>vec;

// ll solve(ll i, ll cnt0)
// {
// 	if(cnt0<0)
// 		return 0;
// 	if(i==divi && cnt0==0)
// 		return 1;
// 	if(i==divi)
// 		return 0;
// 	if(dp[i][cnt0]!=-1)
// 		return dp[i][cnt0];
// 	ll ret=0;
// 	ret+=solve(i+1, cnt0-1);
// 	if(cantake[i]>(i-2-num0+cnt0))
// 		ret+=solve(i+1, cnt0)*(cantake[i]-(i-2-num0+cnt0));
// 	// if(cantake[i]-cnt0-(i-2)>0)
// 	// 	ret+=solve(i+1, cnt0)*(cantake[i]-cnt0-(i-2));
// 	// printf("%lld %lld %lld\n", i, cnt0, ret);
// 	return dp[i][cnt0]=ret;
// }

void main2()
{
	inlld(n);
	divi=1;
	while(n)
	{
		divi++;
		vec.pb({n%divi});
		rep[n%divi]++;
		n/=divi;
	}
	// printf("div: %lld\n", divi);
	sort(vec.begin(), vec.end());
	// for(ll a=0; a<vec.size(); a++)
	// 	printf("%lld ", vec[a]);
	// printf("\n");
	for(ll a=2; a<=divi; a++)
	{
		for(ll b=0; b<vec.size(); b++)
			if(vec[b]<a)
				cantake[a]++;
		// printf("%lld ", cantake[a]);
	}
	ll ans=0, toadd=1;
	for(ll a=2; a<=divi; a++)
		toadd*=(cantake[a]-(a-2));
	for(ll a=0; a<30; a++)
		toadd/=fac[rep[a]];
	ans+=toadd;
	if(!rep[0])
	{
		printf("%lld\n", ans-1);
		return;
	}
	for(ll a=2; a<=divi; a++)
		cantake[a]--;
	rep[0]--;
	ll tosub=1;
	for(ll a=2; a<divi; a++)
		tosub*=(cantake[a]-(a-2));
	for(ll a=0; a<30; a++)
		tosub/=fac[rep[a]];
	ans-=tosub;
	// ans-=func(divi-1);
	printf("%lld\n", ans-1);
}

int main()
{
	fac[0]=1;
	for(ll a=1; a<=20; a++)
		fac[a]=(fac[a-1]*a);
	int t;
	ind(t);
	while(t--)
	{
		// memset(dp, -1, sizeof(dp));
		for(ll a=0; a<30; a++)
		{
			rep[a]=0;
			cantake[a]=0;
		}
		vec.clear();
		main2();
	}
	return 0;
}