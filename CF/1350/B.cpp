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
const lint INF = 1e18;

int n, k, a[N], p[N];
map<int, int> m;
void solve()
{
    m.clear();
    cin >> n >> k;
    p[0]=0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(n==1)
        {
            if(a[1]==0) cout << "yes\n";
            else cout << "no\n";
            return;
        }
        if(a[i]<k) a[i]=-1;
        else a[i]=1;
        p[i]=p[i-1]+a[i];
    }
    m[0]=0;
    int lst0=-1;
    for(int i = 1; i <= n; i++)
    {
        if(a[i]==0) lst0=i;
        if(m.find({p[i]-1, eve})!=m.end())
        {
            int prv = m[{p[i]-1, eve}];
            if(prv < lst0 && prv < i-1)
            {
                cout << "yes\n";
                return;
            }
        }
        if(m.find({p[i], odd})!=m.end())
        {
            int prv = m[{p[i], odd}];
            if(prv < lst0 && prv<i-1)
            {
                cout << "yes\n";
                return;
            }
        }
        if(m.find({p[i], eve})==m.end())
        {
            m[{p[i], eve}]=i;
        }
    }
    cout << "no\n";
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