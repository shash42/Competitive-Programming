#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
int n, a[N];
signed main()
{
    cin >> n;
    int ans=0;
    ans += 32 * ((n & 32) > 0);
    ans += 16 * ((n & 1) > 0);
    ans += 8 * ((n & 4) > 0);
    ans += 4 * ((n & 8) > 0);
    ans += 2 * ((n & 2) > 0);
    ans += ((n & 16) > 0);
    cout << ans;
}