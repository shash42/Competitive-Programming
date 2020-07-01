#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define F first
#define S second
#define int long long
#define lint long long
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define SET(x, val) memset(x, val, sizeof(x))
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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

const int N=2e5+5, MOD=1e9+7;
const lint INF=1e18;

int n, a[N], b[N], p[N];
deque<int> q;
bool sorted()
{
    for(int i = 0; i < n; i++)
    {
        if(q[i]!=i+1) return false;
    }
    return true;
}
signed main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int mx = -1e9;
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
        p[b[i]] = i;
    }
    int stat = 0;
    for(int i = 1; i <= n; i++)
    {
        if(stat==0 && b[i]==1)
        {
            stat=1;
        }
        else if(stat==1 && b[i]!=b[i-1]+1)
        {
            stat=2;
            break;
        }
    }
    if(stat==1)
    {
        int ans = n - b[n];
        bool flag=false;
        for(int i = b[n] + 1; i <= n; i++)
        {
            if(p[i] >= i - b[n]) 
            {
                flag=true;
                break;
            }   
        }
        if(!flag)
        {
            cout << ans;
            return 0;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        mx = max(p[i] - i + n + 1, mx);
    }
    cout << mx;
}