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

const int N = 1e5+5, MOD1 = 1e9 + 7, MOD2 = 998244353, B=17;
const lint INF = 1e18;

int a[N];
void solve()
{
    int n, d;
    cin >> n >> d;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    int curr = a[1], st = 1;
    int mx = 0, mxi = 0;
    for(int i = 1; i <= n; i++)
    {
        if(a[i]==curr) continue;
        int eqn = i - st;
        if(eqn>mx)
        {
            mx = eqn;
            mxi = st;
        }
        curr = a[i];
        st = i;
    }
    int eqn = n+1 - st;
    if(eqn>mx)
    {
        mx = eqn;
        mxi = st;
    }
    if(mx>=d)
    {
        cout << 0;
        return;
    }
    if(mx==2)
    {
        set<int> stt;
        for(int i = 1; i <= n; i++)
        {
            stt.insert(a[i]);
        }
        for(int i = 1; i <= n; i++)
        {
            if(stt.find(a[i]*2)!=stt.end())
            {
                cout << 1;
                return;
            }
        }
        if(mxi<n-1) cout << 1;
        else cout << 2;
        return;
    }
    if(mx==1)
    {
        if(d==2)
        {
            cout << 1;
            return;
        }
        set<int> stt;
        for(int i = 1; i <= n; i++)
        {
            stt.insert(a[i]);
        }
        for(int i = 1; i <= n; i++)
        {
            if(stt.find(a[i]*2)!=stt.end())
            {
                cout << 1;
                return;
            }
        }
        cout << 2;
        return;
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
    }
}