#include<bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back

using namespace std;

const int N=1e5+5;

string s;
int a[N];
vector< pii > v;
int main()
{
	cin >> s;
	int n = s.length();
	for(int i = 1; i <= n; i++) a[i]=s[i-1]-'0';
	if(a[1]==0 || a[n]==1)
	{
		cout << -1;
		return 0;
	}
	for(int i = 1; i < n; i++)
	{
		if(a[i]!=a[n-i])
		{
			cout << -1;
			return 0;
		}
	}
	v.pb(mp(1, 2));
	int curr0=2, curr1=2, ptr=2;
	bool flag=false;
	for(int i = 2; i < n; i++)
	{
		ptr++;
		if(a[i])
		{
			v.pb(mp(ptr, curr1));
			curr1 = ptr;
		}
		else
		{
			v.pb(mp(curr1, ptr));
		}
		/*if(2*i==n && flag==false)
		{
			flag=true;
			i--;
		}*/
	}
	for(auto pp: v)
	{
		cout << pp.first << " " << pp.second << endl;
	}
}	