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

const int N=3e5+5;
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

template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

lint even[N], odd[N] ;

int main()
{
    int t; int n, k ; 
    ind(t);
    while(t--)
    {
        lint ans = 0 ; int x ;
        ind(n); ind(k); for(int i = 0; i < 2*n; i++) even[i] = 0, odd[i] = 0 ;
        for(int i = n; i < (2*n); i++)
        {
            ind(x); odd[i] = odd[i-1] ; even[i] = even[i-1] ; 
            if(x & 1) odd[i] = max(odd[i], x + odd[i - k - 1]);
            else even[i] = max(even[i], x + even[ i - k - 1]);
            ans = max(ans, even[i] + odd[i]);
        }
        printf("%lld\n", ans); 
    }
	return 0;
}