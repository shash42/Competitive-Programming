#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define f first
#define s second
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
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 3e5+5, MOD=1e9+7;
pii a[N];
int n, m, t;
struct srt
{
    bool operator()(const int &aa, const int &b)
    {
        if(a[aa].f==a[b].f) return a[aa].s>a[b].s;
        return a[aa].f < a[b].f;
    }
};
set<int, srt> S;
signed main()
{
    cin >> t;
    while(t--)
    {
        S.clear();
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i].f >> a[i].s;
            S.insert(i);
        }
        int ans=0;
        while(S.size())
        {
            int curr = *S.begin();
            //cout << curr << endl;
            S.erase(curr);
            if(a[curr].f > 0) ans+=a[curr].f;
            if(a[(curr+1)%n].f > 0 && S.size())
            {
                S.erase((curr+1)%n);
                a[(curr+1)%n].f-=a[curr].s;
                S.insert((curr+1)%n);
            }
        }
        cout << ans << endl;
    }
}