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

const int N=3e4;
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

int t, ans=0;
map < pair< string, int>, int> M;
set< string > VS;
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> t;
    while(t--) 
    {
        ans=0;
        M.clear();
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            string w;
            cin >> w;
            VS.insert(w);
            int typ;
            cin >> typ;
            M[mp(w, typ)]++;
        }
        for(auto ss: VS)
        {
            string x = ss;
            int cnt0=M[mp(x, 0)];
            int cnt1=M[mp(x, 1)];
            if(cnt0>cnt1) ans+=cnt0;
            else ans+=cnt1;
        }
        cout << ans << endl;
    }   
	return 0;
}