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

template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n ;
set < pair < lint, lint > > os ;
lint start[N], dur[N] ;
pair < lint, lint > ans[N] ;

int main()
{
    cin >> n ; os.insert({0, 0});
    pair < lint, lint > zero = {0, 0} ;

    for(int i = 0; i < n; i++)
    {
        cin >> start[i] >> dur[i] ;
        if(i == 0) ans[i] = {start[i], start[i] + dur[i] - 1},  os.insert({start[i], start[i] + dur[i] - 1});

    }

    for(int i = 1; i < n; i++)
    {
        lint s = start[i], d = dur[i], e = dur[i] + start[i] - 1 ;
        bool inter = 0 ; 
        for(auto it : os)
        {
            if( (s >= it.first  and s <= it.second) or (e >= it.first and e <= it.second) or (it.first >= s and it.first <= e) or (it.second >= s and it.second <= e))
                inter = 1 ;
        }
        pair < lint, lint > cur ; 
        if(!inter)
            cur = {s, e};
        else {
            
            for(auto it2 : os)
            {
                cur = {it2.second + 1, it2.second + d} ; 
                bool inter2 = 0 ; 
                for(auto it: os)
                {
                    if( (cur.first >= it.first  and cur.first <= it.second) or (cur.second >= it.first and cur.second <= it.second) or (it.first >= cur.first and it.first <= cur.second) or (it.second >= cur.first and it.second <= cur.second))
                        inter2 = 1 ;

                }
                if(inter2 == 0) {
                    break ;
                }
            }
        }
        ans[i] = cur ;
        os.insert(cur);
    }
    for(int i = 0; i < n; i++) cout << ans[i].first << " " << ans[i].second << endl ;
	return 0;
}