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

const int N = 102, M=1003, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, m, x, y, nw;
string mat[N];
void solve()
{
    int cst=0;
    nw=0;
    cin >> n >> m >> x >> y;
    for(int i = 0; i < n; i++)
    {
        cin >> mat[i];
        for(int j = 0; j < m; j++)
        {
            if(mat[i][j]=='.') nw++;
        }
        mat[i][m]='*';
    }
    if(2*x<=y)
    {
        cout << x*nw << endl;
        return;
    }
    for(int i = 0; i < n; i++)
    {
        int cnt = 0;
        for(int j = 0; j <= m; j++)
        {
            if(mat[i][j]=='.') cnt++;
            else{
                cst += (cnt/2)*y;
                cst += (cnt%2)*x;
                cnt=0;
            }
        }
    }
    cout << cst << endl;
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