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
#define vi vector<int>
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define SET(x, val) memset(x, val, sizeof(x))
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int N = 2e5 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, a[N];
string s, ans;
signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> s;
        int l = s.length();
        ans = "";
        char c = s[0];
        bool single = true;
        for(int i = 0; i < l; i++)
        {
            if(s[i]!=c)
            {
                single = false;
                break;
            }
        }
        if(single)
        {
            cout << s << endl;
            continue;
        }
        for(int i = 0; i < l; i++)
        {
            ans+="10";
        }
        cout << ans << endl;
        /*for(int i = 1; i <= l; i++)
        {
            bool chk = true;
            for(int j = 0; j < l - i; j++)
            {
                if(s[j]!=s[j+i])
                {
                    chk = false;
                    break;
                }
            }
            if(chk)
            {
                int p = l/i;
                int st = p*i;
                for(int j = st; j < l; j++)
                {
                    ans+=s[j];
                }
                cout << ans << endl;
                break;
            }
        }*/
    }
}