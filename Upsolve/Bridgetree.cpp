int dsu[N], low[N], T=1, vis[N];
struct edge //put edges using this struct
{
    int u, v;
    bool isb; //sets to true if this is a bridge
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
{ //g[u] has edges from u
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