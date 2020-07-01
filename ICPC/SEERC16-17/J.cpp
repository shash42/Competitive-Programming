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

const int N=100+2;
const int MOD=1e9+7;
const lint INF=1e18;

using namespace std;
using namespace __gnu_pbds;

template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector < pii > bottles ;
int n ;

bool cmp(pii x, pii y)
{
    return x.second > y.second ;
}

int OFF = 1e4 + 2 ;
int dp1[N*N*2][N], dp2[N*N*2][N] ;

int main()
{
    cin >> n ; bottles.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> bottles[i].first ; //  >> bottles[i].second ;
    }
    for(int i = 0; i < n; i++)
        cin >> bottles[i].second ;

    for(int j = 0; j < (N*N*2); j++)
         for(int k = 0; k < N; k++)
            dp2[j][k] = dp1[j][k] = 1e9 ;

    dp2[OFF][0] = 0 ; 
    for(int i = 0; i < n; i++)
    {
        for(int cap = (-1e4); cap < (N*N); cap++)
        {
            for(int mini = 0; mini <= n; mini++)
            {
               // if(i == 0 and cap > 0) break ; 
                int nxt1 = cap - ( bottles[i].second - bottles[i].first ) ; 
                int ans1 = 1e9 ;
                if(mini) ans1 = dp2[OFF + nxt1][mini - 1] ;
                int nxt2 = cap + bottles[i].first ;
                int ans2 = bottles[i].first + dp2[OFF + nxt2][mini] ; 
                dp1[OFF + cap][mini] = min(ans1, ans2) ; 
                /*
                if(i == 1 and cap == 1 and mini == 1) {
                    cout << nxt1 << " " << nxt2 << endl ;
                    cout << ans1 << " " << ans2 << endl ;
                }
                */
            }
        }

        for(int j = 0; j < (N*N*2); j++)
            for(int k = 0; k < N; k++)
                dp2[j][k] = dp1[j][k] ; 
    }

    int ans = 2e9 ; int mx = 1e9 ;
    for(int k = 1; k <= n; k++)
    {
        for(int j = OFF; j < (N*N*2); j++)
        {
            if(dp2[j][k] < ans)
                ans = dp2[j][k] ;
        }
        if(ans < mx) {
            cout << k << " " << ans << endl ;
            return 0;
        }
    }
	return 0;
}