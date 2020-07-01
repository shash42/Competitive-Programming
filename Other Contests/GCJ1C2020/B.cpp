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

const int N = 1e4, MOD1 = 1e9 + 7, MOD2 = 998244353, B=17;
const lint INF = 1e18;

int u, pos[26];
struct query
{
    int m;
    string r;
} q[N+2];
void solve()
{
    set<char> charl;
    vector< pair<int, char> > chars;
    cin >> u;
    for(int i = 1; i <= N; i++)
    {
        cin >> q[i].m >> q[i].r;
        for(int j = 0; j < q[i].r.length(); j++)
        {
            charl.insert(q[i].r[j]);
        }
    }
    for(auto c: charl) chars.pb({0, c});
    for(int i = 0; i < 26; i++)
    {
        char c = 'A' + i;
        if(charl.find(c)==charl.end()){
            pos[i] = 11;
            continue;
        }
        for(int j = 0; j < 10; j++) if(chars[j].S==c) pos[i]=j;
    }
    for(int i = 1; i <= N; i++)
    {
        char c = q[i].r[0];
        int p = pos[c - 'A'];
        if(p==11) exit(7);
        chars[p].F++;
    }
    sort(chars.begin(), chars.end());
    string ans = "";
    ans+=chars[0].S;
    for(int i = 9; i >= 1; i--) ans+=chars[i].S;
    cout << ans;
}

signed main()
{
    int T;
    cin >> T;
    int t = T;
    while(t--)
    {
        cout << "Case #" << T-t << ": ";
        solve();
        cout << endl;
    }
}