#include <bits/stdc++.h>
#define int long long
const int N = 1e5 + 5, INF = 1e18;
using namespace std;
int n, dp[N][3], arr[N];
char c[N];
signed main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            dp[i][j]=-INF;
        }
        int mult = 1;
        if (i)
        {
            cin >> c[i];
            if (c[i] == '-') mult = -1;
        }
        cin >> arr[i];
        arr[i] *= mult;
    }
    dp[0][0] = arr[0];
    for(int i = 1; i < n; i++)
    {
        dp[i][0]=dp[i-1][0] + arr[i];
        dp[i][1]=dp[i-1][1] - arr[i];
        if(c[i] == '-') dp[i][1] = max(dp[i][1], dp[i-1][0] + arr[i]);
        dp[i][2]=dp[i-1][2] + arr[i];
        if(c[i] == '-') dp[i][2] = max(dp[i][2], dp[i-1][1] - arr[i]);
        dp[i][1]=max(dp[i][1], dp[i][2]);
        dp[i][0]=max(dp[i][0], dp[i][1]);

    }
    cout << dp[n-1][0];
}