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

const int N = 1e5+5, MOD=1e9+7;
int a[N], n, m, t, x;

signed main()
{
    cin >> t;
    while(t--)
    {
        cin >> n >> x;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        sort(a+1, a+n+1);
        int p = 0, idx=0;
        for(int i = 1; i <= n; i++)
        {
            if(a[i]>=x && idx==0) idx=i;
            if(a[i]>=x) p+=a[i];
        }
        if(idx==0)
        {
            cout << 0 << endl;
            continue;
        }
        idx--;
       // cout << "i: " << idx << endl;
        int sum=0, cnt=n-idx;
        for(int i = idx; i >= 1; i--)
        {
            sum+=a[i];
            if(sum + p >= x*(cnt+1))
            {
                cnt++;
            }
            else
            {
                break;
            }
        }
        cout << cnt << endl;
    }
}