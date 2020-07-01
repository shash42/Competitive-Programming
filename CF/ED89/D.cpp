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

const int N = 5e5 + 5, M = 1e7+5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

bool p[M];
int n, a[N], in[M], a1[N], a2[N];
vector<int> pf[N];

signed main()
{
    fastio;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        in[a[i]]=i;
    }
    for(int i = 2; i < M; i++)
    {
        if(p[i]) continue;
        for(int j = i; j < M; j+=i)
        {
            p[j] = true;
            if(in[j])
            {
                pf[in[j]].pb(i);
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        a1[i]=a2[i]=-1;
        if(pf[i].size()<2) continue;
        if(pf[i][0]!=2)
        {
            a1[i] = pf[i][0];
            a2[i] = pf[i][1];
            continue;
        }
        a1[i] = 2;
        while(a[i]%2==0) a[i]/=2;
        a2[i] = a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cout << a1[i] << " ";
    }
    cout << endl;
    for(int i = 1; i <= n; i++)
    {
        cout << a2[i] << " ";
    }
}