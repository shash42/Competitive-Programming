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
#define vi vector<int>
#define sz(x) (int)x.size()
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int N=1e5+5, MOD=1e9+7;
const lint INF=1e18;

#define int long long 

using namespace std;
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int t, n, g, b;
signed main()
{
    fastio;
    cin >> t;
    while(t--)
    {
        int ans = 0;
        cin >> n >> g >> b;
        int curr = 0;
        int k = n/2;
        int div = k/b;
        int modd = k%b;
        curr += div*(g+b); //the cycles of good + bad taken with some < b remaining bad days
        curr += g + modd;
     //   cout << div << " " << curr << " " << modd << endl;
        if(n<=curr) //this no. of days it can get directly
        {
            cout << n << endl;
            continue;
        }
        int days = (div+1)*(g+b);
        // all bad days have been used
        int rem = n - curr;
        //cout << days << " " << rem << endl;
        int nxt1 = rem/g;
        int modd2 = rem%g;
        if(modd2==0)
        {
            days += (nxt1-1) * (g+b);
            days += g;
            cout << days << endl;
            continue;
        }
        else
        {
            days += nxt1 * (g+b);
            days += modd2;
            cout << days << endl;
            continue;
        }
    }
}