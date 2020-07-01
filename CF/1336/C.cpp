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

const int N = 3005, MOD2 = 998244353;
const lint INF = 1e18;

int automata[N][27], pi[N], n, dp[N][N], pw2[N];
string s, t, tt;
void kmp() // To check occurence of T in S , create K = T + # + S, and whenever pi[x] = |T|, it means T occurs at (x - 2*|T|) position in T.
{
    pi[0] = 0; // pi[j]=length of LONGEST PROPER prefix of substring T[0...j] which also suffix
    for(int i = 1; i < n; i++)
    {
        int j = pi[i-1] ;
        while(j > 0 and t[j] != t[i]) j = pi[j-1] ;
        if(t[i] == t[j]) j++ ; pi[i] = j ;
    }
} // BTW: The (shortest) period of a given string T is k if k | n (ie n % k == 0) where k = n - pi[n-1]
void build_automata() // t += '#' ; (is required probably)
{
    /* Automata: the state in it is the current value of the prefix function,
        and the transition from one state to another will be performed via the next character. */
    for(int i = 0; i < n; i++)
        for(char ch = 'a'; ch <= 'z'; ch++)
            automata[i][ch - 'a'] = (i > 0 and t[i] != ch) ? automata[pi[i-1]][ch - 'a'] : i + (ch == t[i]);
}
signed main()
{
    cin >> s >> tt;
    string ttr = tt;
    reverse(ttr.begin(), ttr.end());
    t = ttr;
    t += '#';
    n = t.length();
    //t += tt;
    kmp();
    build_automata();
    /*for(int i = 0; i < t.length(); i++)
    {
        cout << pi[i] << " - ";
        cout << automata[i][0] << " " << automata[i][1] << endl;
    }*/
    vi trans[N];
    pw2[0]=1;
    for(int i = 1; i < N; i++)
    {
        pw2[i] = (pw2[i-1]*2)%MOD2;
        dp[i-1][0] = pw2[i];
    }
    if(s[0] == t[0]) dp[0][1] = 1;
    for(int i = 1; i < s.length(); i++)
    {
        for(int j = 0; j < N; j++)
        {
            trans[j].clear();
        }
        if(s[i]==t[0]) trans[1].pb(0);
        for(int jj = 0; jj < N; jj++) {
            int nxt = automata[jj][s[i] - 'a']; //gives length
            trans[nxt].pb(jj);
        }
        for(int j = 1; j < t.length(); j++)
        {
            dp[i][j] = dp[i-1][j]; //put at the back
            for(auto jj: trans[j]) {
                //cout << i << " " << j << " - " << jj << endl;
                dp[i][j] += dp[i - 1][jj]; //put at the front
                dp[i][j] %= MOD2;
            }
            cout << i << " " << j << " | " << dp[i][j] << " " << endl;
        }
   //     cout << endl;
    }
    cout << dp[s.length()-1][t.length()-1];
}