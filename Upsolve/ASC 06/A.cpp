#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define pb push_back
#define F first
#define S second
#define int long long
#define lint long long
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define SET(x, val) memset(x, val, sizeof(x))
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 53, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, k;
string dp[2*N][N][N];
void rest()
{
    for(int i = 0; i < 2*N; i++) for(int j = 0; j < N; j++) for(int it = 0; it < N; it++) dp[i][j][it]="-1";
}
string findSum(string str1, string str2)
{
    if (str1.length() > str2.length())
        swap(str1, str2);
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    if (carry)
        str.push_back(carry+'0');
    reverse(str.begin(), str.end());
    return str;
}
string solve(int i, int d, int m)
{
    if(d>k) return "0";
    if(i==2*n) {
        if(d==0 && m==k) return "1";
        return "0";
    }
    if(dp[i][d][m]!="-1") return dp[i][d][m];
    dp[i][d][m] = solve(i+1, d+1, max(m, d+1));
    if(d) dp[i][d][m] = findSum(dp[i][d][m], solve(i+1, d-1, m));
    return dp[i][d][m];
}
signed main()
{
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);
    int t = 1;
    while(true)
    {
        rest();
        cin >> n >> k;
        if(n+k==0) break;
        cout << "Case " << t << ": " << solve(0, 0, 0) << endl;
        cout << endl;
        t++;
    }
}