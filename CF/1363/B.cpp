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
using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, cnt[N][2];
string s;
void solve()
{
    cin >> s;
    int l = s.length();
    cnt[0][0] = s[0]=='0';
    cnt[0][1] = s[0]=='1';
    int mn = INF;
    for(int i = 1; i < l; i++)
    {
        cnt[i][0] = cnt[i-1][0] + (s[i]=='0');
        cnt[i][1] = cnt[i-1][1] + (s[i]=='1');
       // cout << i << " " << cnt[i][0] << cnt[i][1] << endl;
    }
    for(int i = 0; i < l; i++)
    {
        int f0, f1;
        f0 = cnt[i][1] + cnt[l-1][0] - cnt[i][0];
        f1 = cnt[i][0] + cnt[l-1][1] - cnt[i][1];
        mn = min(mn, f0);
        mn = min(mn, f1);
    }
    cout << mn << endl;
}
signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}