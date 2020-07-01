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
#define ff fflush(stdout)
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e3 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, u, v, k1, k2, d[N], p[N];
vi adj[N];
set<int> me, you;
void reset()
{
    me.clear(); you.clear();
    for(int i = 0; i < N; i++) {
        d[i] = 0;
        adj[i].clear();
    }
}
void dfs(int u)
{
    for(auto v: adj[u])
    {
        if(v==p[u]) continue;
        p[v]=u;
        d[v]=d[u]+1;
        dfs(v);
    }
}
signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        reset();
        cin >> n;
        for(int i = 1; i < n; i++)
        {
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(1);
        cin >> k1;
        int mnv = -1, mnd = MOD1;
        for(int i = 0; i < k1; i++)
        {
            int x; cin >> x;
            if(d[x]<mnd)
            {
                mnd = d[x];
                mnv = x;
            }
            me.insert(x);
        }
        cin >> k2;
        for(int i = 0; i < k2; i++)
        {
            int x; cin >> x;
            you.insert(x);
        }
        int ret1, ret2, ret3;
        cout << "A " << mnv << endl;
        ff;
        cin >> ret1;
        if(you.find(ret1)!=you.end())
        {
            cout << "C " << mnv << endl;
            ff;
            continue;
        }
        cout << "B " << *(you.begin()) << endl;
        ff;
        cin >> ret2;
        int flag=0;
        int curr = ret2;
        while(curr!=0)
        {
            if(me.find(curr)!=me.end())
            {
                flag=curr;
                break;
            }
            curr = p[curr];
        }
        if(flag)
        {
            cout << "A " << flag << endl;
            ff;
            cin >> ret3;
            if(you.find(ret3)!=you.end())
            {
                cout << "C " << flag << endl;
            }
            else
            {
                cout << "C " << -1 << endl;
            }
            ff;
            continue;
        }
        cout << "C " << -1 << endl;
        ff;
    }
}