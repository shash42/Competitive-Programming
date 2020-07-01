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

const int N=1e5+5, MOD=1e9+7;
const lint INF=1e18;

struct psrt
{
    bool operator()(const pii &a, const pii &b)
    {
        return a.F > b.F;
    }
};

int n, m, t, mn[N], a[N];
pii l[N];
signed main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> l[i].F;
        l[i].S = i;
    }
    bool ans = true;
    mn[0] = INF;
    for(int i = 1; i <= m; i++)
    {
        mn[i] = min(mn[i-1], n - i - l[i].F + 2);
    }
    int suff = 0, curr=0;
    bool flag=false;
    for(int i = m; i >= 1; i--)
    {
        if(flag)
        {
            a[i] = n - i - l[i].F + 2;
            if(a[i]<=0) flag=false;
            continue;
        }
        a[i] = curr + 1;
        curr+=l[i].F;
        if(curr >= mn[i-1] - 1)
        {
            flag=true;
        }
    }
    if(flag==false)
    {
        cout << -1;
        return 0;
    }
    for(int i = 1; i <= m; i++)
    {
        cout << a[i] <<  " "; 
    }
}