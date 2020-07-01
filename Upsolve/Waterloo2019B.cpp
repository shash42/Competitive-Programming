#include<bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

set<int> squares;
signed main()
{
	int k, cnt=0;
	set<int> v;
	cin >> k;
	for(int i = 1; i*i < k; i++)
	{
		if(k%i==0)
		{
			int c1=k/i;
			int c2=i;
			int a = (c1-c2)/2;
			int b = (c1+c2)/2;
			if((c1-c2) % 2==0)
			{
				v.insert(a*a);
				v.insert(-b*b);
			}	
		}
	}
	for(int i = 1; i*i<=k; i++)
	{
		squares.insert(i*i);
	}
	for(int i = 1; i*i <= k; i++)
	{
		int j = k-i*i;
		if(squares.find(j)!=squares.end())
		{
			v.insert(-(i*i));
		}
	}
//	for(auto x: v)
//	sort(v.begin(), v.end());
	cout << v.size() << endl;
	for(auto x: v)
	{
		cout << x << " ";
	}
}