#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
const int N=2e3+5, INF=1e9;
using namespace std;
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int n, k, q, a[N], mn=INF;
vector< pii > v;
signed main()
{
    cin >> n >> k >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        v.pb({a[i], i});
    }
    sort(v.begin(), v.end());
    for(int i = 1; i <= n; i++)
    {
        int y = a[i];
        set<int> s;
        ordered_set<int> rm;
        vector<int> tk;
        s.insert(0);
        s.insert(n+1);
        for(auto e: v)
        {
            if(e.F<y)
            {
                s.insert(e.S);
                continue;
            }
            int prv = *(--s.upper_bound(e.S));
            int nxt = *(s.upper_bound(e.S));
            prv-=rm.order_of_key(prv);
            nxt-=rm.order_of_key(nxt);
         /*   if(i==7)
            {
                cout << e.S << " - " << prv << " " << nxt << endl;
            }*/
            if(nxt-prv>k)
            {
                rm.insert(e.S);
                tk.pb(e.F);
            }
            else
            {
                s.insert(e.S);
            }
        }
        if(tk.size()>=q)
        {
            /*if(i==7)
            {
                for(auto e: tk) cout << e << " ";
                cout << endl;
            }*/
            mn = min(mn, tk[q-1] - tk[0]);
        }
    }
    cout << mn;
}