#include<bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define int long long

using namespace std;

const int N = 5002, M = 1e5+5, INF=1e9;
struct edge
{
    int use, u, v, w, idx;
} e[M];
struct edgesrt
{
    bool operator()(const edge &a, const edge &b)
    {
         if(a.w==b.w) //dont know what the fuck to use as tiebreaker no proof 
        {
            return a.u < b.u;
        }
        return a.w < b.w;
    }
};
int n, m, k, ans, par[N], lo = 0, hi = 0;
int fnd(int x)
{
    if(par[x]==x) return x;
    return par[x]=fnd(par[x]);
}
void uni(int a, int b)
{
    par[b]=a;
}
int chk(int x)
{
    int ret = 0, cnt = 0;
    for(int i = 0; i < m; i++)
    {
        e[i].use = 0;
        if(e[i].u==1)
        {
            e[i].w += x;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        par[i]=i;
    }
    sort(e, e+m, edgesrt());
    for(int i = 0; i < m; i++)
    {
        int up = fnd(e[i].u);
        int vp = fnd(e[i].v);
        if(up!=vp)
        {
            if(e[i].u == 1)
            {
                if(ret==k) continue; //this can lead to obvious fuckups_/|\_
                ret++;
            }
            e[i].use=1;
            cnt++;
            uni(up, vp);
        }
    }
    for(int i = 0; i < m; i++)
    {
        if(e[i].u==1) e[i].w -= x;
    }
    if(cnt!=n-1) return INF; //is this right? i really dont know lmao
    return ret;
}
signed main()
{
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++)
    {
        cin >> e[i].u >> e[i].v >> e[i].w;
        e[i].idx = i+1;
        if(e[i].u > e[i].v) swap(e[i].u, e[i].v);
        hi = max(e[i].w, hi);
        if(e[i].u==1)
        {
            lo = max(lo, e[i].w);
        } 
    }
    lo = -lo;
    lo-=1;
    hi+=1;
    //cout << lo << " " << hi << endl;
    while(true)
    {
        if(hi-lo<=1)
        {
            if(chk(hi)==k)
            {
                ans = hi;
                break;
            }
            ans = lo;
            break;
        }
        int mid = (lo+hi)/2;
      //  cout << lo << " " << hi << " " << mid << " - " << chk(mid) << endl;
        if(chk(mid)>=k)
        {
            lo = mid;
        }
        else
        {
            hi = mid-1;
        }
    }
    int lolz = chk(ans);
 //   cout << ans << " - " << lolz << endl;
    if(lolz!=k)
    {
        cout << -1;
        return 0;
    }
    int cst = 0;
    for(int i = 0; i < m; i++)
    {
        if(e[i].use==1) cst++;
    }
    cout << cst << endl;
    for(int i = 0; i < m; i++)
    {
        if(e[i].use==1) cout << e[i].idx << " ";
    }
}