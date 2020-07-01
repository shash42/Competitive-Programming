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

const int N =  105, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, a[N], sum[N];
char mat[N][N];
void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            mat[i][j]='.';
        }
    }
    int ans=0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i-1]+a[i];
        if(sum[i-1] > i-1) ans = max(ans, sum[i-1]-(i-1));
        else if(i > sum[i]) ans = max(ans, i-sum[i]);
    }
    ans+=1;
    if(a[1]==0 || a[n]==0)
    {
        cout << "IMPOSSIBLE";
        return;
    }
    cout << ans;
    for(int i = 1; i <= n; i++)
    {
        char slash = '/';
        int take = sum[i-1]-(i-1);
        if(sum[i]<i)
        {
            slash = '\\';
            take = i - sum[i];
        }
        for(int j = ans; j > ans-take; j--)
        {
            mat[j][i]=slash;
        }
    }
    for(int i = ans; i >= 1; i--)
    {
        cout << endl;
        for(int j = 1; j <= n; j++)
        {
            cout << mat[i][j];
        }
    }
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
    };
}