#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
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

int t, n, vis[26], pos[26], deg[26];
string s, ans;
set<int> adj[26];
void resett()
{
    ans="";
    for(int i = 0; i < 26; i++)
    {
        vis[i]=deg[i]=0; 
        pos[i]=-2;
        adj[i].clear();
    }
}
void dfs(int u)
{
    vis[u]=1;
    ans+='a'+u;
    pos[u]=ans.length()-1;
    for(auto v: adj[u])
    {
        if(!vis[v])
        {
            dfs(v);
        }
    }
}
bool check()
{
    for(int i = 1; i < n; i++)
    {
        int dist = pos[s[i]-'a'] - pos[s[i-1]-'a'];
        if(dist==-1 || dist==1)
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}
signed main()
{
    fastio;
    cin >> t;
    while(t--)
    {
        bool flag=true;
        cin >> s;
        n = s.length();
        resett();
        for(int i = 1; i < n; i++)
        {
            adj[s[i]-'a'].insert(s[i-1]-'a');
            adj[s[i-1]-'a'].insert(s[i]-'a');
        }
        for(int i = 0; i < 26; i++)
        {
            deg[i]=adj[i].size();
            if(deg[i]>2)
            {
                cout << "NO" << endl;
                flag=false;
                break;
            }
        }
        if(!flag)
        {
            continue;
        }
        for(int i = 0; i < 26; i++)
        {
            if(!vis[i] && deg[i]==1)
            {
                dfs(i);
            }
        }
        for(int i = 0; i < 26; i++)
        {
            if(!vis[i])
            {
                ans+=('a'+i);
                pos[i]=ans.length()-1;
                vis[i]=1;
            }
        }
        flag = check();
        if(flag)
        {
            cout << "YES" << endl;
            cout << ans << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}