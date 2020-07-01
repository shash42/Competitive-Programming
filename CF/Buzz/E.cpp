#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define debug(a) cout << a << endl;
#define debug(a, b) cout << a << " " << b << endl;
#define debug(a, b, c) cout << a << " - " << b << " " << c << endl;
#define debug(a, b, c, d) cout << a << " " << b << " - " << c << " " << d << endl; 
#define debug(a, b, c, d, e) cout << a << " " << b << " - " << c << " " << d << " " << e << endl;

using namespace std;

const int N=1e6+6;
int s[N], e[N], u[N], a[N], ca[N], cv[N], cd[N], fv[N], fd[N];
vector<int>  S[N], E[N];
int n, m;
signed main()
{
	//ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		cin >> s[i] >> e[i] >> u[i] >> a[i];
		S[s[i]].pb(i);
		E[e[i]].pb(i);
		fv[i]=u[i]+a[i]*(e[i]-s[i]);
		int t=(e[i]-s[i])+1;
		fd[i]=(t*(2*u[i] + (t-1)*a[i]))/2;
	}
	for(int i = 1; i <= m; i++)
	{
	//	cout << fd[i] << endl;
	}
	for(int i = 1; i <= n; i++)
	{
		ca[i]=ca[i-1]; cv[i]=cv[i-1]; cd[i]=cd[i-1];
		for(int j = 0; j < S[i].size(); j++)
		{
			int car=S[i][j];
			ca[i]+=a[car];
			cv[i]+=u[car];
		}
		for(int j = 0; j < E[i].size(); j++)
		{
			int car=E[i][j];
			ca[i]-=a[car];
		}
		cv[i]+=ca[i-1];
		cd[i]+=cv[i];
		cout << cd[i] << " ";
		//cout << cv[i] << " " << ca[i] << endl;
		for(int j = 0; j < E[i].size(); j++)
		{
			int car=E[i][j];
			cv[i]-=fv[car];
			cd[i]-=fd[car];
		}
	}
}