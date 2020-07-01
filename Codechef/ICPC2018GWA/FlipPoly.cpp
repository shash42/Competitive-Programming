#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define f first
#define s second
#define lint long long
#define mp make_pair
#define pii pair<int, int>
#define pll pair<lint, lint>
#define ld long double
#define inlld(x) scanf("%lld", &x)
#define ind(x) scanf("%d", &x)
#define vi vector<int>
#define all(x) x.begin(), x.end() 



const int N=1e5+5;
const int MOD=1e9+7;
const lint INF=1e18;

using namespace std;
using namespace __gnu_pbds;

const int K = 48 ; 


struct node {
    int fR = 0, y = 0, sR = 0, n ;
};

struct segtree {
    node t[N*4] ;
    node lazy[N*4] ;
    node emptyNode ; 
    node cur ;
    int ncopy ;

    void build(int v, int i, int j, int nn)
    {

        if(i == j)
        {   
            t[v].n = nn ; lazy[v].n = nn ; 
            return ; 
        }
        int mid = i+j >> 1;
        build(v*2, i, mid, nn); build(v*2 + 1, mid + 1, j, nn);
        t[v].n = lazy[v].n = nn ; 
    }

    bool checkLazy(int v)
    {
        return (lazy[v].fR == 0 and lazy[v].sR == 0 and lazy[v].y == 0 );
    }

    void rotateNode(int v, int r)
    {
        if(t[v].y) t[v].sR += r, t[v].sR %= t[v].n ;
        else t[v].fR += r, t[v].fR %= t[v].n  ;
    }


    void rotateLazyNode(int v, int r)
    {
        if(lazy[v].y) lazy[v].sR += r, lazy[v].sR %= lazy[v].n ;
        else lazy[v].fR += r, lazy[v].fR %= lazy[v].n  ;
    }

    void flipNode(int v)    
    {   
        if(t[v].y) {
            t[v].y = 0 ;
            int finalRot = (t[v].fR - t[v].sR) % t[v].n ; 
            if(finalRot < 0) finalRot += t[v].n ;
            t[v].fR = finalRot ;
            t[v].sR = 0 ; 
        }
        else {
            t[v].y = 1 ;
        }
    }


    void flipLazyNode(int v)    
    {   
        if(lazy[v].y) {
            lazy[v].y = 0 ;
            int finalRot = (lazy[v].fR - lazy[v].sR) % lazy[v].n ; 
            if(finalRot < 0) finalRot += lazy[v].n ;
            lazy[v].fR = finalRot ;
            lazy[v].sR = 0 ; 
        }
        else {
            lazy[v].y = 1 ;
        }
    }


    int getAns(int v, int i, int j, int pos)
    {
        // cout << v << " :: " << t[v].fR << " " << t[v].y << " " << t[v].sR << endl ; 

        // cout << t[v].n << endl ;

        int ans2 = pos;
        
        if(t[v].y) ans2 = ( (t[v].n & 1) ? (t[v].n - pos) % t[v].n : (t[v].n + 1 - pos) % t[v].n ) ;
        ans2 %= t[v].n ; if(ans2 < 0) ans2 += t[v].n ;

        int ans1 = ( ans2 + t[v].n - t[v].fR ) % t[v].n ; ans1 %= t[v].n ; if(ans1 < 0) ans1 += t[v].n ; 
        
        // cout << ans1 << endl ;

        // ans2 = ans1 ;

        // cout << ans2 << endl ;

        
        int ans = ( ans2 + t[v].n - t[v].fR ) % t[v].n ; ans %= t[v].n ; if(ans < 0) ans += t[v].n ; 
        //  cout << ans << endl ; 


        return ans ; 
    }

    void push(int v, int i, int j)
    {
        rotateNode(v, lazy[v].fR);
        if(lazy[v].y) flipNode(v);
        rotateNode(v, lazy[v].sR); 

        if(i != j)
        {   
            rotateLazyNode(v*2, lazy[v].fR); if(lazy[v].y) flipLazyNode(v*2); rotateLazyNode(v*2, lazy[v].sR);
            rotateLazyNode(v*2 + 1, lazy[v].fR); if(lazy[v].y) flipLazyNode(v*2 + 1); rotateLazyNode(v*2 + 1, lazy[v].sR);
        }
        lazy[v] = emptyNode ;
    }

