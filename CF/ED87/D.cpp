#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define pb push_back
#define F first
#define S second
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

const int N = 1e6 + 2;

int n, q, segt[4*N]; //16MB
void update(int idx, int l, int r, int pos, int val)
{
    if(pos<l || pos>r) return;
    if(l==r)
    {
        //cout << idx << " " << l << endl;
        segt[idx]+=val;
        return;
    }
    int mid = (l+r)/2;
    update(idx*2, l, mid, pos, val);
    update(idx*2+1, mid+1, r, pos, val);
    segt[idx]=segt[idx*2]+segt[idx*2+1];
}
int query(int idx, int l, int r, int val)
{
    //cout << idx << " " << l << " " << r << " - " << segt[idx] << " " << val << endl;
    if(val>segt[idx]) return 0;
    if(l==r)
    {
        return l;
    }
    if(segt[idx*2]<val)
    {
        val-=segt[idx*2];
        return query(idx*2+1, (l+r)/2 + 1, r, val);
    }
    return query(idx*2, l, (l+r)/2, val);
}
signed main()
{
    fastio;
    cin >> n >> q;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        update(1, 1, n, x, 1);
    }
    for(int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        if(x>0)
        {
            update(1, 1, n, x, 1);
            continue;
        }
        else
        {
            x = -x;
            int ret = query(1, 1, n, x);
           // cout << i << " " << segt[1] << " - " << ret << endl;
            update(1, 1, n, ret, -1);
        }
    }
    cout << query(1, 1, n, 1);
}