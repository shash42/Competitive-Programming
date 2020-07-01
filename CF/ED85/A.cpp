#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define f first
#define s second
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
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5+5, MOD=1e9+7;
int p[N], c[N], n, m, t;

signed main()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        bool flag=true;
        for(int i = 1; i <= n; i++)
        {
            cin >> p[i] >> c[i];
        }   
        p[0]=c[0]=0;
        for(int i = 1; i <= n; i++)
        {
            if(c[i]-c[i-1]>p[i]-p[i-1])
            {
                flag=false;
                break;
            }
            if(p[i]<p[i-1] || c[i]<c[i-1])
            {
                flag=false;
                break;
            }
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
}