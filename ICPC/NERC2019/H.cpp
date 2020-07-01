#include<bits/stdc++.h>

using namespace std;

int c[10];

void solve(int x, int y)
{
	if(x==0)
	{
		cout << 1;
		y--;
	}
	for(int i = 0; i <= y; i++)
	{
		cout << x;
	}
	cout << endl;
	return;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		for(int i = 0; i < 10; i++)
		{
			cin >> c[i];
		}
		c[0]++;
		int mni = -1, mn=1000000;
		for(int i = 0; i < 10; i++)
		{
			if(c[i] < mn)
			{
				mn=c[i];
				mni=i;
			}
		}
		solve(mni, mn);
	}

}