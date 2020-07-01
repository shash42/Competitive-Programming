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
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5 + 5;

int n, vis[N], x[N], v[N], facvis[N];
vi adj[N], fac[N], facnd[N], facts;
lint val[N];
void preproc()
{
    for(int i = 1; i < N; i++)
    {
        fac[i].pb(i);
        for(int j = 2; j*j <= i; j++)
        {
            if(i%j) continue;
            fac[i].pb(j);
            if(j*j!=i) fac[i].pb(i/j);
        }
    }
}
void dfs(int u) {
    vis[u] = 1;
    vector<lint> copfac, szfac;
    for(int i = 0; i < fac[x[u]].size(); i++)
    {
        int fact = fac[x[u]][i];
        if(facvis[fact]==0)
        {
            facvis[fact] = 1;
            facts.pb(fact);
        }
        copfac.pb(val[fact]);
        szfac.pb(facnd[fact].size());
    }
    for (auto vv: adj[u]) {
        if (!vis[vv]) {
            dfs(vv);
        }
    }
    for(int i = 0; i < fac[x[u]].size(); i++)
    {
        int fact = fac[x[u]][i];
        lint subtchnj = val[fact] - copfac[i];
        if(v[u] >= subtchnj)
        {
            while(facnd[fact].size()!=szfac[i]) facnd[fact].pop_back();
            facnd[fact].pb(u);
            val[fact] = copfac[i] + v[u];
        }
    }
}
void reset()
{
    for(int i = 1; i <= n; i++)
    {
        vis[i]=0;
        adj[i].clear();
    }
    for(auto fact: facts)
    {
        facnd[fact].clear();
        facvis[fact]=0;
        val[fact]=0;
    }
}
signed main()
{
    fastio;
    preproc();
    int t;
    scanf("%d", &t);
    while(t--)
    {
        cin >> n;
        for(int i = 0; i < n-1; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].pb(v);
            adj[v].pb(u);
        }
        for(int i = 1; i <= n; i++)
        {
            scanf("%d" "%d", &x[i], &v[i]);
        }
        dfs(1);
        lint ans = 0, gcd = 0;
        for(auto fact: facts)
        {
            if(val[fact]*fact > ans){
                ans = val[fact]*fact;
                gcd=fact;
            }
        }
        printf("%lld %lld\n%d\n", ans, gcd, (int) facnd[gcd].size());
        for(auto node: facnd[gcd])
        {
            printf("%d ", node);
        }
        printf("\n");
        reset();
    }
}