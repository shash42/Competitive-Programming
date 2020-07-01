#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5, A=1e6+5;

int n, pref[N], a[N], q, t[N], ans[A], mx=-1e9;

int query(int jmp)
{
	int ret=0;
	int curr = 0, idx=0;
	while(idx!=n)
	{
		int low = idx+1, high = n;
		while(true)
		{
			if(high-low<=1)
			{
				if(pref[high]-curr<=jmp)
				{
					idx=high;
					break;
				}
				idx=low;
				break;
			}
			int mid = (low+high)/2;
			if(pref[mid]-curr<=jmp)
			{
				low = mid;
			}
			else
			{
				high=mid-1;
			}
		}
		ret++;
		curr=pref[idx];
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		pref[i]=pref[i-1]+a[i];
		mx=max(a[i], mx);
	}
	for(int i = 0; i < A; i++) ans[i]=-1;
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		cin >> t[i];
		if(t[i]<mx)
		{
			cout << "Impossible\n";
			continue;
		}
		if(ans[t[i]]!=-1)
		{
			cout << ans[t[i]] << "\n";
			continue;	
		}
		ans[t[i]] = query(t[i]);
		cout << ans[t[i]] << "\n";
	}
}