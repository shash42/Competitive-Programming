#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define f first
#define lint long long
#define mp make_pair
#define pii pair<int, int>
#define pll pair<lint, lint>
#define ld long double
#define inlld(x) scanf("%lld", &x)
#define ind(x) scanf("%d", &x)
#define vi vector<int>

const int N=1e3+5;
const int MOD=1e9+7;
const lint INF=1e18;


using namespace std;
using namespace __gnu_pbds;

double x1, x2, x3, a, k ; 
vector < double > xx ;
#define PR 0.00001 

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(3) ;

	int t; cin >> t ;
	while(t--)
	{
		cin >> a >> k ; xx.clear();
		cin >> x1 >> x2 >> x3 ; 
		xx.pb(x1); xx.pb(x2); xx.pb(x3); sort(xx.begin(), xx.end());
		x1 = xx[0] ; x2 = xx[1] ; x3 = xx[2] ; double mid = (x1 + x3)/2.0 ;
		x1 = min(x1 + k, mid); x3 = max(x3 - k, mid);

		double newX1 = x1 + a/2.0 ; double newX3 = x3 - a/2.0 ;
		if((newX1 - newX3) <= PR)
		{
			cout << 0.00 << endl ;
			continue ; 
		} 
		double low = min((x1 + a/2.0), (x3 - a/2.0));
		double high = max((x1 + a/2.0), (x3 - a/2.0));
		double ans = a * (high - low) ;
		cout << ans << endl ; 
	}	
}