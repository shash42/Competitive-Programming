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

const int N = 32, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int k[N], s[N];
void print(int i)
{
    for(int j = 1; j <= i; j++)
    {
        cout << k[j] - k[j-1] << " ";
    }
}
void solve()
{
    int x;
    cin >> x;
    if(x==2)
    {
        cout << 1 << endl << 0 << endl;
        return;
    }
    int i;
    for(i = 0; i < N; i++)
    {
        if(s[i]>x) break;
    }
    i--;
    if(s[i]==x)
    {
        cout << i << endl;
        print(i);
        cout << endl;
        return;
    }
    i--;
    int curr = s[i];
    int r = (x - s[i])/2;
    int lol1 = min(r, 2*k[i]);
    curr += lol1;
    cout << i+2 << endl;
    print(i);
    int sum = s[i];
    cout << lol1 - k[i] << " ";
    sum += lol1;
    cout << x-curr-lol1 << " ";
    sum += x-curr;
    cout << endl;
    if(sum!=x)
    {
        exit(7);
    }
}
signed main()
{
    k[0] = 1;
    s[0] = 1;
    for(int i = 1; i < N; i++)
    {
        k[i] = k[i-1]*2;
        s[i] = s[i-1]+k[i];
    }
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}