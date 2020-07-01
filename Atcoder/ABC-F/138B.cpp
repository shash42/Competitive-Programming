#include<bits/stdc++.h>
#define pb push_back

using namespace std;

void outp(int x)
{
	vector<int> v;
	while(x)
	{
		v.pb(x%2);
		x/=2;
	}
	for(int i = v.size()-1; i >= 0; i--) cout << v[i];
}
int main()
{
	for(int i = 1; i <= 20; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			if((i^j) == (i%j))
			{
				cout << i << " - " << j << endl;
				outp(i);
				cout << " ";
				outp(j);
				cout << endl;
			}
		}
	}
}