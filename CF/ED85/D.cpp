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
int a[N], n, l, r, t;
vi v;
signed main()
{
    cin >> t;
    while(t--)
    {
        cin >> n >> l >> r;
        a[0]=0;
        for(int i = 1; i <= n-1; i++)
        {
            a[i] = a[i-1] + 2*(n-i);
        }
        a[n]=a[n-1]+1;
        a[n+1] = a[n]+1;
        int lidx = 0, ridx=0;
        for(int i = 0; i <= n+1; i++)
        {
            if(a[i] >= l) break;
            lidx=i;
        }
        for(int i = 0; i <= n+1; i++)
        {
            if(a[i]>r)
            {
                ridx=i;
                break;
            }
        }
        v.clear();
  //      cout << lidx << " - " << a[lidx] << " " << ridx << " - " << a[ridx] << endl;
        for(int i = lidx; i < ridx; i++)
        {
            if(i==n)
            {
                v.pb(1);
                break;
            }
            for(int j = i+1; j < n; j++)
            {
       //         cout << i << " | " << j << endl;
                v.pb(i+1);
                v.pb(j+1);
            }
        }
      /*  for(auto vv: v)
        {
            cout << vv << " ";
        }
        cout << endl;*/
        int want = r - l + 1;
        int st = l - a[lidx] - 1;
        while(want)
        {
            cout << v[st] << " ";
            st++;
            want--;
        }
        cout << endl;
    }
}