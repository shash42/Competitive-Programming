#include<bits/stdc++.h>
#define f first
#define s second

using namespace std;

const int N=2e5+5;
const int MOD=998244353;

typedef long long ll;

ll n, c[4][N], BIT[N], pow2[N];
pair<ll, ll> arr[N];

ll query(ll x)
{
	ll ret=0;
	for(;x>0; x-=x&-x)
		ret+=BIT[x];
	return ret;
}

void upd(ll x)
{
	for(;x<=n; x+=x&-x)
		BIT[x]+=1;
}

int main()
{
	pow2[0]=1;
	for(ll a=1; a<N; a++)
		pow2[a]=(pow2[a-1]*2LL)%MOD;
	// n=5;
	// upd(2);
	// upd(3);
	// upd(4);
	// printf("%lld %lld %lld\n", query(2), query(3), query(4));
	scanf("%lld", &n);
	for(ll a=1; a<=n; a++)
		scanf("%lld%lld", &arr[a].f, &arr[a].s);
	sort(arr+1, arr+n+1);
	for(ll a=1; a<=n; a++)
	{
		arr[a].f=a;
		swap(arr[a].f, arr[a].s);
	}
	sort(arr+1, arr+n+1);
	for(ll a=1; a<=n; a++)
	{
		arr[a].f=a;
		swap(arr[a].f, arr[a].s);
	}
	// printf("here\n");
	sort(arr+1, arr+n+1);
	for(ll a=1; a<=n; a++)
	{
		// printf("%lld %lld %lld\n", a, arr[a].f, arr[a].s);
		c[0][a]=query(arr[a].s);//LEFT AND DOWN
		c[1][a]=a-c[0][a]-1;//LEFT AND UP
		upd(arr[a].s);
	}
	// printf("here\n");
	for(ll a=0; a<=n; a++)
		BIT[a]=0;
	for(ll a=n; a>=1; a--)
	{
		c[2][a]=query(arr[a].s);//RIGHT AND DOWN
		c[3][a]=n-a-c[2][a];//RIGHT AND UP
		upd(arr[a].s);
	}
	// for(int a=1; a<=n; a++)
	// {
	// 	printf("%d: ", a);
	// 	for(int b=0; b<4; b++)
	// 		printf("%lld ", c[b][a]);
	// 	printf("\n");
	// }
	ll ans=(n*(pow2[n]-1)+MOD)%MOD;
	for(ll a=1; a<=n; a++)
	{
		ll subhere=0;
		for(ll b=0; b<4; b++)
			subhere=(subhere+pow2[c[b][a]]-1)%MOD;
		subhere+=((pow2[c[0][a]]-1)*(pow2[c[1][a]]-1))%MOD;
		subhere%=MOD;
		subhere+=((pow2[c[1][a]]-1)*(pow2[c[3][a]]-1))%MOD;
		subhere%=MOD;
		subhere+=((pow2[c[3][a]]-1)*(pow2[c[2][a]]-1))%MOD;
		subhere%=MOD;
		subhere+=((pow2[c[2][a]]-1)*(pow2[c[0][a]]-1))%MOD;
		subhere%=MOD;
		ans-=subhere;
		ans+=MOD;
		ans%=MOD;
	}
	printf("%lld\n", ans);
	return 0;
}