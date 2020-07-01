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

int n, a[N], p[N], x;
signed main()
{
    cin >> n;
    int ceil = n/2 + n%2;
    for(int i = 1; i <= ceil; i++)
    {
        cin >> a[i];
        p[i]=p[i-1]+a[i];
    }
    cin >> x;
    for(int i = ceil + 1; i <= n; i++)
    {
        a[i]=x;
        p[i]=p[i-1]+x;
    }
    if(x>=0)
    {
        if(p[n]>0)
        {
            cout << n;
        } else
        {
            cout << -1;
        }
        return 0;
    }
    bool flag=true;
    ceil = n/2 + 1;
    for(int i = 0; i < n; i++)
    {
        if(i+ceil>n) break;
        if(p[i+ceil]-p[i] <= 0)
        {
            flag=false;
            break;
        }
    }
    if(flag)
    {
        cout << ceil;
    } else{
        cout << -1;
    }
}