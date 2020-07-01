#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
const int N=1e5+5, INF=1e9;
using namespace std;
int n, m, k, x, vis[N], deg[N], bad[N];
vector<int> fort, adj[N];
vector<int> ans;
queue<int> q;
bool chk(double x)
{
    ans.clear();
    for(int i = 1; i <= n; i++)
    {
        vis[i]=0;
        bad[i]=0;
    }
    while(!q.empty()) q.pop();
    for(auto u: fort)
    {
        vis[u]=1;
        q.push(u);
    }
    while(q.size())
    {
        int u = q.front();
        q.pop();
        for(auto v: adj[u])
        {
            if(!vis[v])
            {
                bad[v]++;
                if( (deg[v] - (double) bad[v])/deg[v] < x)
                {
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i]) ans.pb(i);
    }
    return (ans.size()>0);
}
signed main()
{
    cout << setprecision(15);
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++)
    {
        cin >> x;
        fort.pb(x);
    }
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        deg[u]++; deg[v]++;
    }
    double lo = 0, hi = 1, pr = 1e-12;
    while(true)
    {
        if(hi-lo<=pr)
        {
            if(chk(hi))
                break;
            else if(chk(lo))
                break;
        }
        double mid = (lo+hi)/2;
        //cout << mid << " - " << chk(mid) << endl;
        if(chk(mid))
        {
            lo = mid;
        }
        else
        {
            hi=mid-pr;
        }
    }
    cout << ans.size() << endl;
    for(auto v: ans)
    {
        cout << v << " ";
    }
}