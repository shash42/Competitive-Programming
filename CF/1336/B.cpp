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

const int N = 1e5 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 4e18;

int arr[3][N], n[3], ans = INF;
set<int> sst[3];
void compute(int a, int b, int c)
{
    //cout << a << " " << b << " " << c << endl;
    int comp = (b-a)*(b-a) + (c-b)*(c-b) + (c-a)*(c-a);
    if(ans > comp)
    {
        ans = comp;
    }
}
void solv2(int mid, int y, int d, int r, int xx)
{
    auto itl = sst[y].upper_bound(mid);
    auto itr = sst[y].lower_bound(mid);
    if(d==1) itr = sst[y].upper_bound(mid);
    if(itl!=sst[y].begin())
    {
        itl--;
        compute(r, xx, *itl);
    }
    if(itr!=sst[y].end())
    {
        compute(r, xx, *itr);
    }
}
void solve(int x, int y)
{
    for(int i = 0; i < n[0]; i++)
    {
        auto itl = sst[x].upper_bound(arr[0][i]);
        auto itr = sst[x].lower_bound(arr[0][i]);
        if(itl!=sst[x].begin()) {
            itl--;
            int lo = *itl;
            int mid = (lo + arr[0][i]);
            solv2(mid / 2, y, mid % 2, arr[0][i], lo);
        }
        if(itr!=sst[x].end())
        {
            int hi = *itr;
            int mid = (hi + arr[0][i]);
            solv2(mid/2, y, mid%2, arr[0][i], hi);
        }
    }
}
signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ans = INF;
        cin >> n[0] >> n[1] >> n[2];
        for(int i = 0; i < 3; i++)
        {
            sst[i].clear();
            for(int j = 0; j < n[i]; j++)
            {
                cin >> arr[i][j];
                if(i!=0) sst[i].insert(arr[i][j]);
            }
        }
        solve(1, 2);
        solve(2, 1);
        cout << ans << endl;
    }
}