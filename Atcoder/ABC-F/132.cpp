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

const int K = 5e4 ; 
int n, k ; 

int prods[K] ;
map < int, int > umap ;

vector < lint >  dp1, dp2 ; 
set < int > os ; 

signed main()
{
    cin >> n >> k ; int div ; int j = 1; 
    for(int i = 1; i <= n;)
    {

        int cur = i ; 
        prods[j++] = cur ; 
        div = n/cur ; 
        os.insert(cur);
        umap[div] = i ; 
        cout << div << " : " << umap[div] << endl ; 
        int low = i, high = n+5 ;  
        while((high - low) > 1)
        {
            int mid = low + high >> 1 ;
            int curDiv = n/mid ; 
            if(curDiv < div) high = mid ;
            else low = mid + 1 ; 
        }
        if((n/low) < div) i = low ;
        else i = high ;
        cout << i << endl ; 

    }
    prods[j++] = n+1 ; 
    dp1.resize(K); dp2.resize(K);
    j--;

    dp2[0] = 0 ; 
    for(int i = 1; i < j; i++) cout << prods[i] << " " ;
        cout << endl ; 

    for(int p = 1; p < j; p++)
    {
        // int now = prods[p+1] - prods[p] ;
        dp2[p] = 1 ; 
    }

    cout << j << endl ; 
    cout << "done!" << endl ; 
    for(int i = k-1; i >= 0; i--)
    {
        for(int last = 1; last < j; last++)
        {
            int now = prods[last + 1] - prods[last] ; 
            int ele = umap[n/prods[last]] ; 
            auto it = os.upper_bound(n/prods[last]) ; it-- ; 
            ele = *it ; 
            dp1[last] = now * dp2[ele] ; 
            cout << last << " : " << ele << endl ;
        }

        for(int p = 1; p < j; p++)
        {
            lint now = prods[p+1] - prods[p] ; 
            // dp2[p] = ( dp2[p-1] + ( (now*dp1[p]) % MOD ) ) % MOD ;
            dp2[p] = dp2[p-1] + dp1[p] ; 
        }

        for(int l = 1; l < j; l++) cout << dp2[l] <<  " " ; 
            cout << endl ;  
    }
    cout << dp2[j-1] ; 
    
	return 0;
}