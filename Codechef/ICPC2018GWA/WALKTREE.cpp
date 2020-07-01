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

lint n, ans[N], period[N];
vector<lint>children[N];

void dfs(lint u, lint par, lint num_child)
{
    ans[u]=(ans[par]+period[par]*num_child)%MOD;
    ans[1]=1;
    period[u]=(period[par]*(lint)children[par].size())%MOD;
    period[1]=1;
    for(lint a=0; a<(lint)children[u].size(); a++)
        dfs(children[u][a], u, a);
}

void main2()
{
    inlld(n);
    for(lint a=1; a<=n; a++)
    {
        children[a].clear();
        lint ch;
        inlld(ch);
        while(ch--)
        {
            lint x;
            inlld(x);
            children[a].pb(x);
        }
    }
    ans[0]=1LL;
    period[0]=1LL;
    dfs(1LL, 0LL, 1LL);
    for(lint a=1; a<=n; a++)
        printf("%lld ", ans[a]);
    // for(lint a=1; a<=n; a++)
    //     printf("%lld ", period[a]);
    printf("\n");
}

int main()
{
    int t;
    ind(t);
    while(t--)
    {
        main2();
    }
	return 0;
}