#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
const int N=52, INF=1e18+5;
using namespace std;
int n, k, a[N], dp[N];
signed main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++) a[i]=i;
    dp[n]=1;
    dp[n-1]=2;
    for(int i = n-2; i >= 1; i--)
    {
        dp[i]=min(INF, dp[i+1]+dp[i+2]);
    }
    int curr=k;
    for(int i = 1; i < n; i++)
    {
        if(curr>dp[i+1])
        {
            curr-=dp[i+1];
            swap(a[i], a[i+1]);
            i++;
        }
    }    
    for(int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
}