#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;
const int N=2e5+5, MX=3e18;
int n, k, arr[N], ans=0, num[N], ind[N];
vector< pii > nums;
signed main()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}	
	nums.pb(mp(0, 0));
	int j = 1;
	while(j<=n)
	{
		if(arr[j]==1)
		{
			int cnt=0;
			while(j<=n && arr[j]==1)
			{	
				ind[j]=cnt;
				num[j]=nums.size();
				cnt++;
				j++;
			}
			nums.pb(mp(1, cnt));
		}
		else
		{
			num[j]=nums.size();
			nums.pb(mp(arr[j], 1));
			j++;
		}
	}
	for(int i = 1; i <= n; i++)
	{	
		int P=arr[i], S=arr[i];
		if(P==S*k) ans++;
		if(arr[i]==1)
		{
			S=ind[i]+1;
		}	
		for(int j = num[i]-1; j >= 1; j--)
		{
			if(P>=MX/nums[j].F) break;
			if(nums[j].F==1)
			{
				if(P%k==0 && P>k*S && P<=k*(S+nums[j].S)) //check if ans can be plusd in this comp of 1s
				{	
					ans++;
				}
				S+=nums[j].S;
			}
			else
			{
				P*=nums[j].F;
				S+=nums[j].F;
				if(P==k*S) ans++;
			}
		}
	}
	cout << ans;
}