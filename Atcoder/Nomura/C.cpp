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
#define SET(x, val) memset(x, val, sizeof(x))
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, l[N], a[N], pw[N], lt[N], rt[N];
signed main()
{
    cin >> n;
    pw[0]=1;
    for(int i = 0; i <= n; i++)
    {
        if(i>=1) pw[i]=min(INF, pw[i-1]*2);
        cin >> l[i];
    }
    lt[n]=l[n], rt[n]=l[n];
    int ans=0;
    for(int i = n-1; i >= 0; i--)
    {
        lt[i] = lt[i+1]/2 + (lt[i+1]%2!=0) + l[i];
        rt[i] = min(rt[i+1] + l[i], pw[i]);
        //cout << lt[i] << " " << rt[i] << endl;
        if(lt[i]>rt[i])
        {
            cout << -1;
            return 0;
        }
    }
    int mx = 1;
    for(int i = 0; i <= n; i++)
    {
        if(mx<lt[i])
        {
            cout << -1;
            return 0;
        }
        int cmax = min(mx, rt[i]);
        ans += cmax;
        mx = (cmax - l[i])*2;
    }
    cout << ans;
}