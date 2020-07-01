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

const int N=1e2+5;
const int MOD=1e9+7;
const lint INF=1e18;

using namespace std;
using namespace __gnu_pbds;

template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n, m ;
string strings[N] ;
vi toRemove ;
int x ;
string query ;
set < int > os ;

int main()
{
    cin >> n >> m ;
    for(int i = 0; i <n; i++) cin >> strings[i] ;
    for(int i = 0; i < m; i++) {
        cin >> x ; os.insert(x-1); 
        toRemove.pb(x);
        if((int)toRemove.size() == 1) query = strings[x-1] ; 
    }

    bool pos = 1 ;

    for(int i = 1; i < m; i++)
    {
        int rem = toRemove[i] - 1; 
        int len = strings[rem].length(); 
        // cout << pos << endl ;
        if(len != query.length()) {
            pos = 0 ; 
            break ; 
        }
        for(int j = 0; j < len; j++)
        {
            if(query[j] != strings[rem][j]) query[j] = '?' ; 
        }
        //cout << pos << endl ; 
    }

    for(int i = 0; i < n; i++)
    {
        if(os.find(i) != os.end()) continue ;
        if(strings[i].length() != query.length()) continue ;
        // cout << i << endl ; 
        bool match = 1 ;
        for(int j = 0; j < strings[i].length(); j++)
            if(strings[i][j] != query[j] and query[j] != '?')
                match = 0 ;
        if(match) pos = 0 ;
    }
    if(pos) {
        cout << "Yes\n" << query ;
    }
    else {
        cout << "No" ; 
    }
	return 0;
}