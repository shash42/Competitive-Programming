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

const int N = 2e5 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, m, w[N], s[N], visp[N], visfd[N];
pii food[N];
vi adj[N];

int other(int fid, int i)
{
    return fid ^ food[i].F ^ food[i].S;
}
signed main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> food[i].F >> food[i].S;
        s[food[i].F]++; s[food[i].S]++;
        adj[food[i].F].pb(i); adj[food[i].S].pb(i);
    }
    vi ans;
    queue<int> tpsrt;
    for(int i = 1; i <= n; i++)
    {
        if(s[i]<=w[i])
        {
            tpsrt.push(i);
            visfd[i] = 1;
        }
    }
    while(!tpsrt.empty())
    {
        int fd = tpsrt.front();
        tpsrt.pop();
        for(auto p: adj[fd]){
            if(visp[p]) continue;
            ans.pb(p);
            visp[p] = 1;
            int v = other(fd, p);
            if(!visfd[v]){
                s[v]--;
                if(s[v]<=w[v]){
                    tpsrt.push(v);
                    visfd[v]=1;
                }
            }
        }
    }
    reverse(all(ans));
    if(ans.size()!=m) cout << "DEAD";
    else{
        cout << "ALIVE\n";
        for(auto u: ans)
        {
            cout << u << " ";
        }
    }
}