    void rotation(int v, int i, int j, int l, int r, int deg)
    {
        if(!checkLazy(v)) push(v, i, j);
        if(i > r or j < l) return ;
        if(i >= l and j <= r)
        {
            rotateLazyNode(v, deg);
            push(v, i, j);
            return ; 
        }
        int mid = i+j >> 1 ;
        rotation(v*2, i, mid, l, r, deg); rotation(v*2 + 1, mid + 1, j, l, r, deg);

    }

    void reflect(int v, int i, int j, int l, int r)
    {
        if(!checkLazy(v)) push(v, i, j);
        if(i > r or j < l) return ;
        if(i >= l and j <= r)
        {
            // reflect here  
            // Then push ;
            flipLazyNode(v);
            push(v, i, j);
            return ;
        }
        int mid = i+j >> 1 ;
        reflect(v*2, i, mid, l, r); reflect(v*2 + 1, mid + 1, j, l, r);

    }
    
    int query(int v, int i, int j, int pos, int loc)
    {

        if(!checkLazy(v)) push(v, i, j);
        if(i == j and j == pos)
        {
            return getAns(v, i, j, loc);
        }
        int mid = i+j >> 1 ;
        if(pos <= mid) return query(v*2, i, mid, pos, loc);
        else return query(v*2 + 1, mid + 1, j, pos, loc);
    }

};

int n, q ;
int a[N] ;
map < int, int > fibMap ; 
segtree st[K] ;
vector < int > indices[K] ;
    int fib[K] ;

void pre()
{
    fib[0] = 1; fib[1] = 1 ; fibMap[1] = 1 ; 
    for(int i = 2; i < K; i++) {
        fib[i] = fib[i-1] + fib[i-2] ;
        fibMap[fib[i]] = i ; 
    }


}


void rangeRoate(int l, int r, int theta)
{
    for(int i = 1; i < K; i++)
    {
        int lowIndex = lower_bound(all(indices[i]), l) - indices[i].begin();
        int highIndex = upper_bound(all(indices[i]), r) - indices[i].begin() ; highIndex-- ;

        cout << i << " " << lowIndex << " : " << highIndex << "   " << st[i].ncopy << endl  ;
        if(highIndex >= lowIndex) 
            st[i].rotation(1, 1, n, lowIndex + 1, highIndex + 1, theta); 

    }
}

void rangeFlip(int l, int r)
{
    for(int i = 1; i < K; i++)
    {
        int lowIndex = lower_bound(all(indices[i]), l) - indices[i].begin();
        int highIndex = upper_bound(all(indices[i]), r) - indices[i].begin() ; highIndex-- ;

        // cout << i << " " << lowIndex << " : " << highIndex << "   " << st[i].ncopy << endl  ; 
        if(highIndex >= lowIndex)
            st[i].reflect(1, 1, n, lowIndex + 1, highIndex + 1);     
    }

}


int getLocation(int x, int y)
{
    int whichFib = fibMap[a[x]] ; 
    int pos = lower_bound(all(indices[whichFib]), x) - indices[whichFib].begin(); 
    return st[whichFib].query(1, 1, n, pos + 1, y);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    pre();
    cin >> n >> q ; int qt, l, r, p, x, y ; 
    for(int i = 1; i <= n; i++)
    {
        cin >> x ; a[i] = x ;
        int fibIndex = fibMap[x] ;
        indices[fibIndex].pb(i);
    }

    for(int i = 1; i < K; i++)
    {
        st[i].ncopy = fib[i] ; 
        st[i].build(1, 1, n, fib[i]);
    }

    while(q--)
    {
        cin >> qt ;
        if(qt == 1)
        {
            cin >> l >> r >> p ;
            rangeRoate(l, r, p);
        }
        else if(qt == 2)
        {
            cin >> l >> r ;
            rangeFlip(l, r);
        }
        else {
            cin >> x >> y ;
            cout << getLocation(x, y-1) + 1 << endl ; 

        }
    }
	return 0;
}