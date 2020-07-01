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

const int D = 18, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

pii dp[D][2][2][1025][181];
pii emp = {-1, -1};
lint l, r, pw[D];
int t[D], k, tl;
void memeset()
{
    for(int i = 0; i < D; i++) for(int j = 0; j < 2; j++) for(int ii = 0; ii < 2; ii++) for(int jj = 0; jj < 1025; jj++) for(int kk = 0; kk < 181; kk++) dp[i][j][ii][jj][kk] = {-1, -1};
}
void setfor(lint x)
{
    int i;
    for(i = 0; i < D; i++)
    {
        t[i] = x%10;
        x/=10;
        if(x==0LL) break;
    }
    tl = i;
    for(int j = 0; j <= i/2; j++)
    {
        swap(t[i - j], t[j]);
    }
    /*for(int j = 0; j <= tl; j++)
    {
        cout << t[j];
    }
    cout << endl;*/
}
pii solve(int dig, int eq, int n0, int mask, int sum)
{
    if(__builtin_popcount(mask) > k) return {0, 0};
    if(dig>tl)
    {
        return {0, 1};
    }
    if(dp[dig][eq][n0][mask][sum] != emp) return dp[dig][eq][n0][mask][sum];
    pii curr = {0, 0};
    int mxd = 9;
    if(eq) mxd = t[dig];
    for(int i = 0; i <= mxd; i++)
    {
        int n0c = (i>0);
        n0c = n0 | n0c;
        int nmask = mask;
        if(n0c) nmask |= (1<<i);
        int eqc = 0;
        if(eq && i==mxd) eqc=1;
        pii ret = solve(dig+1, eqc, n0c, nmask, sum + i);
        curr.F += (ret.F + ( (lint) i*(pw[tl-dig]*ret.S)%MOD2)%MOD2)%MOD2;
        curr.F %= MOD2;
        curr.S = (curr.S + ret.S)%MOD2;
    }
  //  cout << dig << " " << eq << " " << n0 << " " << mask << " " << sum << " - " << curr.F << " " << curr.S << endl;
    dp[dig][eq][n0][mask][sum] = curr;
    return curr;
}
signed main()
{
    cin >> l >> r >> k;
    pw[0] = 1;
    for(int i = 1; i < D; i++)
    {
        pw[i] = (pw[i-1]*10)%MOD2;
    }
    setfor(r);

    memeset();
    pii ans1 = solve(0, 1, 0, 0, 0);
    memeset();
    setfor(l-1);
    pii ans2 = solve(0, 1, 0, 0, 0);
    int ans = (ans1.F - ans2.F + MOD2)%MOD2;
    //cout << ans1.F << " " << ans2.F << endl;
    cout << ans;
}