#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;
const int N=1e5+5;
int arr[N];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q;
	cin >> q;
	while(q--)
	{
		int n, r, mv=0;
		cin >> n >> r;
		for(int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr+n);
		int i = 1;
		while(i<n)
		{
			if(arr[i]==arr[i-1])
			{
				int tmp=arr[i-1];
				while(i<n && arr[i]==tmp)
				{
					arr[i]=-1;
					i++;
				}
				i--;
			}
			i++;
		}
		int cnt=0, lptr=0, rptr=n-1;
		while(arr[rptr]==-1) rptr--;
		while(lptr<=rptr)
		{
			cnt++;
			rptr--;
			while(rptr>=0 && arr[rptr]==-1) rptr--;
			mv+=r;
			while(lptr<n && (arr[lptr]==-1 || arr[lptr]<=mv))
			{
				lptr++;
			}
		}
		cout << cnt << endl;
	}	
}