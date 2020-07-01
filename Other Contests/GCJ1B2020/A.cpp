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
using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int N = 2e5 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

const int B = 33;
int a[2][B];
bool xn, ynn;

void ret()
{
    string ans = "";
    char ss[2][2] = {{'W', 'E'}, {'S', 'N'}};
    if(xn) swap(ss[0][0], ss[0][1]);
    if(ynn) swap(ss[1][0], ss[1][1]);
    for(int i = B - 1; i >= 0; i--)
    {
        for(int j = 0; j < 2; j++)
        {
            if(a[j][i] == -1) ans+=ss[j][0];
            else if(a[j][i] == 1) ans+=ss[j][1];
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    return;
}
void solve()
{
    memset(a, 0, sizeof(a));
    int x, y;
    cin >> x >> y;
    xn = false;
    ynn = false;
    if(x<0){
        xn=true;
        x=-x;
    }
    if(y<0){
        ynn=true;
        y=-y;
    }
    if(x%2 == y%2)
    {
        cout << "IMPOSSIBLE";
        return;
    }
    a[0][0] = x%2;
    a[1][0] = y%2;
    for(int i = 1; (1LL<<i) <= max(x, y); i++)
    {
        int xx = ((x & (1LL<<i))!=0);
        int yy = ((y & (1LL<<i))!=0);
        if(a[0][i]==1)
        {
            a[0][i]^=xx;
            if(xx) a[0][i+1]=1;
        }
        else{
            a[0][i]=xx;
        }
        if(a[1][i]==1)
        {
            a[1][i]^=(yy);
            if(yy) a[1][i+1]=1;
        }
        else{
            a[1][i] = yy;
        }
        if(a[0][i] == a[1][i])
        {
            if(a[0][i]==0)
            {
                for (int j = 0; j < 2; ++j) {
                    if(a[j][i-1]==0) continue;
                    if(a[j][i-1] > 0) {

                        a[j][i-1]=-1;
                        a[j][i]=1;
                    }
                    else
                    {
                        a[j][i-1]=1;
                        a[j][i] = -1;
                    }
                }
            }
            else
            {
                for(int j = 0; j < 2; j++){
                    if(a[j][i-1]==0) continue;
                    if(a[j][i-1]==1)
                    {
                        a[j][i+1]=1;
                        a[j][i]=0;
                        a[j][i-1]=-1;
                    }
                    else if(a[j][i-1]==-1)
                    {
                        a[j][i-1] = 1;
                        a[j][i] = 0;
                    }
                }
            }
        }
    }
    ret();
    return;
}
signed main()
{
    int T;
    cin >> T;
    int t = T;
    while(t--)
    {
        cout << "Case #" << T-t << ": ";
        solve();
        cout << endl;
    }
}