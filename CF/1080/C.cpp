#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
const int N=1e5+5, INF=1e9;
using namespace std;
int n, k, a[N];
signed main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i]%=k;
    }
    int curr=k;
    for(int i = 1; i <= n; i++)
    {
        if(a[i]!=0)
        {
            curr = __gcd(curr, a[i]);
        }
    }
    cout << k/curr << endl;
    for(int i = 0; i < k; i+=curr)
    {
        cout << i << " ";
    }
}