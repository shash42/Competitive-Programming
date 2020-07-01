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

lint n;
char str[10005];
std::vector<lint> roots;

int main()
{
    scanf("%s", str);
    n=strlen(str);
    for(lint a=0; a<n-1; a++)
    {
        if(str[a]!=str[a+1])
            roots.pb(2*(a+1)+1);
    }
    if(roots.empty())
    {
        if(str[0]=='H')
            printf("0\n1\n");
        else
            printf("0\n-1\n");
        return 0;
    }
    vector<lint>res;
    res.clear();
    res.pb(1);
    res.pb(-roots[0]);
    for(lint a=1; a<roots.size(); a++)
    {
        vector<lint>newres, here;
        newres.clear();
        here.clear();
        here.pb(1);
        here.pb(-roots[a]);
        newres.pb(1);
        for(lint b=1; b<res.size(); b++)
            newres.pb(res[b]+res[b-1]*here[1]);
        newres.pb(res[res.size()-1]*here[1]);
        res.clear();
        for(lint a=0; a<newres.size(); a++)
            res.pb(newres[a]);
    }
    printf("%d\n", (int)res.size()-1);
    lint mul=1;
    if(str[0]=='A')
    {
        if(res.size()%2==1)
            mul=-1;
    }
    else if(res.size()%2==0)
        mul=-1;
    for(auto x:res)
        printf("%lld ", x*mul );
    printf("\n");
	return 0;
}