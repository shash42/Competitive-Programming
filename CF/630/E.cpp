#include<bits/stdc++.h>
#define int long long
#define lint long long
using namespace std;

const int MOD = 998244353, twoinv = 499122177;
int l, r, n, m;
inline int modpow(lint base, int exp, int modulo) {
  base %= modulo;  lint result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulo;
    base = (base * base) % modulo; exp >>= 1;
  }
  return result;
}
signed main()
{
    cin >> n >> m >> l >> r;
    int k = n*m;
    if(k%2)
    {
        cout << modpow(r-l+1, k, MOD);
    }
    else
    {
        int ans1 = modpow(r-l+1, k, MOD);
        if((r-l+1) % 2 == 1)
        {
            ans1 += 1;
        }
        ans1*=twoinv;
        ans1%=MOD;
        cout << ans1;
    }
}