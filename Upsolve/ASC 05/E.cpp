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

const int S = 182, L = 19, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int cnt[S], dp[L][S][2], pow10[L], n, kk, dn, dk, sumcnt[S];
vi numdigits(int x)
{
    vi num;
    while(x)
    {
        num.pb(x%10);
        x/=10;
    }
    reverse(all(num));
    return num;
}
void digitdp(int len, vi &num) //find count of numbers <= value of num[], num_digits = len
{
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i < num[0]; i++)       dp[0][i][0]=1;
    dp[0][num[0]][1]=1;
    for(int i = 1; i < len; i++) {
        for(int j = 0; j < S; j++)
        {
            for(int dig = 0; dig <= min(j, 9LL); dig++)
            {
                dp[i][j][0] += dp[i-1][j-dig][0];
                if(dig < num[i]) dp[i][j][0] += dp[i-1][j-dig][1];
            }
            if(j>=num[i]) dp[i][j][1] = dp[i-1][j-num[i]][1];
        }
    }
    for(int i = 1; i < S; i++){
        cnt[i] = dp[len-1][i][0] + dp[len-1][i][1];
    }
}
int setsizeofk(int len, int k)
{
    if(len==18) return 1e18;
    if(len==dk) return k - 1;
    int x = k;
    if(len>dk)  {
        while(x < pow10[len-1]) x*=10;
        x-=1; //as 95600 > 956
    }
    else while(x >= pow10[len]) x/=10; //as 95 < 956  so no x-=1
    return x;
}
int solve(int k)
{
    dk = numdigits(k).size();
    int sumk = 0, tmp = k, ans = 0;
    while(tmp){
        sumk += tmp%10; tmp/=10;
    }
    for(int i = 1; i <= dn; i++)
    {
        vi num = numdigits(min(pow10[i]-1, n));
        digitdp(i, num);
        for(int j = 1; j < sumk; j++) ans += cnt[j];
        //cout << i << " " << ans << endl;
        int mn = n;
        mn = min(mn, setsizeofk(i, k));
        num = numdigits(mn);
        digitdp(i, num);
        ans += cnt[sumk];
        //cout << i << " " << ans << endl;
    }
    return ans+1;
}
signed main()
{
    pow10[0] = 1;
    for(int i = 1; i < L; i++) pow10[i] = pow10[i-1]*10;
    cin >> n >> kk;
    dn = numdigits(n).size();
    int ans1 = solve(kk), ans2=0;

    for(int i = 1; i <= n; i++)
    {

    }

    for(int i = 1; i <= dn; i++)
    {
        int lo = pow10[i-1], hi = min(pow10[i]-1, n);
        while(lo<=hi)
        {
            int mid = (lo+hi)/2;
            int ret = solve(mid);
            cout << lo << " " << hi << " " << mid << " " << ret << endl;
            if(ret==kk){
                ans2=mid;
                break;
            }
            else if(ret<kk) lo = mid+1;
            else hi = mid-1;
        }
    }
    if(ans2==0) exit(7);
    cout << ans1 << endl << ans2;
}