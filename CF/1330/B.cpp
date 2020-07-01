#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define F first
#define S second
#define int long long
#define lint long long
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N=2e5+5, MOD=1e9+7;
const lint INF=1e18;
set<int> s;
int n, a[N], t, l[N], r[N];
vector<int> ans;
signed main()
{
    cin >> t;
    while(t--)
    {
        ans.clear();
        s.clear();
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            l[i]=0;
            r[i]=0;
        }
        for(int i = 1; i <= n; i++)
        {
            s.insert(i);
        }
        for(int i = 1; i <= n; i++)
        {
            s.erase(a[i]);
            if(*s.begin() == i+1)
            {
                l[i]=1;
            }
        }
        s.clear();
        for(int i = 1; i <= n; i++)
        {
            s.insert(i);
        }
        for(int i = n; i >= 1; i--)
        {
            s.erase(a[i]);
            if(*s.begin() == n - i + 2)
            {
                r[i]=1;
            }
            if(l[i-1] && r[i])
            {
                ans.pb(i-1);
            }
        }
        cout << ans.size() << endl;
        for(auto i: ans)
        {
            cout << i << " " << n-i << endl;
        }
    }
}