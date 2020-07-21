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
#define SET(x, val) memset(x, val, sizeof(x))
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int M = 1600, MOD1 = 1e9 + 7, MOD2 = 998244353;
const int N=2e3+3, hmod=2147483647;
const lint INF = 1e18;

lint _add(lint x, lint y, lint MOD) {
    lint ret=x+y;
    while(ret<0LL) ret+=MOD;
    return ret;
}
lint _mult(lint x, lint y, lint MOD) {
    x%=MOD; y%=MOD;
    lint ret=x*y;
    ret%=MOD;
    while(ret<0LL) ret+=MOD;
    return ret;
}

//DOUBLE ROLLING HASH
typedef unsigned long long ull;
int rng(const int before, const int after) { // Generate random base in (before, after]
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 mt_rand(seed ^ ull(new ull)); //remove ^ ull thing for speed
    int base = std::uniform_int_distribution<int>(before+1, after)(mt_rand);
    return base; //use steady_clock() for speed, for 64 bit mt19937_64 and lint
}
//NOTE: need _add, _mult
vector<int> pow1;
vector<ull> pow2; //powers of MOD and 2^64
int base, mxlen;
void InitHash(int before, int after, int len) {
    mxlen = len; base = rng(before, after); base+=(base%2==0);
    pow1.push_back(1);  pow2.push_back((ull) 1);
    while(pow1.size()<=mxlen) {
        pow1.push_back(_mult(pow1.back(), base, hmod));
        pow2.push_back(pow2.back()*base);
    }
}
struct PolyHash { //call PolyHash::Init with range (before, after, maxlength) first. //Keep prefix
    vector<int> pref1; //NOTE: for strings always keep before > 256
    vector<ull> pref2; // (not 29 for eg) because ASCII is used
    PolyHash(string &s) {
        pref1.resize(s.length()+1); pref2.resize(s.length()+1);
        for(int i = 0; i < s.length(); i++) {
            pref1[i+1]=_add(pref1[i], _mult( (int) s[i], pow1[i], hmod), hmod);
            pref2[i+1]=pref2[i] + ((int) s[i])*pow2[i];
        }
    }
    PolyHash(int a[], int asz) {
        pref1.resize(asz+1); pref2.resize(asz+1);
        for(int i = 0; i < asz; i++) {
            pref1[i+1]=_add(pref1[i], _mult(a[i], pow1[i], hmod), hmod);
            pref2[i+1]=pref2[i] + a[i]*pow2[i];
        }
    }
    pii RangeHash(int l, int r) {//returns hash from [l, r] inclusive
        int tmplen = r-l+1;
        int hash1 = _add(pref1[r+1], -pref1[l], hmod);
        ull hash2 = pref2[r+1] - pref2[l];
        if (mxlen != 0) {
            hash1 = _mult(hash1, pow1[mxlen-(l+tmplen-1)], hmod);
            hash2 *= pow2[mxlen-(l+tmplen-1)];
        }
        return make_pair(hash1, hash2);
    }
};

int n, k, p[M];
string s, a;
set<pii> st;
void solve(){
    InitHash(257, 1e9+7, M);
    cin >> s;
    st.clear();
    n = s.length();
    PolyHash hash_s(s);
    cin >> a;
    cin >> k;
    for(int i = 1; i <= n; i++){
        p[i] = p[i-1];
        if(a[s[i-1]-'a']=='0'){
            p[i]++;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            int cnt = p[j] - p[i-1];
            if(cnt<=k){
                //cout << i << " " << j << endl;
                pii hash = hash_s.RangeHash(i-1, j-1);
                st.insert(hash);
            }
        }
    }
    cout << st.size();
}
signed main(){
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}