#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=4e5+5;

int n, t, p[N], g, s, b;

signed main()
{
	cin >> t;
	while(t--)
	{
		g=0, s=0, b=0;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> p[i];
		}
		g = 1;
		int ptr=2;
		for( ; ptr <= n/2; ptr++)
		{
			if(p[ptr]!=p[ptr-1])
			{
				break;
			}
			g++;
		}
		for( ; ptr <= n/2; ptr++)
		{
			if(s>g && p[ptr]!=p[ptr-1])
			{
				break;
			}
			s++;
		}
		if(s<=g)
		{
			cout << 0 << " " << 0 << " " << 0 << endl;
			continue;
		}
		//cout << "lolol: " << ptr << endl;
		int incr=0;
		for( ; ptr<=n/2; ptr++)
		{
			if(p[ptr]!=p[ptr-1])
			{
				b+=incr;
				incr=0;
			}
			incr++;
		}
		if(p[n/2+1]!=p[n/2])
		{
			b+=incr;
		}
		if(b<=g)
		{
			cout << 0 << " " << 0 << " " << 0 << endl;
			continue;
		}
		cout << g << " " << s << " " << b << endl;
	}	
}