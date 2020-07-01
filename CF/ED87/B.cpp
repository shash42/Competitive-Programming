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

string s;
void solve()
{
    int p1=-1e6, p2=-1e6, p3=-1e6, mn=MOD1;
    cin >> s;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i]=='1') p1=i;
        if(s[i]=='2') p2=i;
        if(s[i]=='3') p3=i;
        int lst = min(p1, p2);
        lst = min(lst, p3);
        mn = min(mn, i-lst+1);
    }
    if(mn>s.length())
    {
        cout << 0 << endl;
        return;
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