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
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b, a%b);
}
int n, a[N], b[N], pw[N], cnt=1, a0=0, b0=0, ab0=0;
map<pii, int> st;
set<pii> done;
vector<pii> v;
signed main()
{
    pw[0]=1;
    for(int i = 1; i < N; i++)
    {
        pw[i] = (pw[i-1]*2)%MOD1;
    }
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        if(a[i]==0 && b[i]==0)
        {
            ab0++;
            continue;
        }
        if(a[i]==0)
        {
            a0++;
            continue;
        }
        if(b[i]==0)
        {
            b0++;
            continue;
        }
        int g = gcd(abs(a[i]), abs(b[i]));
        a[i]/=g; b[i]/=g;
        if(a[i]*b[i]>0)
        {
            a[i]=abs(a[i]);
            b[i]=abs(b[i]);
        } else{
            a[i]=-abs(a[i]);
            b[i]=abs(b[i]);
        }
        st[{a[i], b[i]}]++;
    }
    for(auto it: st)
    {
        if(done.find(it.F)!=done.end()) continue;
      //  cout << it.F.F << " " << it.F.S << " - " << it.S << " " << st[{it.F.S, -it.F.F}] << endl;
        v.pb({it.S, st[{it.F.S, -it.F.F}]});
        done.insert({it.F.S, -it.F.F});
    }
    for(auto p: v)
    {
        int mult = (pw[p.F] + pw[p.S]) % MOD1;
        mult = (mult - 1 + MOD1)%MOD1;
   //     cout << mult << endl;
        cnt*=mult;
        cnt%=MOD1;
    }
    //cout << a0 << " " << b0 << endl;
    int zero = (pw[a0] + pw[b0] - 1 + MOD1)%MOD1;
    cnt*=zero;
    cnt%=MOD1;
    cnt = (cnt + ab0 -1 + MOD1)%MOD1;

    cout << cnt;
}