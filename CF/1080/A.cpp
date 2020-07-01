#include<bits/stdc++.h>
#define int long long
#define double long double
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
const int N=1e3+5, INF=1e9;
double prr = 2e-10;
using namespace std;
int n, m, a[N], b[N];
bool chk(double x)
{
    x -= (m+x)/a[1];
    if(x<0) return false;
    for(int i = 2; i <= n; i++)
    {
        x -= (m+x)/a[i];
        if(x<0) return false;
        x -= (m+x)/b[i];
        if(x<0) return false;
    }
    x -= (m+x)/b[1];
    return (x>-prr);
}
signed main()
{
    cin >> n >> m;
    cout << setprecision(20);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }    
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    double lo = prr, hi = 1e9+3, pr = 1e-7, ans;
    while(true)
    {
        if(hi-lo<pr)
        {
            if(chk(lo))
                ans = lo;
            else ans = hi;
            break;
        }
        double mid = (lo+hi)/2.0;
        if(chk(mid))
        {
            hi = mid;
        }
        else
        {
            lo = mid+pr;
        }
    }
    if(ans>1e9+1) cout << -1;
    else cout << ans;
}