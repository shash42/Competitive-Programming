#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long
#define pb push_back
#define F first
#define S second
#define lint long long
#define mp make_pair
#define pii pair<int, int>
#define pll pair<lint, lint>
#define vi vector<int>
#define sz(x) (int)x.size()
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int N=1e5+5, MOD=1e9+7;
const lint INF=1e18;
using namespace std;
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int t, n, k;
signed main()
{
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        if(n%2 != k%2) cout << "NO\n";
        else if(n>=k*k) cout << "YES\n";
        else cout << "NO\n";
    }
}