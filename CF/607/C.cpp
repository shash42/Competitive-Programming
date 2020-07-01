#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define F first
#define S second
#define int long long
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
    ret%=MOD;
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

int x;
string s;
string fin;
signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int l = 0;
        cin >> x;
        cin >> s;
        fin=s;
        while(fin.length()<x)
        {
           // cout << l << endl;
            l++;
            int kk=fin.length();
            for(int i = 1; i < fin[l-1]-'0'; i++)
            {
                for(int j = l; j < kk; j++)
                {
                    fin+=fin[j];
                }
            }
        }
       // cout << fin << endl;
        int lencurr=fin.length();
        while(l!=x)
        {
            l++;
         //   cout << lencurr << endl;
            lencurr=_add(lencurr, _add(lencurr, -l)*(fin[l-1]-'0'-1));
        }
        cout << lencurr << endl;
    }
	return 0;
}