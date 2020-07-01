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

lint _add(lint x, lint y)
{
    lint ret=x+y;
    while(ret<0LL)
        ret+=MOD;
    return ret;
}

lint _mult(lint x, lint y)
{
    x%=MOD;
    y%=MOD;
    lint ret=x*y;
    ret%=MOD;
    while(ret<0LL)
        ret+=MOD;
    return ret;
}

using namespace std;
using namespace __gnu_pbds;


// string L, R ;
lint L, R ;
lint dp[80][80][5] ;
bool bigger = false ;
lint num ;
lint one = 1 ;

lint solve(int i, int cnt, bool smaller)
{
    if(i < 0) {
        if(cnt == 0) return 0 ; 
        lint now = one << (cnt - 1) ; now %= MOD ;  
        if(!bigger)
            return (now); 
        else 
            return (smaller) ? (now) : 0 ;
    }
    if(dp[i][cnt][smaller] != -1) return dp[i][cnt][smaller] ;
    lint ans = 0;
    lint current = ( num & (one << i) ) > 0LL ;  

//     cout << i << " : " << cnt << " :: " << smaller << endl ; 

    if(smaller)
    {
        ans += solve(i-1, cnt, 1); ans %= MOD ;
        ans += solve(i-1, cnt + 1, 1); ans %= MOD ;
    }
    else {
        if(!current) ans += solve(i-1, cnt, 0);
        else {
            ans += solve(i-1, cnt, 1); ans %= MOD ;
            ans += solve(i-1, cnt + 1, 0); ans %= MOD ;
        }
        ans %= MOD ;
    }
    return dp[i][cnt][smaller] = ans  ;
}



int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> L >> R ;
    num =  R ; 
    lint ans1 = solve(63, 0, 0);
    cout << ans1 << endl ; 

    memset(dp, -1, sizeof(dp));
    num = L ; bigger = true ; 
    lint ans2 = solve(63, 0, 0); 
    cout << ans2 << endl ; 

    lint ans = (ans1 - ans2) ; if(ans < 0) ans += MOD ;
    cout << ans ; 
	return 0;
}