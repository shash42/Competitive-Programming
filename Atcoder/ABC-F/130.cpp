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

const int N=1e5+5;
const int MOD=1e9+7;
const lint INF=1e18;

using namespace std;
using namespace __gnu_pbds;

template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define pd pair < long double, long double > 
#define PR 0.0000000001 

pd points[N] ; 
int ind ; 
char dir[N] ; int n ; 

pd giveNew(int i, ld t)
{
    pd cur = points[i] ; 
    if(dir[i] == 'R') cur.first += t ;
    else if(dir[i] == 'L') cur.first -= t ;
    else if(dir[i] == 'U') cur.second += t ;
    else cur.second -= t ;
    return cur ; 
}


ld maxArea(ld t)
{
    cout << t;
    ld maxX = -1e9, minX = 1e9, maxY = -1e9, minY = 1e9 ;
    for(int i = 0; i < n; i++)
    {
        pd shift = giveNew(i, t);
        maxX = max(maxX, shift.first);
        minX = min(minX, shift.first);
        minY = min(minY, shift.second);
        maxY = max(maxY, shift.second);
    }
    return (maxX - minX)*(maxY - minY);
}

signed main()
{
    cout<<fixed<<setprecision(10); 
    cin >> n ; 
    for(int i = 0; i < n; i++)
    {
        cin >> points[i].first >> points[i].second ;
        cin >> dir[i] ; 
    }

    ld cur, nxt, mid, nextMid, low = 0, high = 1e9 ;
    while((high - low) > 0.00000000001)
    {
        mid = (low + high) / 2.0 ; 
        nextMid = mid + PR ;
        cout << mid;
        cur = maxArea(mid); nxt = maxArea(nextMid);
        
        cout << high << " : " << low << " ::: " << cur << " - " << nxt << endl ; 
        if(cur - nxt >= 0) low = mid ;
        else high = mid  ; 
         cout << high << " : " << low << endl ; 
    }
    cout << maxArea(high) ; 
	return 0;
}