#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define F first
#define S second
#define lint long long
#define mp make_pair
#define pii pair<int, int>
#define pll pair<lint, lint>
#define vi vector<int>
#define sz(x) (int)x.size()
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int N=1e5+5, MOD=1e9+7;
const lint INF=1e18;

using namespace std;
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int t;
string s;
signed main()
{
    fastio;
    cin >> t;
    while(t--)
    {
        cin >> s;
        int l = s.length(), lidx=-1, ridx=-1;
        for(int i = 0; i < l; i++)
        {
            if(s[i]=='1')
            {
                lidx=i;
                break;
            }
        }
        for(int i = l-1; i >= 0; i--)
        {
            if(s[i]=='1')
            {
                ridx=i;
                break;
            }
        }
        int cnt1=0;
        for(int i = lidx; i <= ridx; i++)
        {
            if(s[i]=='1') cnt1++;
        }
        int ans = ridx - lidx + 1;
        ans-=cnt1;
        if(lidx==-1)
        {
            cout << 0 << endl;
            continue;
        }
        cout << ans << endl;
    }
}