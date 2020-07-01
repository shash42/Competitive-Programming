#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
const int N=302, MOD=1e9+7;
using namespace std;
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int dp[2][N][N][4], n, m, ptr=1;
int pref[2][4][N][4]; //sum over col[2] when remaining col last posn is [3] and current col is [4]
struct qry
{
    int l, r, x;
} q[N];
struct qrysrt
{
    bool operator()(const qry &a, const qry&b)
    {
        return a.r < b.r;
    }
};
signed main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)       cin >> q[i].l >> q[i].r >> q[i].x;
    sort(q+1, q+m+1, qrysrt());
    for(int i = 1; i <= 3; i++)       dp[1][0][0][i]=1;
    while(ptr<=m && q[ptr].r==1)
    {
        if(q[ptr].x!=1)
        {
            cout << 0;
            return 0;
        }
        ptr++;
    }
    for(int i = 2; i <= n; i++)
    {
        for(int j = 0; j < i-1; j++) //fixed
            for(int csum = 1; csum <= 3; csum++)
                for(int ccur = 1; ccur <= 3; ccur++)
                {
                    int tba=0, rem = 6 - csum - ccur;
                    for(int k = 0; k < i-1; k++) //sumover
                    {
                        if(rem<csum) tba += dp[(i-1)%2][j][k][ccur];
                        else tba += dp[(i-1)%2][k][j][ccur];  
                        tba %= MOD;
                    }  
                    pref[(i-1)%2][csum][j][ccur] = tba;
                }
        for(int j = 0; j < i; j++)
            for(int k = 0; k < i; k++)
                for(int c = 1; c <= 3; c++)
                {
                    if(k==j && k!=0)
                    {
                        dp[i%2][j][k][c]=0;
                        continue;
                    }
                    if(j!=i-1 && k!=i-1)         dp[i%2][j][k][c]=dp[(i-1)%2][j][k][c];
                    else if(j==i-1)
                    {
                        if(c==1) dp[i%2][j][k][c] = pref[(i-1)%2][1][k][2]; //prefix sum over 2nd dimension with rem color fixed at k
                        else if(c==2) dp[i%2][j][k][c] = pref[(i-1)%2][2][k][1];
                        else dp[i%2][j][k][c] = pref[(i-1)%2][3][k][1]; 
                    }
                    else
                    {
                        if(c==1) dp[i%2][j][k][c] = pref[(i-1)%2][1][j][3];
                        else if(c==2) dp[i%2][j][k][c] = pref[(i-1)%2][2][j][3];
                        else dp[i%2][j][k][c] = pref[(i-1)%2][3][j][2];
                    }
                }
        while(ptr<=m && q[ptr].r == i)
        {
            qry dq = q[ptr];
            for(int j = 0; j < i; j++)
                for(int k = 0; k < i; k++)
                    for(int c = 1; c <= 3; c++)
                    {
                        int cnt = 1;
                        cnt += (j>=dq.l);
                        cnt += (k>=dq.l);
                        if(cnt!=dq.x) dp[i%2][j][k][c]=0;
                    }
            ptr++;
        }
    }
    int ans = 0;
    for(int lc = 1; lc <= 3; lc++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
            {
                ans += dp[n%2][j][k][lc];
                ans %= MOD;
            }
    cout << ans;
}