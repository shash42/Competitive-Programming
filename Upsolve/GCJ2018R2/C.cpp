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

const int N = 102, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, a[N][N], row[N], col[N], it, cnt[2][N][2*N], ans;
void count()
{
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cnt[0][i][a[i][j]]++;
            cnt[1][j][a[i][j]]++;
        }
    }
}
void upd()
{
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(row[i] || col[j] || a[i][j]==n) continue;
            if(cnt[0][i][a[i][j]]>1 && cnt[1][j][a[i][j]]>1)
            {
                ans++;
                cnt[0][i][a[i][j]]--;
                cnt[1][j][a[i][j]]--;
                a[i][j]=n;
                row[i]=1; col[j]=1;
            }
        }
    }
}
void solve()
{
    ans = 0;
    cin >> n;
    it = 10*n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            a[i][j]+=n;
        }
    }
    for(int itr = 1; itr <= it; itr++)
    {
        count();
        upd();
    }
    count();

    for(int dim = 0; dim < 2; dim++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j <= 2*n; j++)
            {
                if(j==n) continue;
                if(cnt[dim][i][j]>1) ans+=cnt[dim][i][j]-1;
            }
        }
    }
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
    };
}