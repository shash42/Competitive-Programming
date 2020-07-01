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

const int N = 1e5 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, p[N], m, k, cnt, vis[N], ans=2, col[N], col1=0, tot;
vector<int> adj[N];
stack<int> st;

void dfs(int u)
{
    cnt++;
    if(col[u]==1) col1++;
    vis[u]=1;
    st.push(u);
    for(auto v: adj[u])
    {
        if(p[u]==v) continue;
        if(vis[v])
        {
            ans=1;
            tot = v;
            return;
        }
        else if(cnt==k)
        {
            continue;
        }
        else
        {
            p[v]=u;
            col[v] = 1-col[u];
            dfs(v);
        }
        if(ans==1) return;
    }
    st.pop();
}
signed main()
{
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i = 1; i <= n; i++) col[i]=-1;
    col[1]=0;
    dfs(1);
    if(ans==1)
    {
        cout << 2 << endl;
        vector<int> lmao;
        while(st.size())
        {
            lmao.pb(st.top());
            if(st.top() == tot) break;
            st.pop();
        }
        cout << lmao.size() << endl;
        for(auto u: lmao)
        {
            cout << u << " ";
        }
    }
    else
    {
        cout << 1 << endl;
        int find=0;
        if(col1 > k-col1)
        {
            find=1;
        }
        int out=0, req = k/2 + (k%2);
        for(int i = 1; i <= n; i++)
        {
            if(col[i]==find)
            {
                out++;
                cout << i << " ";
            }
            if(out==req) break;
        }
    }
}