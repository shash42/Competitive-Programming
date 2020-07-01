#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;
const int N=3e5+15, INF=1e9;
int n, ans[N];
signed main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for(int i = n; i < 3*n; i++)
	{
		arr[i]=arr[i%n];
	}
	int curr=0, mx=-INF, mxind=-1, mxby2=-1;
	while(curr<n)
	{
		mx=-INF, mxind=-1;
		int ptr=curr;
		while(ptr<3*n)
		{
			if(arr[ptr]>=mx)
			{
				mx=arr[curr];
				mxind=ptr;
			}
			if(arr[ptr] <= (mx/2 - (mx%2==0)) )
			{
				for(int i = curr; i <= mxind; i++)
				{
					cout << mxby2
				}
				break;
			}
			ptr++;	
		}
	}
}