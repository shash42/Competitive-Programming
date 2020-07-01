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

const int N = 2e5 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int a[N], b[N], n;
priority_queue<int, vector<int>, greater<int>> st;
priority_queue<int> st2;

bool solve()
{
    while(st.size()) st.pop();
    for(int i = 1; i <= n; i++)
    {
        st.push(i+a[i]);
        b[i] = st.size();
        while(st.size() && st.top()==i) st.pop();
    }
   /* for(int i = 1; i <= n; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;*/
    while(st2.size()) st2.pop();
    for(int i = n; i >= 1; i--)
    {
        st2.push(i-a[i]);
        b[i]+=st2.size()-1;
        while(st2.size() && st2.top()==i) st2.pop();
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        a[i]=b[i];
        if(a[i]==n) cnt++;
    }
    if(cnt==n) return true;
    return false;
}
signed main()
{
    fastio;
    int k;
    cin >> n >> k;
    //n = 200000, k = 100;
    //a[1]=1;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= k; i++)
    {
        //cout << i << endl;
        bool comp = solve();
        if(comp) break;
    }
    for(int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
}