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

const int N=1e6+5;
const int MOD=1e9+7;
const lint INF=1e18;

using namespace std;
using namespace __gnu_pbds;

struct group {
    vi traders ;
    int index ; 
};

int n, k ;
int marked[N] ;
vector < group > groups ;
int cnt[N] ;
vi which[N] ;
set < pii > os ;

bool cmp(int i, int j)
{
    return cnt[i] > cnt[j] ;
}

bool cmp2(group x, group y)
{
    return cnt[x.traders[0]] > cnt[y.traders[0]] ;
}

void solve()
{
    for(int i = 0; i < k; i++) sort(all(groups[i].traders), cmp);
    sort(groups.begin(), groups.end(), cmp2);
    
    int ans = 0 ;
    for(int i = 0; i < k; i++)
    {
        if(marked[groups[i].index]) continue ;
        int pick = groups[i].traders[0] ;
        for(int whichGroup : which[pick])
            marked[whichGroup] = 1 ;
        ans++ ;
    }
    printf("%d\n", ans);
}

void solve2()
{
    for(int i = 1; i <= n; i++) os.insert({cnt[i], i});
    int covered = 0 ;  int ans = 0 ;
    while(covered <= k)
    {
        pii cur = *os.rbegin(); os.erase(cur);
        int now = cur.second ; bool coverNow = 0 
        for(int whichGroup : which[now])
        {
            if(!marked[whichGroup]) marked[whichGroup] = 1, covered++, coverNow = 1 ;
            for(int x : groups[whichGroup].traders)
            {
                os.erase({cnt[x], x});
                cnt[x]--;
                os.insert({cnt[x], x});
            }
        }
        if(coverNow) ans++ ; 
    }
    printf("%d\n", ans) ; 
}

void pre()
{
    for(int i = 0; i <= n; i++) cnt[i] = 0 ;
    groups.clear(); groups.resize(k);
    for(int i = 0; i <= k; i++) marked[i] = 0 ; 
    for(int i = 0; i <= n; i++) which[i].clear();

}

int main()
{
    int t, x ; scanf("%d", &t); int len ; 
    while(t--){
        // CLEAN vectors 
        scanf("%d %d", &n, &k); pre();

        for(int i = 1; i < n; i++) scanf("%d", &x);
        for(int i = 0; i < k; i++)
        {
            scanf("%d", &len); groups[i].traders.resize(len);
            for(int j = 0; j < len; j++){

               scanf("%d", &groups[i].traders[j]);
               cnt[groups[i].traders[j]]++ ;
               which[groups[i].traders[j]].pb(i);
            }
            groups[i].index = i ; 
       }
       solve2();
    } 
	return 0;
}