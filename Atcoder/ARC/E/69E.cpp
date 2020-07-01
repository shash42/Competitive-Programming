#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
const int N=1e5+5, INF=1e9;
using namespace std;
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int n, a[N], f[N], s[N], prv[N], pos[N], tot;
set< pii > st;
pii ss[N];
signed main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        tot+=a[i];
        ss[i] = {a[i], i};
    }
    sort(ss+1, ss+n+1);
    s[n+1]=0;
    for(int i = n; i >= 1; i--)
    {
        s[i] = s[i+1] + ss[i].F;
        pos[ss[i].S]=i;
    }
    st.insert({-INF, 0});
    st.insert({a[1], 1});
    int mx=a[1], mxi=1;
    for(int i = 2; i <= n; i++)
    {
        prv[i] = (*(--st.upper_bound({a[i], 0}))).S;
        prv[i] = (*(st.upper_bound({a[prv[i]], -1}))).S;
        st.insert({a[i], i});
        if(a[i]>mx)
        {
            mxi = i;
            mx = a[i];
        }
    }
    int idx = mxi, curr=0, nxt;
    while(idx!=1)
    {
        int nidx = prv[idx];
        int cnt = n - pos[nidx];
        int suffsum = s[pos[nidx]+1];
        nxt = suffsum - cnt*a[nidx];
        f[idx] = nxt - curr;
        curr = nxt;
        idx = nidx;
    }
    f[1]=tot-curr;
    for(int i = 1; i <= n; i++)
    {
        cout << f[i] << endl;
    }
}