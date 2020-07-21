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
using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5+5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, x, y, b[N], a[N], nt, mfq;
vi occ[N];
priority_queue< pii > pq;
void rest(){
    while(!pq.empty()) pq.pop();
    for(int i = 1; i <= n+1; i++){
        b[i]=a[i]=0;
        occ[i].clear();
    }
}
vi derange(vi arr){
    vector<pii> temp;
    vector<int> t2(arr.size()), ret(arr.size());
    int l = arr.size();
    for(int i = 0; i < arr.size(); i++){
        temp.pb({arr[i], i});
    }
    sort(all(temp));
    for(int i = 0; i < l; i++){
        int idx = (i - mfq + l)%l;
        t2[i] = temp[idx].F;
        ret[temp[i].S] = t2[i];
    }
    return ret;
}
void solve(){
    cin >> n >> x >> y;
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        occ[b[i]].pb(i);
    }
    for(int i = 1; i <= n+1; i++){
        if(occ[i].size()==0){
            nt = i;
            break;
        }
        pq.push({occ[i].size(), i});
    }
    for(int i = 1; i <= n-y; i++){
        pii tp = pq.top();
        pq.pop();
        int num = tp.S;
        b[occ[num].back()] = n + 1 + i;
        occ[num].pop_back();
        pq.push({occ[num].size(), num});
    }
    for(int i = 1; i <= x; i++){
        pii tp = pq.top();
        pq.pop();
        int num = tp.S;
        a[occ[num].back()] = num;
        occ[num].pop_back();
        pq.push({occ[num].size(), num});
    }
    mfq = pq.top().F;
    if(mfq > (n-x)/2){
        cout << "NO\n";
        return;
    }
    vi arr;
    for(int i = 1; i <= n; i++){
        if(a[i]==0){
           arr.pb(b[i]);
        }
    }
    cerr << arr.size() << endl;
    vi ret = derange(arr);
    int ptr = 0;
    for(int i = 1; i <= n; i++){
        if(a[i]==0){
            a[i] = ret[ptr++];
            if(a[i]>n+1) a[i]=nt;
        }
    }
    cout << "YES\n";
    for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    rest();
}
signed main(){
    fastio;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}