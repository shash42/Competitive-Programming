#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define pii pair<int, int>
#define ld long double
#define inlld(x) scanf("%lld", &x)
#define ind(x) scanf("%d", &x)
#define vi vector<int>

const int N=1e5+5;
const int MOD=1e9+7;

using namespace std;
using namespace __gnu_pbds;

template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n, k;
pii arr[N];
ordered_set< pii > s;

struct comp
{
	bool operator()(const pii &a, const pii &b)
	{
		return a.S < b.S;
	}
};
signed main()
{
	int ans=0;
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i].F >> arr[i].S;
	}
	sort(arr, arr+n, comp());
	for(int i = 0; i < n; i++)
	{
		if (s.size() && (*s.find_by_order(0)).F <= arr[i].F)
		{
			//cout << i << " " << arr[i].F << " " << arr[i].S << " --- " << s.order_of_key(mp(arr[i].F+1, 0)) << " " << (*(s.find_by_order(s.order_of_key(mp(arr[i].F+1, 0))))).F << endl;
			s.erase(s.find_by_order(s.order_of_key(mp(arr[i].F+1, 0))-1));
		}
		if(s.size() < k)
		{
			//cout << ans << endl;
			s.insert(mp(arr[i].S, i));
			ans++;
		}
	}
	cout << ans;
	return 0;
}