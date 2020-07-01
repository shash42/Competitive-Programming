#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define F first
#define S second
#define lint long long
#define int long long
#define mp make_pair
#define pii pair<int, int>
#define pll pair<lint, lint>
#define ld long double
#define inlld(x) scanf("%lld", &x)
#define ind(x) scanf("%d", &x)
#define vi vector<int>
#define sz(x) (int)x.size()
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int N=2e5+5, MOD=1e9+7;
const lint INF=2e18;

using namespace std;
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n, k, arr[N], pospt = 0, tmparr[N];
ordered_set<int> OS;

bool check(int x, int pr = 0)
{
    //neg-neg exact
    int ptr = n-1, cnt=0, ptrneg = pospt-1;
    for(int i = 0; i < pospt; i++)
    {
        while(ptrneg >= 0LL && tmparr[i]*tmparr[ptrneg]>=x)
        {
            ptrneg--;
        }
        int toadd = min(i, ptrneg + 1);
        cnt += toadd;
        if(pr)
        {
            cout << i << " " << ptrneg << " " << tmparr[i] << " - " << toadd << endl;
        }   
    }
    if(pr) cout << "now: pos-all" << endl;
    //pos-all exact
    for(int i = pospt; i < n; i++)
    {
        while(ptr >= 0LL && arr[i]*arr[ptr]>=x)
        {
            ptr--;
        }
        int toadd = min(i, ptr + 1);
        cnt += toadd;
        if(pr)
        {
            cout << i << " " << toadd << endl;
        }   
    }
    if(pr) cout << "Count: " << cnt << endl;
    if(cnt < k) return true;
    return false;
}

signed main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    for(int i = 0; i < n; i++)
    {
        if(arr[i]>=0)
        {
            pospt = i;
            break;
        }
        else
        {
            tmparr[i]=-arr[i];
        }
    }
    sort(tmparr, tmparr + pospt);
/*    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;*/
    int lo = -INF, hi = INF, ans;
    while(true)
    {
        if(hi-lo <= 1LL)
        {
            if(check(hi))
            {
                ans = hi;
                break;
            }
            ans = lo;
            break;
        }
        int mid = (hi+lo)/2LL;
        if(check(mid))
        {
            lo = mid;
        }
        else
        {
            hi = mid-1LL;
        }
    }
    //check(-6, 1);
    //cout << "next" << endl;
    //check(10, 1);
    cout << ans; 
}