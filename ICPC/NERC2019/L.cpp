#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int a, b, c, n;
		cin >> a >> b >> c;
		n=a+b+c;
		int seel = n/3 + (n%3!=0);
		if(a>c) swap(a, c);
		if(b>=n/3)
		{
			cout << seel << endl;
			continue;
		}
		if(a==n/3 || a==seel || c==n-seel || c==n-n/3)
		{
			cout << seel << endl;
			continue;
		}
		if(a>n/3)
		{
			if(a+b>=n-seel)
			{
				cout << seel << endl;
				continue;
			}
			cout << a << endl;
			continue;
		}
		else
		{
			if(a+b>=n/3)
			{
				cout << seel << endl;
				continue;
			}
			cout << c/2 + c%2 << endl;
			continue;
		}
	}
}