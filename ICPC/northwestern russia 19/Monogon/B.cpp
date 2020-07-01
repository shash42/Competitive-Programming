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

const int N = 1003, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, m, comps;
string mat[N];
bool vis[N][N];
void dfs(int i, int j)
{
    if(i<0 || i>=n || j<0 || j>=m) return;
    if(vis[i][j]) return;
    if(mat[i][j]=='.') return;
    vis[i][j]=true;
    dfs(i+1, j);
    dfs(i, j+1);
    dfs(i, j-1);
    dfs(i-1, j);
}
bool isbr, isbc;
signed main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> mat[i];
    }
    for(int i = 0; i < n; i++)
    {
        int state = 0;
        for(int j = 0; j < m; j++)
        {
            if(state==0 && mat[i][j]=='#')
            {
                state=1;
            }
            else if(state==1 && mat[i][j]=='.')
            {
                state=2;
            }
            else if(state==2 && mat[i][j]=='#')
            {
                cout << -1;
                return 0;
            }
        }
        if(state==0) isbr=true;
    }
    for(int j = 0; j < m; j++)
    {
        int state = 0;
        for(int i = 0; i < n; i++)
        {
            if(state==0 && mat[i][j]=='#')
            {
                state=1;
            }
            else if(state==1 && mat[i][j]=='.')
            {
                state=2;
            }
            else if(state==2 && mat[i][j]=='#')
            {
                cout << -1;
                return 0;
            }
        }
        if(state==0) isbc=true;
    }
    if(isbr^isbc)
    {
        cout << -1;
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!vis[i][j] && mat[i][j]=='#')
            {
                comps++;
                dfs(i, j);
            }
        }
    }
    cout << comps;
}