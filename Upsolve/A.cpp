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

const int K = 52, N = 2e5 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int pw[52], ans[K];
int c2(int x)
{
    return (x*(x+1))/2;
}
signed main()
{
    pw[0]=1;
    for(int i = 1; i < K; i++)
    {
        pw[i]=pw[i-1]*2;
    }
    int q;
    cin >> q;
    while(q--)
    {
        int a, b, m, k;
        cin >> a >> b >> m;
        bool flag=false;
        for(int i = 0; i < K; i++)
        {
            if(pw[i]*(a+1)>b) break;
            if(pw[i]*(a+1)<=b && pw[i]*(a+m)>= b)
            {
                flag=true;
                k = i;
                break;
            }
        }
        if(!flag)
        {
            cout << -1 << endl;
            continue;
        }
        int curr = b - pw[k]*a;
       //cout << curr << " " << endl;
        ans[0]=a;
        for(int i = 1; i <= k+1; i++)
        {
            ans[i]=pw[i-1]*a;
        }
        int pref = 0, cumpref=0;
        for(int i = 1; i <= k+1; i++)
        {
            int fut = c2(k+1-i);
            int cando = curr-fut;
            int lol = k+1-i+1;
            int now = cando / lol + (cando%lol!=0);
            now = min(now, m);            pref = cumpref + now;
            curr -= (k+1-i)*now;
            ans[i] += pref;
            cumpref += pref;
        }
        cout << k+2 << " ";
        cout << ans[0] << " ";
        for(int i = 1; i <= k+1; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}