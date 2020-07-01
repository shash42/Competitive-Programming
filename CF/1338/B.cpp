#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define f first
#define s second
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
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N=1e5+5, MOD=1e9+7;
const lint INF=1e18;

int n, m, p[N], deg[N], d[N], c[N];
bool l[N];
vector<int> adj[N];
void dfs(int u)
{
    for(auto v: adj[u])
    {
        if(v!=p[u])
        {
            l[u]=true;
            p[v]=u;
            d[v]=d[u]+1;
            dfs(v);
            if(!l[v]) c[u]++;
        }
    }
}
void solve()
{
    cin >> n;
    int root = 0;
    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
        deg[a]++;
        deg[b]++;
        if(root==0)
        {
            if(deg[a]>1) root=a;
            else if(deg[b] > 1) root=b;
        }
    }
    d[root]=0;
    p[root]=root;
    dfs(root);
    bool eve=false, odd=false;
    int cnt = n-1;
    for(int i = 1; i <= n; i++)
    {
        if(l[i])
        {
            //cout << i << " " << c[i] << endl;
            if(c[i]!=0) cnt -= c[i]-1;
            continue;
        }
        if(d[i]%2==0) eve=true;
        else odd=true;
    }
    if(eve && odd)
    {
        cout << 3 << " ";
    }
    else
    {
        cout << 1 << " ";
    }
    cout << cnt;
}
signed main()
{
    int t=1;
    //cin >> t;
    while(t--)
    {
        solve();
    }
}