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

string a, b, c, f, g  ;

int kmp(string s)
{
    int n = s.length();
    vi pi(n+1, 0);
    for(int i = 1; i < n; i++)
    {
        int j = pi[i-1] ;
        while(j > 0 and s[j] != s[i])
            j = pi[j-1] ;
        if(s[j] == s[i]) j++ ;
        pi[i] = j ;
    }
    return pi[n-1] ; 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t ;
    while(t--)
    {
        cin >> a >> b >> c ; int a1 = a.length() ; int b1 = b.length(); int c1 = c.length();
        f = c + '#' + a ; g = b + '#' + c ;
        int x = kmp(f) ; int y = kmp(g);
        int ans = max(0, c1 - y - x);
        cout << y << " : " << x << endl ;
        cout << ans+a1+b1 << "\n" ; 
    }
	return 0;
}