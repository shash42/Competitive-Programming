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
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N=32, MOD=1e9+7;
const lint INF=1e18;
int d, m, s[N], pw[N];
signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> d >> m;
        pw[0]=1;
        for(int i = 1; i < N; i++)
        {
            pw[i]=pw[i-1]*2;
            pw[i]%=m;
        }
        int lst = 0, curr=1;
        while(curr <= d)
        {
            curr*=2;
            lst++;
        }
        lst--;
        //cout << lst << endl;
        pw[lst] = d - (1<<lst) + 1;
        int ans = 1;
        for(int i = 0; i <= lst; i++)
        {
            ans*=(pw[i]+1);
            ans%=m;
        }
        ans-=1;
        ans+=m;
        ans%=m;
        cout << ans << endl;
    }
}