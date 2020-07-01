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
const int N=3003, MOD=1e9+7;
const lint INF=1e18;
lint _add(lint x, lint y) {
    lint ret=x+y;
    while(ret<0LL) ret+=MOD;
    return ret;
}
lint _mult(lint x, lint y) {
    x%=MOD; y%=MOD;
    lint ret=x*y;
    ret%=MOD;
    while(ret<0LL) ret+=MOD;
    return ret;
}
inline int modpow(lint base, int exp, int modulo) {
  base %= modulo;  lint result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulo;
    base = (base * base) % modulo; exp >>= 1;
  }
  return result;
}
using namespace std;
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n, k, a[N], lft, mx, pos[3*N], cnt;
vi ans[N*N];
string s;
signed main()
{
  //  fastio;
    scanf("%d %d", &n, &k);
    cin >> s;
    lft=k;
    for(int i = 0; i < n; i++)
    {
        if(s[i]=='L')
        {
            mx+=i-cnt;
            cnt++;
        }
    }
    //cout << mx << endl;
    if(mx<k)
    {
        cout << -1;
        return 0;
    }
    int i=1;
    for(i = 1; i <= min(3*n, k); i++)
    {
        lft--;
        for(int j = 0; j < n-1; j++)
        {
            if(s[j]=='R' && s[j+1]=='L')
            {
                ans[i].pb(j+1);
                mx--;
                if(mx==lft) break;
            }
        }
        for(auto v: ans[i])
        {
            swap(s[v-1], s[v]);
        }
        //cout << i << " - " << mx << endl;
        if(mx==lft) break;
    }
    if(mx>lft)
    {
        cout << -1;
        return 0;
    }
    for(int j = 0; j < n; j++)
    {
        if(s[j]=='L')
        {
            int tj = j;
            while(tj > 0 && s[tj-1]=='R')
            {
                ans[++i].pb(tj);
                swap(s[tj], s[tj-1]);
                tj--;
            }
        }
    }
    for(int i = 1; i <= k; i++)
    {
        printf("%d ", (int)ans[i].size());
        for(auto v: ans[i])
        {
            printf("%d ", v);
        }
        printf("\n");
    }
}