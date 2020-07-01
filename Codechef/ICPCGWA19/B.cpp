#include<bits/stdc++.h>

using namespace std;

const int N=102, W=1e4;

int n, p[N], w[N], pp[N], wp[N];

int query(int i, int j)
{
	cout << 1 << " " << i << " " << j << endl;
	fflush(stdout);
	int x;
	cin >> x;
	return x;
}
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		p[i]=query(i, W)-pp[i-1];
		pp[i]=pp[i-1]+p[i];
		int low = wp[i-1]+1, high = wp[i-1]+100, ans;
		while(true)
		{
			if(high-low<=1)
			{
				if(query(i, low)==pp[i])
				{
					ans=low;
				}
				else ans = high;
				break;
			}
			int mid=(low+high)/2;
			int ret = query(i, mid);
			if(ret==pp[i])
			{
				high = mid;
			}
			else
			{
				low=mid+1;
			}
		}
		wp[i]=ans;
		w[i]=wp[i]-wp[i-1];
	}
	cout << 2 << endl;
	fflush(stdout);
	for(int i = 1; i <= n; i++)
	{
		cout << w[i] << " ";
	}
	cout << endl;
	fflush(stdout);
	for(int i = 1; i <= n; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;
	fflush(stdout);
}