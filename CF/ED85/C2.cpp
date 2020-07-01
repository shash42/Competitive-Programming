
#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define pll pair<ll, ll> 
#define vi vector<int>
#define vl vector<ll> 
#define vvl vector< vector<ll> > 
#define vvi vector< vector<int> >
#define vlp vector< pair<ll, ll> >
#define vllp vector<pair<ll, ll>, ll > 
#define mll map<ll, ll> 
#define rep(i,a)  for(ll i=0; i< a; i++)
#define rep1(i,a)   for(ll i = 1; i< a; i++)
#define foi(i, a, b)    for(ll i = a; i<b ; i++)
#define fod(i, a, b)    for(ll i = a; i>=b ; i--)
#define mp make_pair
#define fst first
#define sec second
#define ff first.first
#define fs first.second
#define pi pair<int, int>
#define ppi pair<pair<int, int>, int>
#define max3(a, b, c)   max(max(a, b), c)
#define min3(a, b, c)   min(min(a, b), c)
#define MAX 1000001
#define MOD 1000000007
#define INF (ll)1e18
#define s(v) v.size()
#define e(v) v.empty()
#define bscount(x) __builtin_popcountll(x)
 
using namespace std;
 
ll gcd(ll a, ll b){if(b==0)return a;return gcd(b, a%b);}
ll lcm(ll a, ll b){return a*b/gcd(a, b);}
ll fexp(ll a, ll b){ll ans = 1;while(b){if(b&1) ans = ans*a%MOD; b/=2;a=a*a%MOD;}return ans;}
ll inverse(ll a, ll p){return fexp(a, p-2);}
// bool sortbysec(const pll &a, const pll &b){return (a.second < b.second);} 
void ingraph(vvl& graph, ll m){ll x, y;rep(i, m){cin>>x>>y;x--, y--;graph[x].pb(y);graph[y].pb(x);}}
ll modify(ll n){ll res = n;res%=MOD;res+=MOD;res%=MOD;return res;}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    // t = 1;
    while(t--){
    	ll n;
    	cin>>n;
    	vlp vec(n+1);
    	ll x, y;
    	vec[0] = {0, 0};
     	rep1(i, n+1){
    		cin>>x>>y;
    		vec[i] = {x, y};
    	}
    	bool possible = true;
    	rep1(i, n+1){
    		// cout<<vec[i].first<<" "<<vec[i].sec<<endl;
    		if(vec[i].first < vec[i-1].first)	possible = 0;
    		if(vec[i].sec < vec[i-1].sec)	possible = 0;
    		if(vec[i].sec > vec[i].first)	possible = 0;
    		if(vec[i].sec > vec[i-1].sec && vec[i].first <= vec[i-1].first)	possible = 0;
    	}
    	if(possible)	cout<<"YES";
    	else cout<<"NO";
    	cout<<endl;
    }
}