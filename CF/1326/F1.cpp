#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
const int N=14, INF=1e9;
using namespace std;
int n, dp[2][N][1<<N], mat[N][N];
char inp[N][N];
vector<int> masks[N];
int solve(int it, int bin, int mask)
signed main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> inp[i][j];
            char
        }
    }
    dp[0][0][0]=1;
    for(int i = 0; i < (1<<N); i++)
    {
        masks[__builtin_popcountll(i)].pb(i);
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < (1<<i); j++)
        {
            for(auto mask: masks[i])
            {
                for(int k = 0; k < N; k++)
                {
                    if(mask&(1<<k))
                    {
                        dp[i][j][mask] += dp[i-1][j/2][mask^(1<<k)];
                    }
                }
            }
        }
    }
    for(int i = 0; i < (1<<(n-1)); i++)
    {
        cout << dp[n-1][j][(1<<n)-1] << " ";
    }
}