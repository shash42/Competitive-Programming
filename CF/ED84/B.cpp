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
const int N=1e5+5, MOD=1e9+7;
const lint INF=1e18;
using namespace std;
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int t, n, k[N], vis[N], mch[N], cnt;
vi adj[N];
signed main()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            adj[i].clear();
            vis[i]=mch[i]=0;
            cnt=0;
            cin >> k[i];
            for(int j = 1; j <= k[i]; j++)
            {
                int x;
                cin >> x;
                adj[i].pb(x);
            }
        }
        for(int i = 1; i <= n; i++)
        {
            for(auto p: adj[i])
            {
                if(!vis[p])
                {
                    vis[p]=1;
                    mch[i]=p;
                    cnt++;
                    break;
                }
            }
        }
        if(cnt==n)
        {
            cout << "OPTIMAL\n";
            continue;
        }
        int lftp, dot;
        for(int i = 1; i <= n; i++)
        {
            if(!vis[i])
            {
                lftp=i;
                break;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            if(!mch[i])
            {
                dot = i;
                break;
            }
        }
        if(dot!=0 && lftp!=0)
        {
            cout << "IMPROVE\n";
            cout << dot << " " << lftp << endl;
        }
        else
        {
            cout << "OPTIMAL\n";
        }
        
    }
}