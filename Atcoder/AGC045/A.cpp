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
using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 202, D=62, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, a[N], pw2[D];
int basis[D]; // basis[i] keeps the mask of the vector whose f value is i
int sz; // Current size of the basis
string s;

bool insertVector(int mask, int p1 = 0) {
    for (int i = 0; i < D; i++) {

        if ((mask & pw2[i]) == 0LL) continue; // continue if i != f(mask)

        if (!basis[i]) { // If there is no basis vector with the i'th bit set, then insert this vector into the basis
            if(p1) return true;
            basis[i] = mask;
            ++sz;
            return true;
        }
        mask ^= basis[i]; // Otherwise subtract the basis vector from this vector
    }
    return false;
}
void solve()
{
    for(int i = 0; i < D; i++) basis[i] = 0;
    sz = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> s;
    for(int i = n-1; i >= 0; i--)
    {
        if(s[i]=='0')
        {
            insertVector(a[i]);
        }
        else
        {
            bool ret = insertVector(a[i], 1);
            if(ret)
            {
                cout << 1 << endl;
                return;
            }
        }
    }
    cout << 0 << endl;
}
signed main()
{
    pw2[0]=1;
    for(int i = 1; i < D; i++) pw2[i] = pw2[i-1]*2;
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}