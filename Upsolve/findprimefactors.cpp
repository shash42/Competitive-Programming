#include<bits/stdc++.h>
#define pb push_back

using namespace std;

void factorize(int x)
{
	int tmpx=x;
	vector<int> factors;
	for(int i = 2; i*i <= x; i++)
	{
		while(tmpx%i==0)
		{
			tmpx/=i;
			factors.pb(i);
		}
	}
	if(tmpx>1) factors.pb(tmpx);
}

int main()
{
	factorize(100);
}