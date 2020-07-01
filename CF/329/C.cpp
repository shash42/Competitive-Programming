#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define fo find_by_order
#define ok order_of_key
const int N=1e5+5, MOD=1e9+7, B=8;
using namespace std;
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef unsigned long long ull;
int rng(const int before, const int after) { // Generate random base in (before, after] 
    auto seed = std::chrono::steady_clock::now().time_since_epoch().count(); 
    std::mt19937 mt_rand(seed); //remove ^ ull thing for speed
    int base = std::uniform_int_distribution<int>(before+1, after)(mt_rand);
    return base; //use steady_clock() for speed, for 64 bit mt19937_64 and lint
}
ordered_set<int> av;
struct rsrt
{
    bool operator()(const pii &a, const pii &b)
    {
        return a.S < b.S;
    }
};
int n, m, deg[N], req;
set<pii> s;
pii brej[B*B];
vector<pii> ans;
bool brute()
{
    int tot = n*(n-1)/2;
    for(int i = 0; i < (1<<tot); i++)
    {
        if(__builtin_popcount(i) != m) continue;
        ans.clear();
        for(int j = 1; j <= n; j++)
        {
            deg[j]=0;
        }
      //  cout << "test i:" << endl;
        for(int j = 0; j < tot; j++)
        {
            if((i & (1<<j)) == 0) continue;
            if(s.find({brej[j].F, brej[j].S}) != s.end()) break;
            deg[brej[j].F]++;
            deg[brej[j].S]++;
            if(deg[brej[j].F]>2) break;
            if(deg[brej[j].S]>2) break;
            ans.pb({brej[j].F, brej[j].S});
        }
        if(ans.size()==m) return true;
    }
    return false;
}
void solve()
{
    req = 2*m;
    for(int i = 1; i <= n; i++)
    {
        av.insert(i);
    }
    for(int i = 1; i <= n; i++)
    {
        if(deg[i]==2) continue;
        av.erase(i);
        int v1, v2;
        if(req==0) break;
        while(true)
        {
            v1 = rng(-1, av.size()-1);
            v1 = *av.fo(v1);
            if(s.find({i, v1})==s.end()) 
            {
                req-=2;
                deg[i]++;
                deg[v1]++;
                if(deg[v1]==2) av.erase(v1);
                s.insert({i, v1});
                s.insert({v1, i});
                ans.pb({i, v1});
                break;
            }            
        }
        if(deg[i]==2) continue;
        if(req==0) break;
        while(true)
        {
            v2 = rng(-1, av.size()-1);
            v2 = *av.fo(v2);
            if(s.find({i, v2})==s.end()) 
            {
                req-=2;
                deg[i]++;
                deg[v2]++;
                if(deg[v2]==2) av.erase(v2);
                s.insert({i, v2});
                s.insert({v2, i});
                ans.push_back({i, v2});
                break;
            }            
        }
    }
}
signed main()
{
    int cnt=0;
    for(int i = 1; i < B; i++)
    {
        for(int j = i+1; j < B; j++)
        {
            brej[cnt++]={i, j};
        }
    }
    sort(brej, brej+cnt, rsrt());
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        s.insert({x, y});
        s.insert({y, x});
    }
    if(n<B)
    {
        if(brute()==false)
        {
            cout << -1;
            return 0;
        }
    }
    else
    {
        solve();
    }
    for(auto v: ans)
    {
        cout << v.F << " " << v.S << endl;
    }
}