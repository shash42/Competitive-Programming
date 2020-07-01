#include<bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define vvi vector < vector < int > >
#define pii pair<int, int>
#define F first
#define S second
#define mp make_pair

using namespace std;

const int N=2e5+5, LOG=20;
int dsu[N], low[N], T=1, vis[N];
struct edge
{
    int u, v;
    bool isb;
} E[N];
inline int adjnd(int e, int u) {   return E[e].u ^ u ^ E[e].v; }
int fnd(int x)
{
    if(dsu[x]==x) return x;
    return dsu[x]=fnd(dsu[x]);
}
void merge(int a, int b) {  dsu[fnd(a)]=fnd(b); }
int dfsb(vector<int> g[N], edge E[N], int u, int pe)
{
    vis[u]=1;
    low[u]=T++;
    int mxb = low[u];
    for(auto e: g[u])
    {
        int cu = adjnd(e, u);
        if(!vis[cu]) mxb = min(mxb, dfsb(g, E, cu, e));
        else if(e!=pe) mxb=min(mxb, low[cu]);
    }
    if(mxb == low[u] && pe!=-1) E[pe].isb=true;
    else if(pe!=-1) merge(E[pe].u, E[pe].v);
    return mxb;
}
vvi BridgeTree(vector<int> g[N], edge E[N], int n, int m) //edges must be 1-indexed
{
    T=1;
    vvi btree;
    btree.resize(n+1);
    for(int i = 1; i <= n; i++)
    { 
        vis[i]=0;
        dsu[i]=i;
    }
    for(int i = 1; i <= n; i++) if(!vis[i]) dfsb(g, E, i, -1);
    for(int i = 1; i <= n; i++) dsu[i]=fnd(i);
    for(int i = 1; i <= m; i++)
    {
        if(dsu[E[i].u]!=dsu[E[i].v])
        {
            btree[dsu[E[i].u]].pb(dsu[E[i].v]);
            btree[dsu[E[i].v]].pb(dsu[E[i].u]);
        }
    }
    return btree;    
}
int n, m, q, mark[N][2], subt[N][2], height[N], binpar[N][LOG];
vector<int> g[N];
int lca(int u, int v)
{
    if(height[u]<height[v])
        swap(u, v);
    int log=log2(height[u]);
    for(int a=log; a>=0; a--)
        if(height[u]-(1<<(a))>=height[v])
            u=binpar[u][a];
    if(u==v)
        return u;
    for(int a=log; a>=0; a--)
        if(binpar[u][a]!=binpar[v][a])
            u=binpar[u][a], v=binpar[v][a];
    return binpar[u][0];
}
void lcaprecomp()
{
    for(int i = 1; i < LOG; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            binpar[j][i]=binpar[binpar[j][i-1]][i-1];
        }
    }
}
void dfsinit(vvi &btree, int u)
{
    vis[u]=1;
    height[u]=height[binpar[u][0]]+1;
    for(auto v: btree[u])
    {
        if(!vis[v])
        {
            binpar[v][0]=u;
            dfsinit(btree, v);
        }
    } 
}
bool dfsfin(vvi &btree, int u)
{
    bool ret=true;
    subt[u][0]=mark[u][0];
    subt[u][1]=mark[u][1];
    for(auto v: btree[u])
    {
        if(v!=binpar[u][0])
        {
            ret = ret && dfsfin(btree, v);
            subt[u][0]+=subt[v][0];
            subt[u][1]+=subt[v][1];
        }
    }
    if(!ret) return false;
    if(subt[u][0]!=0 && subt[u][1]!=0) return false;
    return true; 
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> q;
    for(int i = 1; i <= m; i++)
    {
        cin >> E[i].u >> E[i].v;
        g[E[i].u].pb(i);
        g[E[i].v].pb(i);
    }
    vvi btree;
    btree = BridgeTree(g, E, n, m);
    /*for(int i = 1; i <= n; i++)
    {
        for(auto v: btree[i])
        {
            cout << i << " " << v << endl;
        }
    }*/
    for(int i = 1; i <= n; i++) vis[i]=0;
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            binpar[i][0]=0;
            dfsinit(btree, i);       
        }
    }
    lcaprecomp();
    bool ans = true;
    for(int i = 1; i <= q; i++)
    {
        int u, v;
        cin >> u >> v;
        int du = dsu[u], dv = dsu[v];
        int l = lca(du, dv);
     //   cout << l << " " << du << " " << dv << endl;
        if(l==0)
        {
            ans = false;
        }
        mark[l][0]-=1, mark[l][1]-=1;
        mark[du][0]+=1, mark[dv][1]+=1;
    }
    for(int i = 1; i <= n; i++)
    {
        if(binpar[i][0]==0)
        {
            ans = ans && dfsfin(btree, i);       
        }
    }
    if(ans) cout << "Yes";
    else cout << "No";
}