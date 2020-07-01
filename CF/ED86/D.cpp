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

const int N = 2e5 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

struct srt
{
    bool operator()(const pii &a, pii &b)
    {
        return a.S > b.S;
    }
};
int n, k, m[N], cnt[N], scnt[N], c[N], mx=0;
vector<int> ans[N];
priority_queue<pii, vector<pii>, srt> pq;
signed main()
{
    fastio;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> m[i];
        cnt[m[i]]++;
    }
    for(int i = 1; i <= k; i++)
    {
        cin >> c[i];
    }
    scnt[k] = cnt[k];
    for(int i = k; i >= 1; i--)
    {
        scnt[i] = scnt[i+1] + cnt[i];
    }
    for(int i = k; i >= 1; i--)
    {
        int cur = scnt[i]/c[i] + (scnt[i]%c[i]!=0);
        while(cur > mx)
        {
            mx++;
            pq.push({mx, 0});
        }
        for(int j = 0; j < cnt[i]; j++)
        {
            pii bst = pq.top();
            pq.pop();
            ans[bst.F].pb(i);
            bst.S+=1;
            pq.push(bst);
        }
    }
    cout << mx << endl;
    for(int i = 1; i <= mx; i++)
    {
        cout << ans[i].size() << " ";
        for(auto j: ans[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
}