#include<bits/stdc++.h>
#define pb push_back
using namespace std;

const int N=102;
int ans[N][N];
int n = 6;
vector<int> rotate(vector<int> v, int r)
{
	vector<int> temp(n);
	for(int i = 0; i < n; i++)
	{
		temp[i]=v[(i-r+n)%n];
	}
	return temp;
}
vector<int> flipodd(vector<int> v)
{
	vector<int> temp(n);
	for(int i = 0; i < n; i++)
	{
		temp[i]=v[(n-i)%n];
	}
	return temp;
}
vector<int> flipeven(vector<int> v)
{
	vector<int> temp(n);
	for(int i = 0; i < n; i++)
	{
		temp[i]=v[(n+1-i)%n];
	}
	return temp;	
}
int main()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			vector<int> v;
			for(int k = 1; k <= n; k++) v.pb(k);
			v = rotate(v, i);
			v = flipeven(v);
			v = rotate(v, j);
			v = flipeven(v);
			ans[i][j]=(n+1-v[0])%n;
		}
	}	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}