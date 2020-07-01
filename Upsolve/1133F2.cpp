#include<bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define int long long

using namespace std;

const int N = 5002, M = 1e5+5, INF=1e18;
vi g[N];
struct edge
{
    int u, v, w, use=0;
} e[M];
struct edgesrt
{
    bool operator()(const edge &a, const edge &b)
    {
        return a.w < b.w;
    }
};
vector<edge> possib;
int adj(int i, int u)
{
    return e[i].u ^ e[i].v ^ u;
}
int n, m, k, par[N], mx, mxi, vis[N];
int fnd(int x)
{
    if(par[x]==x) return x;
    return par[x]=fnd(par[x]);
}
void uni(int a, int b)
{
    par[b]=a;
}
stack<int> stk;
bool flag;
set<int> finset;
void dfs(int u, int p)
{
//    cout << "node: " << u << endl;
    vis[u]=1;
    for(auto i: g[u])
    {
        if(i==p) continue;
        int v = adj(i, u);
        if(vis[v])
        {
  //          cout << u << " hit!" << endl;
            if(e[i].use == 1)
            {
                mx = e[i].w;
                mxi = i;
            }
            while(stk.size())
            {
                if(e[stk.top()].use==1)
                {
                    if(mx < e[stk.top()].w)
                    {
                        mxi = stk.top();
                        mx = e[stk.top()].w;
                    }
                }
                stk.pop();
            }
            flag=false;
            return;
        }
        else
        {
            stk.push(i);
            dfs(v, i);
            if(!flag)
            {
                return;
            }
            stk.pop();
        }
    }
}
signed main()
{
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
    {
        par[i]=i;
    }
    for(int i = 0; i < m; i++)
    {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e, e+m, edgesrt());
    int cnt = 0, cst = 0, cnt1 = 0;
    for(int i = 0; i < m; i++)
    {
        int up = fnd(e[i].u);
        int vp = fnd(e[i].v);
        if(up!=vp)
        {
            if(e[i].u == 1 || e[i].v==1)
            {
                if(cnt1==k) continue;
                e[i].use=2;
                cnt1++;
            }
            else e[i].use=1;
           // cout << "cost: " << e[i].w << endl;
            cst+=e[i].w;
            uni(up, vp);
            g[e[i].u].pb(i);
            g[e[i].v].pb(i);
            cnt++;
            finset.insert(i);
        }
    }
    if(cnt<n-1)
    {
        cout << -1;
        return 0;
    }
    for(int i = 0; i < m; i++)
    {
        if((e[i].u==1  || e[i].v==1) && e[i].use==0)
        {
            g[e[i].u].pb(i);
            g[e[i].v].pb(i);
            mx = 0;
            mxi = m;
            while(stk.size()) stk.pop();
            for(int i = 1; i <= n; i++) vis[i]=0;
            flag=true;
            dfs(1, -1);
            possib.pb({i, mxi, e[i].w - mx, 0});
            e[mxi].use = 2; //this edge has been considered for remuv.
    //        cout << i << " " << mx << endl;
            g[e[i].u].pop_back();
            g[e[i].v].pop_back();
        }
    }
    if(possib.size() + cnt1 < k)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    //cout << cst << " " << cnt1 << endl;
    sort(possib.begin(), possib.end(), edgesrt());
    for(int i = 0; i < k-cnt1; i++)
    {
        cst += possib[i].w;
        finset.insert(possib[i].u);
        finset.erase(possib[i].v);
    }
    for(auto it: finset)
    {
        cout << e[it].u << " " << e[it].v << endl;
    }
}