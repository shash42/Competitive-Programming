#include<bits/stdc++.h>
#define inlld(x) scanf("%lld", &x)

using namespace std;

const int N=1e5+5;

typedef long long ll;

ll s, n, x, arr[N];

void main2()
{
	inlld(s);inlld(n);inlld(x);
	for(ll a=1; a<=n; a++)
		inlld(arr[a]);
	arr[0]=s;
	ll tot=s;
	for(ll a=1; a<=n; a++)
	{
		arr[a]+=tot;
		tot+=arr[a];
		if(arr[a]>=x)
		{
			n=a;
			break;
		}
	}
	for(ll a=n; a>=0; a--)
		if(arr[a]<=x)
			x-=arr[a];
	if(x==0)
		printf("yes\n");
	else
		printf("no\n");
}

int main()
{
	ll t;
	inlld(t);
	while(t--)
		main2();
	return 0;
}