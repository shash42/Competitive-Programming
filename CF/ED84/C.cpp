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
const int N=202, MOD=1e9+7;
const lint INF=1e18;
using namespace std;
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int n, m, k, sx[N], sy[N], ex[N], ey[N];
string ans="";
signed main()
{
    cin >> n >> m >> k;
    int mxy=-1, mxx = -1;
    for(int i = 1; i <= k; i++)
    {
        cin >> sx[i] >> sy[i];
        mxy=max(mxy, sy[i]);
        mxx=max(mxx, sx[i]);
    }
    for(int i = 1; i <= k; i++)
    {
        cin >> ex[i] >> ey[i];
    }
    //cout << mxx << " " << mxy << endl;
    for(int i = 1; i < mxx; i++)
    {
        ans+='U';
    }
    for(int i = 1; i < mxy; i++)
    {
        ans+='L';
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            if(i%2) ans+='R';
            else ans+='L';
        }
        if(i!=n) ans += 'D';
    }
    cout << ans.length() << endl;
    cout << ans;
}