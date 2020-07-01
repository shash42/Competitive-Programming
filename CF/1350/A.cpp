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

int n, spf[N], cnt[N], a[N];
vector<int> primes;

void spfsieve() {
    for (int i = 1; i < N; i++)
        spf[i] = -1;
    for (int i = 2; i < N; i++) {
        if (spf[i] != -1) continue;
        primes.pb(i);
        for (int j = i; j < N; j += i) if (spf[j] == -1) spf[j] = i;
    }
}
signed main()
{
    spfsieve();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        int tmp = a[i], prv=1, mult=1;
        while(spf[tmp]!=-1)
        {
            if(spf[tmp]!=prv)
            {
                prv=spf[tmp];
                mult=prv;
            }
            else mult*=spf[tmp];
            tmp/=spf[tmp];
          //  cout << i << " " << prv << endl;
            cnt[mult]++;
        }
    }
    int ans=1;
    for(auto p: primes)
    {
        int tmp=p;
        while(tmp<N)
        {
            tmp*=p;
        }
        tmp/=p;
        while(tmp>1)
        {
            if(cnt[tmp]>=n-1)
            {
                ans*=tmp;
                break;
            }
            tmp/=p;
        }
    }
    cout << ans;
}