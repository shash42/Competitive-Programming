#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
const int N=1e5+5, INF=1e9;
using namespace std;
int n, ans = 0, d, a, b, cnt;
map<int, int> xpyl;
map<int, int> xmyl;
set<int> vis;
int mult=1;
struct pinhole
{
    int x, y, xpy, xmy;
} ph[N];
int M(int x)
{
    x%=d;
    x+=d;
    x%=d;
    return x;
}
int dfs(int x, map<int, int> &mp)
{
    vis.insert(x);
    int ret = 0;
    if(mp[x-d]!=0 && vis.find(x-d)==vis.end())
    {
        ret += mp[x-d]*mp[x];
        cout << x << " " << x-d << " - " << mp[x] << " " << mp[x-d] << endl;
        ret += dfs(x-d, mp);
    }
    if(mp[x+d]!=0 && vis.find(x+d)==vis.end())
    {
        ret += mp[x+d]*mp[x];
        cout << x << " " << x+d << " - " << mp[x] << " " << mp[x+d] << endl;
        ret += dfs(x+d, mp);
    }
    return ret;
}
signed main()
{
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++)
    {
        cin >> ph[i].x >> ph[i].y;
    }
    d = abs(ph[a].x - ph[b].x) + abs(ph[a].y - ph[b].y);
    for(int i = 1; i <= n; i++)
    {
        ph[i].xpy = (ph[i].x + ph[i].y);
        ph[i].xmy = (ph[i].x - ph[i].y);
        xpyl[ph[i].xpy]++;
        xmyl[ph[i].xmy]++;
    }
    int pva = dfs(ph[a].xpy, xpyl);
    int pvb = dfs(ph[b].xpy, xpyl);
    mult = -1; vis.clear();
    int mva = dfs(ph[a].xmy, xmyl);
    int mvb = dfs(ph[b].xmy, xmyl);
    cout << pva + pvb + mva + mvb << endl;
}