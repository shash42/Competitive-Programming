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

const int N=1e5+5, MOD=1e9+7;
const lint INF=1e18;

int n, m, a[N];
ofstream fil;

void binn(int x)
{
    vector<int> pr;
    while(x)
    {
        pr.pb(x%2);
        x/=2;
    }
    reverse(pr.begin(), pr.end());
    for(auto c: pr)
    {
        fil << c;
    }
}
void solve()
{
    fil.open("cb.txt");
    set<int> S;
    n = 300;
    for(int i = 1; i <= n*10; i++)
    {
        S.insert(i);
    }
    vector<int> ans;
    for(int i = 1; i <= n/3; i++)
    {
        int a = *S.begin();
        S.erase(a);
        vector<int> ignored;
        for(auto v: ans)
        {
            int d = a^v;
            if(S.find(d)!=S.end())
            {
                S.erase(d);
                ignored.pb(d);
            }
        }
        int b = *S.begin();
        int c = a^b;
        S.erase(b); S.erase(c);
        ans.pb(a); ans.pb(b); ans.pb(c);
        for(auto v: ignored) S.insert(v);
    }
    int j;
    for(int i = 0; i < ans.size(); i++)
    {
       /* if(i%3==0)
        {
            j = ans[i];
            fil << ans[i] << " ";
        }
        else if(i%3==1)
        {
            fil << ans[i] - 2*j << " ";
        }
        else
        {
            fil << ans[i] - 3*j << " ";
        }*/
        //fil << (ans[i]) << " ";
        binn(ans[i]);
        fil << " ";
        if(i%3==2) fil << endl;
    }
}
void solvee()
{
    cin >> n;
    int k = n/3;
    if(n%3==0) k--;
    int sum = 0, i, curr;
    for(i = 0; i < 30; i++)
    {
        curr = ((int)1<<(2*i));
   //     cout << curr << endl;
        if(sum + curr > k) break;
        sum += curr;
    }
    int a = curr + k - sum;
    if(n%3==1)
    {
        cout << a << endl;
        return;
    }
   // cout << curr << " - " << k << " " << sum << " " << a << endl;
    int b = curr*2;
    int j = a % curr;
    for(int jj = 2*i; jj >= 2; jj-=2)
    {
        int cur = ((int)1<<jj);
        int prv=cur/4;
        int dd = j % cur;
        dd = dd / prv;
       // cout << jj << " - " << dd << endl;
        if(dd%4==1) b+=2*prv;
        else if(dd%4==2) b+=3*prv;
        else if(dd%4==3) b+=prv;
        //cout << b << endl;
    }
    if(n%3==2)
    {
        cout << b << endl;
        return;
    }
    cout << (a^b) << endl;
}
signed main()
{
    int t = 1;
    cin >> t;
    while(t--)
    {
        solvee();
    }
}