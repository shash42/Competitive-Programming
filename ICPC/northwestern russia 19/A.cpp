#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define f first
#define s second
#define lint long long
#define mp make_pair
#define pii pair<int, int>
#define pll pair<lint, lint>
#define ld long double
#define inlld(x) scanf("%lld", &x)
#define ind(x) scanf("%d", &x)
#define vi vector<int>

const int N=2e5+5;
const int MOD=1e9+7;
const lint INF=1e18;

lint _add(lint x, lint y)
{
    lint ret=x+y;
    while(ret<0LL)
        ret+=MOD;
    return ret;
}

lint _mult(lint x, lint y)
{
    x%=MOD;
    y%=MOD;
    lint ret=x*y;
    ret%=MOD;
    while(ret<0LL)
        ret+=MOD;
    return ret;
}

using namespace std;
using namespace __gnu_pbds;

template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n, m, taim, vis[N], cnt[N];
vi adj[N], teams;
queue<int> q;
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        vis[i]=-1;
        cnt[i]=0;
    }
    for(int i = 0; i < n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i = 1; i <= m; i++)
    {
        int c;
        cin >> c;
        teams.pb(c);
        vis[c]=0;
        cnt[c]=1;
        q.push(c);
    }
    while(q.size())
    {
        int u = q.front();
    //    cout << u << " " << cnt[u] << endl;
        q.pop();
        taim = max(taim, vis[u]);
        for(auto v: adj[u])
        {
            if(vis[v]!=-1)
            {
                if(vis[v]==taim+1)
                {
                    cnt[v]+=cnt[u];    
                }
            }
            else
            {
                cnt[v]+=cnt[u];
                vis[v]=taim+1;
                q.push(v);
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
      //  cout << cnt[i] << " ";
        if(cnt[i]==m)
        {
            cout << "YES\n";
            cout << i;
            return 0;
        }
    }
    cout << "NO";
	return 0;
}