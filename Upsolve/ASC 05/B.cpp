#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>

#define pb push_back
#define F first
#define S second
#define lint long long
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define SET(x, val) memset(x, val, sizeof(x))
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
//using namespace __gnu_pbds;
//template<typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 12, B = (1 << N), MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, b;
vi ans;
set<int> s;

string tobin(int x)
{
    //cout << x << endl;
    string bin = "";
    for (int i = 0; i < n; i++)
    {
        int test = (1 << i);
        bin += '0' + ((x & test) != 0);
    }
    reverse(bin.begin(), bin.end());
    return bin;
}

int diff(int x, int y)
{
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        int test = (1 << i);
        if ((x & test) xor (y & test)) ret++;
    }
    return ret;
}

signed main()
{
    freopen("code.in", "r", stdin);
    freopen("code.out", "w", stdout);
    cin >> n;
    b = (1 << n);
    for (int i = 0; i < b; i++)
    {
        s.insert(i);
    }
    ans.pb(0);
    ans.pb((1 << (n / 2)) - 1);
    ans.pb(b - (1 << (n / 2)));

    s.erase(0);
    s.erase((1 << (n / 2)) - 1);
    s.erase(b - (1 << (n / 2)));

    int prv = b - (1 << (n / 2));
    for (int i = 1; i < b / 2; i++)
    {
        bool flag = false;
        for (auto u: s)
        {
            if (diff(u, prv) >= n / 2)
            {
                ans.pb(u);
                ans.pb(b - 1 - u);
                prv = b - 1 - u;
                s.erase(u);
                s.erase(b - 1 - u);
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            cout << "none";
            return 0;
        }
    }
    for (int i = 0; i < ans.size() - 1; i++)
    {
        cout << tobin(ans[i]) << endl;
    }

    for(int i = 0; i < b; i++)
    {
        int c = ans[i];
        int nx = ans[(i+1)%b];
        if(diff(c, nx)<n/2)
        {
            exit(7);
            cout << i << " none " << ans[i] << endl;
        }
    }
}