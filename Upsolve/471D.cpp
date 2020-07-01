#include<bits/stdc++.h>
#define pb push_back

using namespace std;

const int N=4e5+5;

int H[N], B[N];
vector<int> KMP(vector<int> v, int n)
{
	vector<int> pi (n);
	for(int i = 1; i < n; i++)
	{
		int j = pi[i-1];
		while(j!=0 && v[j]!=v[i])
		{
			j=pi[j-1];
		}
		pi[i] = j + (v[j]==v[i]);
	}
	return pi;
}
int main()
{
	int n, m, cnt=0;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> B[i];
	}
	for(int i = 0; i < m; i++)
	{
		cin >> H[i];
	}
	if(m>n)
	{
		cout << 0;
		return 0;
	}
	vector<int> diff;
	for(int i = 1; i < m; i++)
	{
		diff.pb(H[i]-H[i-1]);
	}
	diff.pb(2e9);
	for(int i = 1; i < n; i++)
	{
		diff.pb(B[i]-B[i-1]);
	}
	vector<int> pref = KMP(diff, diff.size());
	for(auto p: pref)
	{
		if(p==m-1)
		{
			cnt++;
		}
	}
	cout << cnt;
}