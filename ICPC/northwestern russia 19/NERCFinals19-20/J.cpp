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

const int N=2e6+5;
const int MOD=1e9+7;
const lint INF=1e18;


using namespace std;
using namespace __gnu_pbds;

#define lint long long

vi distinct ;
int freq[N] ;
int seen[N] ;
int a[N] ;
int  n = N - 1;
set < int > done ;

int check(int now)
{
    int ans = 0 ; 
    for(int p : distinct)
    {
        int z = ceil((float)p/now); int q = z - 1 ; int r = z + 1 ; 
        if((now*z) == p or (now*z - 1) == p)
            ans += z ;
        else if((now*q) == p or (now*q - 1) == p)
            ans += q ;
        else if((now*r) == p or (now*r - 1) == p)
            ans += r ;
        else {
            ans = 1e9 ;
            break ; 
        }
    }
    return ans ; 
}


lint check2(int s)
{
    lint ans = 0;
    for(int xx : distinct)
    {
        lint x = xx ; 
        lint k = x%s ; 
        k = (s - k) % s ; 
        lint req = k * (s - 1);
        if(req <= x and req >= 0LL)
        {
            ans += k + (x - k*(s - 1) )/s ; 
        }
        else {
            return 1e18 ;
        }
    }
    return ans ; 
}

lint solve2()
{
    lint mx = 1e18, mx2 = 1e17 ;
    for(int i = 0; i < n; i++)
    {
        if(!seen[a[i]])
        {
            distinct.pb(freq[a[i]]);
            seen[a[i]] = 1 ;
            // mx += freq[a[i]] ;
        }
    }
    int sz = distinct.size();
    sort(distinct.begin(), distinct.end());
    int lowest = distinct[0] + 1; 

    while(lowest)
    {
        mx = min(mx, check2(lowest));
        lowest-- ;
        if(mx < mx2) return mx ; 
    }
    return mx ;

}

int solve()
{
    int mx = 0 ;
    for(int i = 0; i < n; i++)
    {
        if(!seen[a[i]])
        {
            distinct.pb(freq[a[i]]);
            seen[a[i]] = 1 ;
            mx += freq[a[i]] ;
        }
    }
    int sz = distinct.size();
    sort(distinct.begin(), distinct.end());
    int lowest = distinct[0] ; int z = 1 ; 

    while(lowest and z < N)
    {
        lowest = ceil((float)distinct[0]/z) ;
        int now = lowest, now2 = lowest + 1 ; 
        // int cur1 = 0, cur2 = 0 ; int here1 = 0, here2 = 0 ;
        if(done.find(now) == done.end())
        {
            done.insert(now);
            mx = min(mx, check(now));
        }
        if(done.find(now2) == done.end())
        {
            done.insert(now2);
            mx = min(mx, check(now2));
        }
        z++ ; 
    }
    return mx ;
}

void pre()
{
    for(int i = 0; i <= n; i++) freq[i] = 0, seen[i] = 0 ; 
    distinct.clear();
    done.clear();
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t ; cin >> t ;
    while(t--)
    {
        cin >> n ; pre();
        for(int i = 0; i < n; i++)
        {
            cin >> a[i] ;
            freq[a[i]]++ ;
        }
        cout << solve2() << endl ; 
    }
	return 0;
}
/*
3
11
1 5 1 5 1 5 1 1 1 1 5
6
1 2 2 2 2 1
5
4 3 3 1 2
*/