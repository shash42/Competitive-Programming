#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
const int N=2e5+5, MOD=998244353;
using namespace std;
int n, k, a[N], ret=1, curr=-1, ans=0;
signed main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(curr==-1 && a[i]>n-k)
        {
            curr=i;
            ans+=a[i];
        }
    }
    for(int i = curr+1; i <= n; i++)
    {
        if(a[i]>n-k)
        {
            ret*=(i-curr);
            ret%=MOD;
            ans+=a[i];
            curr=i;
        }
    }
    cout << ans << " " << ret;
}