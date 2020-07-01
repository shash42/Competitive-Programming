#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std ;
using namespace __gnu_pbds;

template <typename T> // *s.find_by_order(0), s.order_of_key(2) ;
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define reMin(a, b) a = min(a, b)
#define reMax(a, b) a = max(a, b)

#define lint long long
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define SET(x, val) memset(x, val, sizeof(x))
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long 
#define mp make_pair
#define F first
#define S second

typedef vector < int > vi ;
typedef pair < int, int > pii ;

const int N = 2e5 + 2 ;
const int MOD = 1e9 + 7 ;
const lint INF = 1e18 ;

struct project
{
    int l, p, r, ind;
} prjct[N];

struct projsrt
{
    bool operator()(const project &a, const project &b)
    {
        return a.l < b.l;
    }
};

pii t[N*4];
int lazy[N*4], n, k, arr[N], pref[N], ans=-2*INF, currL, currR;

void build(int v, int i, int j, int l, int r)
{
    lazy[v] = 0 ;
    if(i == j)
    {
        t[v] = {pref[i], i} ; return ;
    }
    int mid = (i + j) / 2 ;
    build(v*2, i, mid, l, r); build(v*2 + 1, mid + 1, j, l, r);
    if(t[v*2].F > t[v*2 + 1].F) t[v] = t[v*2] ;
    else t[v] = t[v*2 + 1] ;
}

void push(int v, int i, int j)
{
    t[v].F -= lazy[v] ;
    if(i != j)
    {
        lazy[v*2] += lazy[v] ;
        lazy[v*2 + 1] += lazy[v] ;
    }
    lazy[v] = 0 ;
}

void subtract(int v, int i, int j, int l, int r, int X)
{
    if(lazy[v]) push(v, i, j);
    if(i > r or j < l) return ;
    if(i >= l and j <= r)
    {
        lazy[v] += X ;
        push(v, i, j); 
        return ;
    }
    int mid = (i + j) / 2 ;
    subtract(v*2, i, mid, l, r, X); subtract(v*2 + 1, mid + 1, j, l, r, X);
    if(t[v*2].F > t[v*2 + 1].F) t[v] = t[v*2] ;
    else t[v] = t[v*2 + 1] ; 
}

pii query(int v, int i, int j, int l, int r)
{
    if(lazy[v]) push(v, i, j);
    if(i > r or j < l) return {-INF, i};
    if(i >= l and j <= r) return t[v];
    int mid = (i + j) / 2 ;
    pii lft = query(v*2, i, mid, l, r), rght = query(v*2 + 1, mid + 1, j, l, r)  ;
    if(lft.F > rght.F) return lft ;
    else return rght ;
   // return max(query(v*2, i, mid, l, r), query(v*2 + 1, mid + 1, j, l, r));
}

signed main()
{
    fastio; 
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> prjct[i].l >> prjct[i].r >> prjct[i].p;
        prjct[i].ind=i;
    }
    sort(prjct, prjct+n, projsrt());
    for(int i = 0; i < n; i++)
    {
        arr[prjct[i].r]+=prjct[i].p;
    }
    for(int i = prjct[0].l; i < N; i++)
    {
        arr[i]-=k;
        pref[i]=pref[i-1]+arr[i];
    }
    build(1, 1, N-1, 1, N-1);
    for(int i = 0; i < n; i++)
    {
        if(i==0 || prjct[i].l!=prjct[i-1].l)
        {
            if(i!=0) subtract(1, 1, N-1, prjct[i].l, N-1, -k*(prjct[i].l - prjct[i-1].l));
            pii suff=query(1, 1, N-1, prjct[i].l, N-1);
 //           cout << prjct[i].l << " " << suff.S << " - " << suff.F << endl;
            if(ans<suff.F)
            {
                ans=suff.F;
                currL=prjct[i].l;
                currR=suff.S;
            }
        }
        subtract(1, 1, N-1, prjct[i].r, N-1, prjct[i].p);
    }
    if(ans<0)
    {
        cout << 0;
        return 0;
    }
    vector<int> intervals;
    for(int i = 0; i < n; i++)
    {
        if(prjct[i].l >= currL && prjct[i].r <= currR)
        {
            intervals.pb(prjct[i].ind+1);
        }
    }
    cout << ans << " " << currL << " " << currR << " " << intervals.size() << endl;
    for(auto v: intervals)
    {
        cout << v << " ";
    }
}