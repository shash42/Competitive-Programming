#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define pb push_back
#define F first
#define S second
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

const int N = 2e5 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, a[N], ans[N], cnt[N];
set<int> pq;
void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for(int i = 0; i <= 2*n; i++)
    {
        pq.insert(i);
    }
    for(int i = n; i >= 1; i--)
    {
        pq.erase(a[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        ans[i]=(*pq.begin());
        pq.erase(pq.begin());
        cnt[a[i]]--;
        if(!cnt[a[i]]){
            pq.insert(a[i]);
        }
    }
    pq.clear();
    for(int i = 0; i <= n; i++)
    {
        pq.insert(i);
    }
    for(int i = 1; i <= n; i++)
    {
        if(pq.find(ans[i])!=pq.end())
        {
            pq.erase(ans[i]);
        }
        //cout << a[i] << " " << *pq.begin() << endl;
        if(a[i]!=(*pq.begin()))
        {
            cout << -1;
            return;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
}
signed main()
{
    int t= 1;
    while(t--)
    {
        solve();
    }
}