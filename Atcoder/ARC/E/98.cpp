//INCOMPLETE AND MIGHT BE WRONG TRACK


#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second

using namespace std;
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N=1e5+5;
int inf=2e9, n, k, q, arr[N], sarr[N], l[N], r[N], cnt, ptrl, ptrr, vis[N];
void disable(int idx)
{
	for(int i = idx+1; i <= idx+k-1; i++)
	{
		if(vis[i]) continue;
		if(l[i]>idx) break;
		l[i]=idx;
		if(r[i]-idx + idx-l[i] + 1 > K && arr[i] > sarr[ptrl].F && arr[i] <= sarr[ptrr].F)
		{
			vis[i]=1;
			cnt--;
		}
	}
	for(int i = idx-k+1; i < idx; i++)
	{
		if(vis[i]) continue;
		if(r[i]<idx) break;
		r[i]=idx;
		if(r[i]-idx + idx-l[i] + 1 > K)
		{
			vis[i]=1;
			cnt--;
		}
	}
}
int main()
{
	int mn = inf;
	cin >> n >> k >> q;
	for(int i = 0; i < n; i++)
	{
		l[i]=-inf; r[i]=inf;
 		cin >> arr[i];
		sarr[i] = mp(arr[i], i);
	}
	sort(sarr, sarr+n);
	int ptrr = q-1, ptrl=0;
	cnt=q;
	while(ptrl < ptrr && ptrr<n)
	{
		while(cnt>=q)
		{
			mn=min(mn, sarr[ptrr].F - sarr[ptrl]. F);
			cnt--;
			ptrl++;
			disable(sarr[ptrl].S);
		}

	}
	cout << mn;
}