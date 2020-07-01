#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std ;
using namespace __gnu_pbds;

template <typename T> // *s.find_by_order(0), s.order_of_key(2) ;
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define lint long long
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)

#define chkMin(a, b) a = min(a, b)
#define chkMax(a, b) a = max(a, b);

const int N = 1e6 + 2 ;
const int MOD = 1e9 + 7 ;
const lint INF = 1e18 ;

typedef vector < int > vi ;
typedef pair < int, int > pii ;

// template <typename T>

int modpow(int base, int exp, int modulo) {
  base %= modulo;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulo;
    base = (base * base) % modulo;
    exp >>= 1;
  }
  return result;
}

int n, k ;
vi a ;
bool taken[22] ;

int main()
{
    int  t; cin >> t ;
    while(t--)
    {
        cin >> n >> k ; a.resize(n); memset(taken, 0, sizeof(taken));
        for(int i = 0; i < n; i++)
        {
            cin >> a[i] ;
            for(int j = 19; j >= 0; j--)
            {
                if(a[i] & (1 << j))
                    taken[j] = 1 ;
            }
        }
        int ans = 0;
        for(int i = 0; i < 20; i++)
        {
            if(taken[i])
                ans |= (1 << i) ;
            // cout << i << " " << taken[i] << " " << ans << endl;
        }
        cout << ans << endl ;
    }
}