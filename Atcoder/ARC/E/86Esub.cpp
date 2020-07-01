#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define lint long long
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
const int N=2e3+5, MOD=1e9+7;
using namespace std;
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int n, p[N], dp[N][N][2], cnt[N][N];
vector<int> adj[N];
inline int modpow(lint base, int exp, int modulo) {
  base %= modulo;  lint result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulo;
    base = (base * base) % modulo; exp >>= 1;
  }
  return result;
}
void dfs(int u, int d)
{
    dp[u][d][1]=1;
    cnt[u][d]=1;
    vector<int> p0(n+1);
    for(int i = 0; i <= n; i++)
    {
        p0[i]=1;
    }
    for(auto v: adj[u])
    {
        dfs(v, d+1);
        for(int i = 0; i <= n; i++)
        {
            p0[i]*=dp[v][i][0];
            p0[i]%=MOD;
            cnt[u][i]+=cnt[v][i];
        }
    }
    for(auto v: adj[u])
    {
        for(int i = d+1; i <= n; i++)
        {
            if(cnt[v][i]==0) break;
            int curr = p0[i];
            curr*=dp[v][i][1];
            curr%=MOD;
            curr*=modpow(dp[v][i][0], MOD-2, MOD);
            curr%=MOD;
            dp[u][i][1]+=curr;
            dp[u][i][1]%=MOD;
        }
    }
    //cout << "node: " << u << endl;
    for(int i = d; i <= n; i++)
    {   
        dp[u][i][0] = (modpow(2, cnt[u][i], MOD) - dp[u][i][1] + MOD)%MOD; 
      //  cout << i << " - " << dp[u][i][0] << " " << dp[u][i][1] << endl;
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
    dfs(0, 0);
    int ans = 0;
    for(int i = 0; i <= n; i++)
    {
        if(i<=7) cout << i << " - " << dp[0][i][1] << " " << n+1 - cnt[0][i] << endl;
        ans+=dp[0][i][1]*modpow(2, n+1 - cnt[0][i], MOD);
        ans%=MOD;
    }
    cout << ans;
}
