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

char str[3][3];

int main()
{
    int t;
    ind(t);
    while(t--)
    {
        for(int a=0; a<3; a++)
            scanf(" %s", str[a]);
        bool there=false;
        for(int a=1; a<3; a++)
            for(int b=0; b<2; b++)
            {
                if(str[a][b]=='l' && str[a][b+1]=='l' && str[a-1][b]=='l')
                    there=true;
            }
        if(there)
            printf("yes\n");
        else
            printf("no\n");
    }
	return 0;
}