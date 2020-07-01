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

const int N = 5e5 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int A, B, C, D, cnt[N];
void solve()
{
    int ans = 0;
    cin >> A >> B >> C >> D;
    int a = B-A; int b = C-B; int d = D-C+1;
    if(a>b) swap(a, b);
    for(int i = 0; i <= a+b; i++)
    {
        if(i<=a) cnt[i] = i+1;
        else if(i>a && i <= b) cnt[i] = a+1;
        else
        {
            cnt[i] = a+b-i+1;
        }
    }

    for(int i = 0; i <= a+b; i++)
    {
        int c = A+B+i;
        int mult = max(0LL, c-C);
        mult = min(mult, d);
        ans += mult*cnt[i];
    }
    cout << ans;
}
signed main()
{
    solve();
}