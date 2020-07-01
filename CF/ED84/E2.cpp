#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long
#define pb push_back
#define F first
#define S second
#define lint long long
#define mp make_pair
#define pii pair<int, int>
#define pll pair<lint, lint>
#define vi vector<int>
#define sz(x) (int)x.size()
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int N=2e5+5, MOD=998244353, inv=981274199;
const lint INF=1e18;
using namespace std;
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int n, pw[N], cnt[N];
signed main()
{
    pw[0]=1;
    cin >> n;
    if(n==1)
    {
        cout << 10;
        return 0;
    }
    n+=2;
    for(int i = 1; i < N; i++)
    {
        pw[i]=pw[i-1]*10;
        pw[i]%=MOD;
    }
    for(int i = 1; i <= n; i++)
    {
        cnt[i]=(180*pw[n-i-1])%MOD;
        cnt[i]+=(810*(n-i-1)*pw[n-i-1])%MOD;
        cnt[i]%=MOD;
    }
    for(int i = 1; i < n-2; i++)
    {
        cnt[i]*=inv;
        cnt[i]%=MOD;
    }
    cnt[n-2]=10;
    for(int i = 1; i <= n-2; i++)
    {
        cout << cnt[i] << " ";
    }
}