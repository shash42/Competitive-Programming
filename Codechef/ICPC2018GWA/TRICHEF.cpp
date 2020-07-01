#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define f first
#define lint long long
#define mp make_pair
#define pii pair<int, int>
#define pll pair<lint, lint>
#define inlld(x) scanf("%lld", &x)
#define ind(x) scanf("%d", &x)
#define vi vector<int>

const int N=1e6+5;
const int NN=2e3+6;
const int MOD=1e9+7;
const lint INF=1e18;


using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

struct pt
{
	ll x, y;
};

pt arr[NN];
ll n, pref[4][N], suff[4][N], arr2[4][N];

void main2()
{
	inlld(n);
	for(ll a=1; a<=n; a++)
	{
		inlld(arr[a].x);inlld(arr[a].y);
		arr2[arr[a].x][arr[a].y]+=1;
	}
	for(ll b=1; b<=3; b++)
	{
		for(ll a=1; a<N; a++)
			pref[b][a]=pref[b][a-1]+arr2[b][a];
		for(ll a=N-2; a>=0; a--)
			suff[b][a]=suff[b][a+1]+arr2[b][a];
	}
	ld area=0;
	for(ll a=1; a<=n; a++)
		for(ll b=a+1; b<=n; b++)
		{
			pt pt1=arr[a], pt2=arr[b];
			if(pt1.x>pt2.x)
				swap(pt2, pt1);
			if(pt1.x==pt2.x)
				continue;
			if(pt1.x==1)
			{
				if(pt2.x==2)
				{
					ll x3=2*pt2.y-pt1.y;
					ld area_here=((ld)pt1.y+(ld)pt2.y)/2.0L;
					ll cnt=pref[1][pt1.y-1]+pref[2][pt2.y-1]+pref[3][max(0LL, min(x3-1, 1LL*N-1))];
					cnt-=(suff[1][pt1.y+1]+suff[2][pt2.y+1]+suff[3][min(1LL*N-1, max(x3+1, 0LL))]);
					area+=((ld)cnt*area_here);
					// printf("first: %lld %lld %Lf %lld\n", a, b, area_here, cnt);
				}
				else
				{
					// ld x2=((ld)pt2.y+(ld)pt1.y)/2;
					ld area_here=(ld)pt1.y+(ld)pt2.y;
					ll cnt=pref[1][pt1.y-1]+pref[3][pt2.y-1];
					if((pt2.y+pt1.y)%2==1)
						cnt+=pref[2][(pt2.y+pt1.y)/2];
					else
						cnt+=pref[2][(pt2.y+pt1.y)/2-1];
					cnt-=(suff[1][pt1.y+1]+suff[3][pt2.y+1]);
					cnt-=suff[2][(pt1.y+pt2.y)/2+1];
					area+=((ld)cnt*area_here);
					// printf("second: %lld %lld %Lf %lld\n", a, b, area_here, cnt);
				}
			}
			else
			{
				ll x1=2*pt1.y-pt2.y;
				ld area_here=((ld)pt1.y+(ld)pt2.y)/2.0L;
				ll cnt=pref[2][pt1.y-1]+pref[3][pt2.y-1]+pref[1][min(1LL*N-1, max(x1-1, 0LL))];
				cnt-=(suff[2][pt1.y+1]+suff[3][pt2.y+1]+suff[1][max(0LL, min(x1+1, 1LL*N-1))]);
				area+=((ld)cnt*area_here);
				// printf("third: %lld %lld %Lf %lld\n", a, b, area_here, cnt);
			}
		}
	printf("%0.10Lf\n", area);
}

int main()
{
	ll t;
	inlld(t);
	while(t--)
	{
		for(int a=0; a<N; a++)
		{
			for(int b=1; b<4; b++)
			{
				pref[b][a]=0;
				suff[b][a]=0;
				arr2[b][a]=0;
			}
		}
		main2();
	}
	return 0;
}