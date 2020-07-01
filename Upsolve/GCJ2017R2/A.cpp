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

const int N = 1e2 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, p, g[N], cnt[5];
void solve()
{
    cin >> n >> p;
    for(int i = 0; i <= 4; i++)
    {
        cnt[i]=0;
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> g[i];
        cnt[g[i]%p]++;
    }
    int ans, mid = 4, l=4, r=4;
    if(p==4)
    {
        mid = 2; l = 1; r = 3;
    }
    else if(p==2) mid = 1;
    else if(p==3)
    {
        l = 1; r = 2;
    }
    ans = cnt[0]; cnt[0]=0; //0 vale saare fresh shuru me
    ans += cnt[mid]/2; cnt[mid]%=2; //half vale next kha hi lenge (1/2 efficiency)
    if(cnt[l]<cnt[r]) //l, r next (1/2 efficiency)
    {
        ans+=cnt[l];
        cnt[r]-=cnt[l];
        cnt[l]=0;
    } else{
        ans+=cnt[r];
        cnt[l]-=cnt[r];
        cnt[r]=0;
    }
    ans+=cnt[l]/p; ans+=cnt[r]/p; //(l r me jo zyada tha vo 1/p efficiency)
    cnt[l]%=p; cnt[r]%=p;
    if(cnt[mid])
    {
        if(cnt[l]>=2 || cnt[r]>=2)
        {
            if(cnt[l]>=2) cnt[l]-=2;
            if(cnt[r]>=2) cnt[r]-=2;
            cnt[mid]=0, ans++;
        }
    }
    if(cnt[1] || cnt[2] || cnt[3]) ans++;
    cout << ans;
}
signed main()
{
    int T;
    cin >> T;
    int t = T;
    while(t--)
    {
        cout << "Case #" << T-t << ": ";
        solve();
        cout << endl;
    }
}