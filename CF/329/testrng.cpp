#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define fo find_by_order
#define ok order_of_key
const int N=1e5+5, MOD=1e9+7, B=8;
using namespace std;
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef unsigned long long ull;
int rng(const int before, const int after) { // Generate random base in (before, after] 
    auto seed = std::chrono::steady_clock::now().time_since_epoch().count(); 
    std::mt19937 mt_rand(seed); //remove ^ ull thing for speed
    int base = std::uniform_int_distribution<int>(before+1, after)(mt_rand);
    return base; //use steady_clock() for speed, for 64 bit mt19937_64 and lint
}

signed main()
{
    cout << rng(0, 1);
}