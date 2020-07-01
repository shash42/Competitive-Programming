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
lint dp[80][5][5][5] ;
bool bigger = false ;
lint num ;
lint one = 1 ;

lint solve(int i, bool msb, bool s1, bool s2)
{
    if(i < 0) {
        return 1 ; 
    }
    if(dp[i][msb][s1][s2] != -1) return dp[i][msb][s1][s2] ;

    lint ans = 0;
    lint current = ( num & (one << i) ) > 0LL ;  
    lint curL = (L & (one << i) ) > 0LL ; 




    // cout << i << " : " << msb << " :: " << s1 << " :: " << s2 << endl ; 
    lint ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0 ; 

    // cout << current << " : " << curL << endl ;

    if(s1)  // y < R stricly 
    {

            // Choose to place 0 in y 
            if(s2) {
                // x > Y so freely place 
                ans1 = solve(i-1, msb, 1, 1);
            }
            else {
                // x == Y as of now 
                if(!curL) ans1 = solve(i-1, msb, 1, 0); 
            }

            // Choose to place 1 in y 
            if(s2) { // x > Y already  

                // Place 0 in x only when MSB has been placed
                if(msb) {
                    ans2 = solve(i-1, 1, 1, 1);
                }

                // Place 1 in x 
                ans3 = solve(i-1, 1, 1, 1);
            }
            else { // x == L 

                // Place 0 in x only when MSB has been placed
                if(msb and !curL) {
                    ans2 = solve(i-1, 1, 1, 0);
                }

                // Place 1 in x 
                ans3 = solve(i-1, 1, 1, curL == 0);

            }
    }
    else {
        if(!current) {
            if(s2) // x > L 
                ans1 = solve(i-1, msb, 0, 1);
            else { 
                // x == L as of now 
                if(!curL) ans1 = solve(i-1, msb, 0, 0); 
            }
        }
        else { // R has 1 bit here 

            // Choose to place 0 in y 
            if(s2) {
                // x > L so freely place 
                ans1 = solve(i-1, msb, 1, 1);
            }
            else {
                // x == L as of now 
                if(!curL) ans1 = solve(i-1, msb, 1, 0); 
            }

            // Choose to place 1 in y 
            if(s2) { // x > Y already  

                // Place 0 in x only when MSB has been placed
                if(msb) {
                    ans2 = solve(i-1, 1, 0, 1);
                }

                // Place 1 in x 
                ans3 = solve(i-1, 1, 0, 1);
            }
            else { // x == L 

                // Place 0 in x only when MSB has been placed
                if(msb and !curL) {
                    ans2 = solve(i-1, 1, 0, 0);
                }

                // Place 1 in x 
                ans3 = solve(i-1, 1, 0, curL == 0);

            }

        }
    }
    ans = (ans1 + ans2 + ans3 + ans4) % MOD ; 
    return dp[i][msb][s1][s2] = ans  ;
}



int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> L >> R ;
    num =  R ; 

    lint ans = solve(63, 0, 0, 0);
    cout << ans ; 
	return 0;
}