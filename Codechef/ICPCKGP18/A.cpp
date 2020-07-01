#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define f first
#define s second
#define lint long long
#define mp make_pair
#define pii pair<int, int>
#define pll pair<lint, lint>
#define ld long double
#define inlld(x) scanf("%lld", &x)
#define ind(x) scanf("%d", &x)
#define vi vector<int>

const int N=1e5+5;
const int MOD=1e9+7;
const lint INF=1e18;

using namespace std;
using namespace __gnu_pbds;

template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int cnt[3], a[N];
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, ans=0;
		cnt[0]=0, cnt[1]=0, cnt[2]=0;
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
			cnt[a[i]%3]++;
		}
		for(int i = 0; i < n; i++)
		{
			if(a[i]%3==0)
			{
				if(cnt[2]!=0 || cnt[1]!=0) ans++;
			}
			else if(a[i]%3==1)
			{
				if(cnt[2]!=1 || cnt[1]!=1) ans++;
			}
			else ans++;
		}
		cout << ans << endl;
	}
	return 0;
}