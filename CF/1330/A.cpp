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
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N=205, MOD=1e9+7;
const lint INF=1e18;

int n, a[N], p[N], t, y;
signed main()
{
    cin >> t;
    while(t--)
    {
        for(int i = 1; i < N; i++)
        {
            a[i]=1;
            p[i]=0;
        }
        cin >> n >> y;
        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a[x]=0;
        }
        int mx = -1;
        for(int i = 1; i < N; i++)
        {
            p[i] = p[i-1] + a[i];
            if(p[i]<=y) mx = max(mx, i);
        }
        cout << mx << endl;
    }
}