#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define pb push_back
#define F first
#define S second
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

const int N = 1e5 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, m;
vector<int> ver;
vector<int> rpts;
map<int, vector< pii > > hor;
signed main()
{
    cin >> n >> m;
    ver.pb(0);
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        ver.pb(x);
    }
    ver.pb(1e9);
    sort(all(ver));
    for(int i = 1; i <= m; i++)
    {
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        if(x1==1)
        {
            int rnk = upper_bound(ver.begin(), ver.end(), x2) - ver.begin();
            rpts.pb(rnk); //(rnk-1)th vaale tak block kar raha hai
         //   cout << i << " " << rnk << endl;
        }
       // hor[y].pb({x1, x2});
    }
    /*for(auto y: hor)
    {
        vector< pii > yv = y.S;
        sort(yv.begin(), yv.end());
        int st = 0, en = 1;
        if(yv[0].F!=1) continue;
        for(auto xx: yv)
        {
            if(xx.F==en)
        }
    }*/
    sort(all(rpts));
    int ans = MOD1;
    for(int i = 1; i <= n+1; i++)
    {
        int horz = rpts.size() - (upper_bound(all(rpts), i) - rpts.begin());
        ans = min(i-1 + horz, ans);
    }
    cout << ans;
}