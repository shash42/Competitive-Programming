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

int n, x, d[2*N], s[2*N];
int nc2(int p)
{
    return p*(p+1)/2;
}
void solve()
{
    cin >> n >> x;
    for(int i = 1; i <= n; i++)
    {
        cin >> d[i];
        s[i]=nc2(d[i]);
        d[n+i]=d[i];
        s[n+i]=s[i];
    }
    int r = 1, ss=0, ans=0, c=0;
    for(int l = 1; l <= n; l++)
    {
        if(x<=d[l])
        {
            int tmps = nc2(d[l]);
            tmps -= nc2(d[l] - x);
            ans=max(ans, tmps);
            continue;
        }
        if(r<l+1)
        {
            r=l+1;
            ss=nc2(d[l]);
            c=d[l];
        }
        while(r<=2*n)
        {
            if(c+d[r]>=x) break;
            c+=d[r];
            ss+=s[r];
            r++;
        }
        int tk = x-c; //jo right pe already hai
        int tmps = ss + nc2(tk); //uska sum
        int lft = d[r]-tk; //jitne right end pe aur daal sakta hun
        int add = min(lft, d[l]); //jitne shift karunga
        tmps += add*tk;
        ans = max(ans, tmps);
        ss-=s[l];
        c-=d[l];
    }
    cout << ans << endl;
}
signed main()
{
    int t = 1;
    while(t--)
    {
        solve();
    }
}