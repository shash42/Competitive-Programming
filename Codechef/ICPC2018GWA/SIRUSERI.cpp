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

int A, B, n;
pair<int, pair<int, int> > arr[N];

int main()
{
	int fib[N] ; fib[0] = 1; fib[1] = 1 ; fib[2] = 2 ;
	for(int i = 3; i < 45; i++)
	{
		fib[i] = fib[i-1] + fib[i-2] ;
		cout << fib[i] << endl ;
	}

    int t;
    ind(t);
    while(t--)
    {
        ind(A);ind(B);
        n=A*B;
        for(int a=1; a<=n; a++)
        	ind(arr[a].s.f);
        for(int a=1; a<=n; a++)
        {
        	ind(arr[a].s.s);
        	arr[a].f=max(arr[a].s.f, arr[a].s.s);
        }
        sort(arr+1, arr+n+1);
        int freespace=0, cities=0, ans=0;
        for(int a=n; a>=1; a--)
        {
        	if(cities==A)
        		break;
        	if(arr[a].s.f>arr[a].s.s)
        	{
        		freespace+=B-1;
        		ans++;
        		cities++;
        	}
        	else
        	{
        		if(freespace)
        			freespace--;
        		else
        		{
        			freespace+=B-1;
        			cities++;
        		}
        	}
        }
        printf("%d\n", ans);
    }
	return 0;
}