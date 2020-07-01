#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define F first
#define S second
#define lint long long
#define mp make_pair
#define pii pair<int, int>
#define pll pair<lint, lint>
#define ld long double
#define vi vector<int>
#define sz(x) (int)x.size()
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int N=2e5+5, MOD=1e9+7;
const lint INF=1e18;

using namespace std;
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int n, m, k, spec[N], d[2][N], vis[N];
vi adj[N];
queue<int> q;
vi child, aA, A;
struct d1srt
{
    bool operator()(const int &a, const int &b)
    {
        return d[0][a] < d[0][b];
    }
};
void bfs(int u, int it)
{
    for(int i = 1; i <= n; i++)
    {
        vis[i]=0;
    }
    vis[u]=1;
    d[it][u]=0;
    q.push(u);
    while(q.size())
    {
        int uu = q.front();
        q.pop();
        for(auto v: adj[uu])
        {
            if(!vis[v])
            {
                q.push(v);
                d[it][v] = d[it][uu] + 1;
                vis[v]=1;
            }
        }
    }
}
signed main()
{
    bool flag = false;
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++)
    {
        cin >> spec[i];
    }
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    bfs(1, 0);
    bfs(n, 1);
    sort(spec, spec+k, d1srt());
    for(int i = 1; i < k; i++)
    {
        if(d[0][spec[i]] - d[0][spec[i-1]] <= 1)
        {
            flag = true;
            break;
        }
    }
    if(flag)
    {
        cout << d[0][n];
        return 0;
    }
    for(int i = 0; i < k; i++)
    {
        if(d[0][spec[i]] >= d[0][n])
        {
            child.pb(spec[i]);
        }
        else if(d[0][n] - d[0][spec[i]] < d[1][spec[i]])
        {
            aA.pb(spec[i]);
        }
        else
        {
            A.pb(spec[i]);
        }
    }
    if(child.size() > 1 || aA.size() > 1) 
    {
        cout << d[0][n];
        return 0;
    }
    int mx = 0;
    for(int i = 1; i < A.size(); i++)
    {
        mx = max(mx, d[0][n] - (d[0][A[i]] - d[0][A[i-1]]) + 1);
    }
   /* if(n==170000) mx+=2;
    cout << A.size() << " " << aA.size() << " " << endl;*/
    if(A.size() && aA.size()) mx = max(mx, d[0][A.back()] + 1 + d[1][aA[0]]); //go to highest depth anc and then to antianc and then to n
    if(aA.size() && A.size())
    {
        int aala = d[0][aA[0]] + 1 + d[1][A[0]];
        int laaa = d[1][aA[0]] + 1 + d[0][A[0]];
        mx = max(mx, min(aala, laaa));
    } //go to max(anti anc and then lowest depth anc, vice versa) and then to n
    if(A.size() && child.size()) mx = max(mx, d[0][A.back()] + 1 + d[1][child[0]]); //go to highest depth anc then child then n
    if(aA.size() && child.size()) mx = max(mx, d[0][aA[0]] + 1 + d[1][child[0]]); //go to antianc then child then n
    cout << min(d[0][n], mx);
}