#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pii pair<int, int>
#define pll pair<lint, lint>
#define ld long double
#define inlld(x) scanf("%lld", &x)
#define ind(x) scanf("%d", &x)
#define vi vector<int>

const int N=1e5+5;
const int MOD=1e9+7;

using namespace std;
using namespace __gnu_pbds;

template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n, l, dp[N], vis[N], mod=1e9+7;
vector<int> adj[N];
set<int> S;
void dfs(int u)
{
    vis[u]=1;
    for(auto v: adj[u])
    {
        if(v<=l)
        {
            if(!vis[v]) dfs(v);
            dp[u]+=dp[v];
            dp[u]%=mod;
        }
        else
        {
            S.insert(v);
            dp[u]+=1;
            dp[u]%=mod;
        }
    }
}
signed main()
{
    cin >> n >> l;
    for(int i = 1; i <= l; i++)
    {
        int k;
        cin >> k;
        for(int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            adj[i].pb(x);
        }
    }
    dfs(1);
    cout << dp[1] << " " << S.size();
}