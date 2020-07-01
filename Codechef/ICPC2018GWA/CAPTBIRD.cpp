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

int n, arr[N], p, q;

ld get_angle(int x1, int x2)
{
    if(p>=x2)
    {
        return atan((ld)(p-x1)/(ld)q)-atan((ld)(p-x2)/(ld)q);
    }
    else if(p<=x1)
    {
        return atan((ld)(x2-p)/(ld)q)-atan((ld)(x1-p)/(ld)q);   
    }
    else
    {
        return atan((ld)(p-x1)/(ld)q)+atan((ld)(x2-p)/(ld)q);
    }
}

int main()
{
    int t;
    ind(t);
    while(t--)
    {
        ind(n);
        for(int a=1; a<=n; a++)
            ind(arr[a]);
        ind(p);ind(q);
        sort(arr+1, arr+n+1);
        ld ans=0;
        for(int a=1; a<=n/2; a++)
        {
            ans+=get_angle(arr[a], arr[n-a+1]);
        }
        printf("%0.15Lf\n", ans);
    }
	return 0;
}