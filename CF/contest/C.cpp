#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;
const int N=2e5+5;
int p[N], n, k, lcm;
pii xa, yb;
bool f(int x)
{
	int curr=0, ans=0;
	int lpos=x/lcm;
	int ypos=x/yb.S - lpos;
	int xpos=x/xa.S - lpos;
	for(int i = n; i >= 1; i--)
	{
		if(lpos)
		{
			curr++;
			ans+=(xa.F + yb.F) * p[i]/100;
			if(ans>=k) return true;
			lpos--;
		}
		else if(ypos)
		{
			curr++;
			ans+=yb.F * p[i]/100;
			if(ans>=k) return true;
			ypos--;
		}
		else if(xpos)
		{
			curr++;
			ans+=xa.F * p[i]/100;
			if(ans>=k) return true;
			xpos--;
		}
	}
	return false;
}
int Gcd(int y, int x)
{
	if(x==0) return y;
	return Gcd(x, y%x);
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q;
	cin >> q;
	while(q--)
	{
		int outp=-1;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> p[i];
		}
		cin >> xa.F >> xa.S >> yb.F >> yb.S >> k;
		if(xa.F > yb.F)
		{
			swap(xa, yb);
		}
		sort(p+1, p+n+1);
		lcm=(xa.S*yb.S)/Gcd(yb.S, xa.S);
		int l=0, r=n+1;
		while(true)
		{
			if(r-l<=1)
			{
				if(f(l))
				{
					outp=l;
				}
				else if(f(r))
				{
					outp=r;
				}
				break;
			}
			int mid=(l+r)/2;
			if(f(mid))
			{
				r=mid;
			}
			else
			{
				l=mid+1;
			}
		}
		cout << outp << endl;
	}
}