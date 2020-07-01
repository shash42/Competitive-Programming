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

const int N = 2049, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

typedef unsigned long long ull;
int rng(const int before, const int after) { // Generate random base in (before, after]
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 mt_rand(seed ^ ull(new ull)); //remove ^ ull thing for speed
    int base = std::uniform_int_distribution<int>(before+1, after)(mt_rand);
    return base; //use steady_clock() for speed, for 64 bit mt19937_64 and lint
}

int n, p[N], b = 20;
signed main()
{
    cin >> n;
    int nd = 4095;
    while(true)
    {
        int x;
        while(true)
        {
            x = rng(1, n);
            if(p[x]==0) break;
        }

        break;
    }
}