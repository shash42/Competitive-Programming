#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define F first
#define S second
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
const lint LINF=1e18;

using namespace std;
using namespace __gnu_pbds;

template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n, a[N], nxt[N], suff[N];
stack< pii > stk;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			while(stk.size() && stk.top().S<=a[i])
			{
				nxt[stk.top().F]=i;
				stk.pop();
			}
			stk.push(mp(i, a[i]));
		}
		a[n+1]=MOD;
		while(stk.size())
		{
			nxt[stk.top().F]=n+1;
			stk.pop();
		}
		suff[n+1]=0;
		for(int i = n; i >= 1; i--)
		{
			suff[i]=suff[nxt[i]]+1;
		}
	//	for(int i = 1; i <= n; i++) cout << suff[i] << " ";
	//		cout << endl;
		int pref=0, lstnum=0, rptr=2;
		for(int i = 1; i <= n; i++)
		{
			int curr = pref;
			if(rptr==i) rptr++;
			while(a[rptr]<lstnum) rptr++;
			curr+=suff[rptr];
			ans=max(ans, curr);
	//		cout << i << " " << curr << endl;
			if(a[i]>=lstnum)
			{
				pref++;
				lstnum=a[i];
			}
		}
		ans = max(ans, pref);
		cout << ans << endl;
	}	
}