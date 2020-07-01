#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define F first
#define S second

using namespace std;

const int N=2e3+5;

string s, ins;
int n, k;
vector< pii > v;

int fnd(int idx, char c)
{
	for(int i = idx; i < n; i++)
	{
		if(ins[i]==c)
		{
			return i;
		}
	}
}
void rev(int l, int r)
{
	string ts = "";
	for(int i = 0; i < l; i++) ts+=ins[i];
	for(int i = r; i >= l; i--) ts+=ins[i];
	for(int i = r+1; i < n; i++) ts+=ins[i];
	ins = ts;
}
signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		v.clear();
		s = "";
		cin >> n >> k;
		cin >> ins;
		for(int i = 0; i < (k-1); i++)
		{
			s+="()";
		}
		for(int i = 0; i < n/2 - (k-1); i++)
		{
			s+="(";
		}
		for(int i = 0; i < n/2 - (k-1); i++)
		{
			s+=")";
		}
	//	cout << "yeS " << s << endl;
		for(int i = 0; i < n; i++)
		{
			int r = fnd(i, s[i]);
			rev(i, r);
			v.pb(mp(i+1, r+1));
		}
		cout << v.size() << endl;
	//	cout << "yeins " << ins << endl;
		for(auto p: v)
		{
			cout << p.F << " " << p.S << endl;
		}
	}	
}