#include<bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pii pair<int, int>
#define inlld(x) scanf("%lld", &x)
#define gc getchar

const int N=1e5+5, T=2e4+4;

using namespace std;

int n, q, st[N], en[N], tim;
vector<pii>adj[N];

inline void ind(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

int binpar[N][25], height[N];

void dfs(int u, int p, int h)
{
    height[u]=h;
    int anc=1, i=0;
    while(anc<=h)
    {
        if(i==0)
            binpar[u][i]=p;
        else
            binpar[u][i]=binpar[binpar[u][i-1]][i-1];
        anc*=2;
        i++;
    }
    for(int a=0; a<adj[u].size(); a++)
        if(adj[u][a].f!=p)
            dfs(adj[u][a].f, u, h+1);
}

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
    return max(binpar[u][0], 1);
}

int weight_par[N];

void dfs_euler(int u, int p)
{
    st[u]=++tim;
    for(auto v:adj[u])
        if(v.f!=p)
        {
            dfs_euler(v.f, u);
            weight_par[v.f]=v.s;
        }
    en[u]=++tim;
}

inline int lt(int x){return 2*x;}
inline int rt(int x){return 2*x+1;}

int segt[8*N];

void upd(int nd, int s, int e, int idx, int val)
{
    if(s==e)
    {
        segt[nd]=val;
        return;
    }
    int m=(s+e)/2;
    if(m>=idx) upd(lt(nd), s, m, idx, val);
    if(m+1<=idx) upd(rt(nd), m+1, e, idx, val);
    segt[nd]=segt[lt(nd)]+segt[rt(nd)];
}

int quer(int nd, int s, int e, int l, int r)
{
    if(s>r || e<l)
        return 0;
    if(s>=l && e<=r)
        return segt[nd];
    int m=(s+e)/2, q1=0;
    if(m>=l) q1+=quer(lt(nd), s, m, l, r);
    if(m+1<=r) q1+=quer(rt(nd), m+1, e, l, r);
    return q1;
}

vector<pii>updlist[T];
vector<pair<int, pii> >queries[N];
int ans[N];

int main()
{
    ind(n);ind(q);
    for(int a=1; a<n; a++)
    {
        int u, v, w;
        ind(u);ind(v);ind(w);
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    dfs(1, 0, 0);
    dfs_euler(1, 0);
    for(int u=1; u<=n; u++)
    {
        for(auto v:adj[u])
        {
            int w=v.s;
            if(binpar[v.f][0]==u)
            {
                for(int a=1; a*a<=w; a++)
                    updlist[a].pb({v.f, (int) ceil( (float) w/a)});//TRY CHANGING
                int a;
                for(a=1; a*a<=w; a++)
                    updlist[(int) ceil( (float) w/a)].pb({v.f, a});
                if((a-1)*(a-1)!=w)
                {
                  //  cout << w << " - " << a << " " << (int)ceil(w/a) << " " << v.f << endl;
                    updlist[ (int) ceil((float) w/a)].pb({v.f, a});
                }
            }
        }
    }
    for(int a=1; a<=n; a++)
    {
        upd(1, 1, 2*n, st[a], weight_par[a]);
        upd(1, 1, 2*n, en[a], -weight_par[a]);
    }
    // for(int a=1; a<=n; a++)
    //     printf("%d %d\n", a, quer(1, 1, 2*n, st[1], st[a]));
    for(int a=1; a<=q; a++)
    {
        int u, v, t;
        ind(u);ind(v);ind(t);
        queries[t].pb({a, {u, v}});
    }
  //  printf("\n");
    for(int a=1; a<T; a++)
    {
        pii prev={-1, -1};
        for(auto x:updlist[a])
        {
            if(x==prev) continue;
            upd(1, 1, 2*n, st[x.f], x.s);
            upd(1, 1, 2*n, en[x.f], -x.s);
            prev=x;
    //        printf("%d %d %d\n", a, x.f, x.s);
        }
        for(auto x:queries[a])
        {
            int lca_here=lca(x.s.f, x.s.s);
            ans[x.f]=quer(1, 1, 2*n, st[lca_here]+1, st[x.s.s])+quer(1, 1, 2*n, st[lca_here]+1, st[x.s.f]);
        }
    }
    for(int a=1; a<=q; a++)
        printf("%d\n", ans[a]+1);
    return 0;
}