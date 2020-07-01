#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long
#define pii pair<int, int>
#define mp make_pair
using namespace std;
using namespace __gnu_pbds;
using ordered_set = tree< pii , null_type, less< pii >, rb_tree_tag, tree_order_statistics_node_update>;
const int N=2e5+5;
ordered_set S;
int n, k, arr[N], pref[N],ans=0;
signed main()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		arr[i]-=k;
		pref[i]=pref[i-1]+arr[i];
	}		
	S.insert(mp(0, 0));
	for(int i = 1; i <= n; i++)
	{
		ans+=S.order_of_key(mp(pref[i], i));
		S.insert(mp(pref[i], i));
		//cout << i << " " << ans << endl;
	}
	cout << ans;
}