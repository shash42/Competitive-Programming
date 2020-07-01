#include<bits/stdc++.h>

using namespace std;

int n, x, m;
signed main()
{
    cin >> x;
    n = x/1000;
    m = x%1000;
    int ans = 1;
    while(n>0)
    {
        ans*=n;
        ans%=m;
        ans-=2;
    }
    cout << ans;
}