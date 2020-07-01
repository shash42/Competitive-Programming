#include<bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

const int N=1e5+5, INF=1e18;

int n, arr[N], mx=-INF;
signed main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for(int c = 1; c < n; c++)
	{
		int currmx=-INF;
		vector<int> jc, jcpd, pjc, sjcpd;
		int d = c + (n-1)%c, sz = 0;
		if(d==c) while(n+c-1>2*d) d+=c;
	//	cout << c << " - " << d << endl;
		jc.pb(0); jcpd.pb(0);	pjc.pb(0); sjcpd.pb(0);
		for(int j = d; j < n; j+=c)
		{
			sz++;
			//if(j!=n-1) 
				jc.pb(arr[sz*c]);
			//else jc.pb(0);
			jcpd.pb(arr[j]);
			pjc.pb(pjc.back()+jc.back());
			sjcpd.pb(0);
		}
		sjcpd[sz]=jcpd[sz];
		for(int j = sz - 1; j >= 0; j--)
		{
			sjcpd[j]=sjcpd[j+1]+jcpd[j];
		}
		/*for(int j = 0; j <= sz; j++)
		{
			cout << jc[j] << "  ";
		}
		cout << endl;
		for(int j = 0; j <= sz; j++)
		{
			cout << jcpd[j] << "  ";
		}
		cout << endl;*/
		for(int j = 1; j <= sz; j++)
		{
	//		cout << j << " - " << sjcpd[j] << " " << pjc[sz - j] << endl;
			currmx = max(currmx, sjcpd[j] + pjc[sz - j]);
		}
		mx = max(currmx, mx);
	}
	cout << mx;
}
