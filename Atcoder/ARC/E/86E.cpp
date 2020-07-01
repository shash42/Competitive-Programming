#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define lint long long
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
const int N=2e5+5, MOD=1e9+7;
using namespace std;
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int n, p[N], lst[N], mxd[N], mxd2[N], d[N];
vector<int> dp[N][2], cnt[N], adj[N];
inline int modpow(lint base, int exp, int modulo) {
  base %= modulo;  lint result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulo;
    base = (base * base) % modulo; exp >>= 1;
  }
  return result;
}
void dfsinit(int u)
{
    vector<int> depths;
    depths.pb(d[u]);
    for(auto v: adj[u])
    {
        d[v]=d[u]+1;
        dfsinit(v);
        depths.pb(mxd[v]);    
    }
    sort(depths.begin(), depths.end());
    mxd[u] = depths.back();
    if(depths.size() > 1) mxd2[u] = depths[depths.size()-2];
    else mxd2[u] = d[u];
}
void dfs(int u)
{
    dp[u][1].pb(1);
    cnt[u].pb(1);
    vector<int> p0;
    for(int i = 0; i <= mxd2[u]-d[u]; i++)
    {
        p0.pb(1);
        if(i) cnt[u].pb(0);
        if(i) dp[u][1].pb(0);
    }
    vector<int> lsts;
    for(auto v: adj[u])
    {
        dfs(v);
        for(int i = d[u]+1; i <= min(mxd2[u], mxd[v]); i++)
        {
            lsts.pb(lst[i]);
            p0[i-d[u]]*=dp[lst[i]][0][i - d[lst[i]]];
            p0[i-d[u]]%=MOD;
            cnt[u][i-d[u]]+=cnt[lst[i]][i - d[lst[i]]];
        }
    }
    int itr=0;
    for(auto v: adj[u])
    {
        for(int i = d[u]+1; i <= min(mxd[v], mxd2[u]); i++)
        {
            int curr = p0[i-d[u]];
            curr*=dp[lsts[itr]][1][i - d[lsts[itr]]];
            curr%=MOD;
            curr*=modpow(dp[lsts[itr]][0][i - d[lsts[itr]]], MOD-2, MOD);
            curr%=MOD;
            dp[u][1][i-d[u]]+=curr;
            dp[u][1][i-d[u]]%=MOD;
            itr++;
        }
    }
    for(int i = d[u]; i <= mxd2[u]; i++)
    {   
        dp[u][0].pb((modpow(2, cnt[u][i-d[u]], MOD) - dp[u][1][i-d[u]] + MOD)%MOD); 
        lst[i]=u;
        // cout << u << " " << cnt[u][i-d[u]] << endl;
      //  cout << i << " - " << dp[u][0][i] << " " << dp[u][0][i] << endl;
    }
}
signed main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> p[i];
        adj[p[i]].pb(i);
    }
    d[0]=0;
    dfsinit(0);
    dfs(0);
    int ans = 0;
    for(int i = 0; i <= mxd[0]; i++)
    {
     //   cout << i << " - " << " " << dp[lst[i]][1][i - d[lst[i]]] << " " << n+1 - cnt[lst[i]][i - d[lst[i]]] << endl;
        ans+=dp[lst[i]][1][i - d[lst[i]]]*modpow(2, n+1 - cnt[lst[i]][i - d[lst[i]]], MOD);
        ans%=MOD;
    }
    //cout << cnt[0][4] << endl;
    cout << ans;
}