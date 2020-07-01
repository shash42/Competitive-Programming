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

const int N = 1e3 + 3, MOD1 = 1e9 + 7, MOD2 = 998244353;
const int INF = 1e9+1;

int n, m, xN, yN, hs[N], he[N], hy[N], vs[N], ve[N], vx[N];
lint ans;
vi xs, ys;
vector<pii> delta{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool inff, vis[3*N][3*N], ml[3*N][3*N], mr[3*N][3*N], md[3*N][3*N], mu[3*N][3*N];

int rankinx(int x)
{
    return lower_bound(all(xs), x) - xs.begin();
}
int rankiny(int x)
{
    return lower_bound(all(ys), x) - ys.begin();
}
queue<pii> q;
void bfs(int y, int x)
{
    q.push({y, x});
    //cout << y << " - " << x << endl;
    vis[y][x]=true;
    while(q.size())
    {
        pii p = q.front();
        y = p.F; x = p.S;
        q.pop();
        if(x==0 || x==xN-1 || y==0 || y==yN-1)
        {
            inff=true;
            return;
        }
        ans += ((lint)(xs[x+1] - xs[x]))*(ys[y+1] - ys[y]);
        for(int i = 0; i < 4; i++)
        {
            if(i==0 && mu[y][x]) continue;
            if(i==1 && md[y][x]) continue;
            if(i==2 && ml[y][x]) continue;
            if(i==3 && mr[y][x]) continue;
            int nx = x + delta[i].S, ny = y + delta[i].F;
            if(vis[ny][nx]) continue;
            vis[ny][nx]=true;
            q.push({ny, nx});
        }
    }
}
signed main()
{
    //n=1000, m=1000;
    //int cnt=0;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        //hs[i]=cnt++; he[i]=cnt++; hy[i]=cnt++;
        cin >> hs[i] >> he[i] >> hy[i];
        xs.pb(hs[i]); xs.pb(he[i]);
        ys.pb(hy[i]);
    }
    for(int i = 0; i < m; i++)
    {
        //vx[i]=cnt++; vs[i]=cnt++; ve[i]=cnt++;
        cin >> vx[i] >> vs[i] >> ve[i];
        ys.pb(vs[i]); ys.pb(ve[i]);
        xs.pb(vx[i]);
    }
    xs.pb(-INF); xs.pb(INF);
    ys.pb(-INF); ys.pb(INF);
    sort(all(xs)); sort(all(ys));
    xs.resize(unique(all(xs)) - xs.begin());
    ys.resize(unique(all(ys)) - ys.begin());
    xN = xs.size(); yN = ys.size();
    for(int i = 0; i < n; i++)
    {
        int l = rankinx(hs[i]), r = rankinx(he[i]);
        int y = rankiny(hy[i]);
        for(int j = l; j < r; j++)
        {
            md[y-1][j]=true; mu[y][j]=true;
        }
    }
    for(int i = 0; i < m; i++)
    {
        int u = rankiny(vs[i]), d = rankiny(ve[i]);
        int x = rankinx(vx[i]);
        for(int j = u; j < d; j++)
        {
            mr[j][x-1]=true; ml[j][x]=true;
        }
    }
    int stx = rankinx(0)-1, sty = rankiny(0)-1;
    bfs(sty, stx);
    if(inff)
    {
        cout << "INF"; return 0;
    }
    cout << ans;
    return 0;
}