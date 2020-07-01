#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
using namespace std;
const int N=3e5+5, INF=1e9;
int n, p[N], q[N], segt[4*N], ans[N], pos[N];
set<int> St;
void build(int idx, int l, int r)
{
    if(l==r)
    {
        segt[idx]=p[l];
        return;
    }
    int mid = (l+r)/2;
    build(idx*2, l, mid);
    build(idx*2+1, mid+1, r);
    segt[idx]=min(segt[idx*2], segt[idx*2+1]);
}
int query(int idx, int l, int r, int s, int e)
{
    if(l>e || r<s) return -INF;
    if(l==r) return segt[idx];
    int mid = (l+r)/2;
    int lv = query(idx*2, l, mid, s, e);
    int rv = query(idx*2+1, mid+1, r, s, e);
    return min(lv, rv);
}
void update(int idx, int l, int r, int s, int e, int val)
{
    if(l>x || r<x) return;
    propogate();
    if(l==r)
    {
        segt[idx]=INF;
        return;
    };
    int mid = (l+r)/2;
    update(idx*2, l, mid, x, val);
    update(idx*2+1, mid+1, r, x, val);
    segt[idx]=min(segt[idx*2], segt[idx*2+1]);
}
signed main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> p[i];
        pos[p[i]]=i;;
    }
    for(int i = 1; i <= n; i++) cin >> q[i];
    int mx = -1, it = 0;
    for(int i = n; i >= 1; i--)
    {
        int ispos = query(1, 1, n);
        if(ispos<0)
        {
            update(1, 1, n, pos[i], pos[i], 1);
            continue;
        }
        
    }
    for(int i = 1; i<=n; i++)
    {
        cout << ans[i] << " ";
    }
}