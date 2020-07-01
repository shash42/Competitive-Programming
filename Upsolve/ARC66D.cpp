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

const int B = 65, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int v[B][3], n;
vector<int> N;
void tovec()
{
    N.clear();
    int tmp = n;
    while(tmp)
    {
        N.pb(tmp%2);
        tmp/=2;
    }
    N.pb(0);
    reverse(N.begin(), N.end());
}
int solve()
{
    tovec();
    v[0][0] = 1;
    for(int i = 1; i < N.size(); i++)
    {
        v[i][0] = (v[i-1][0] + v[i-1][1]*(N[i]==0))%MOD1;
        v[i][1] = ((N[i]==1)*v[i-1][0] + v[i-1][1])%MOD1;
        int k2 = 1 + (N[i]==1);
        v[i][2] = (3*v[i-1][2] + k2*v[i-1][1])%MOD1;
    }
    int nn = N.size()-1;
    return (v[nn][0] + v[nn][1] + v[nn][2])%MOD1;
}
signed main()
{
    cin >> n;
    cout << solve();
}
