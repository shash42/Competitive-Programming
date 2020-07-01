#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long
#define pb push_back
#define F first
#define S second
#define lint long long
#define mp make_pair
#define pii pair<int, int>
#define pll pair<lint, lint>
#define vi vector<int>
#define sz(x) (int)x.size()
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int N=7, MOD=1e9+7, M=1e6+6;
const lint INF=1e18;
using namespace std;
using namespace __gnu_pbds;
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int n=6, pw[N], cnt[N];
vector<int> v[M];
signed main()
{
    pw[0]=1;
    for(int i = 1; i < N; i++) pw[i]=pw[i-1]*10;
    for(int i = 0; i < pw[n]; i++)
    {
        int j = i;
        while(j>0)
        {
            v[i].pb(j%10);
            j/=10;
        }
        while(v[i].size()!=n) v[i].pb(0);
    }
    for(int i = 0; i < pw[n]; i++)
    {
        int dig=v[i][0], ccnt=1;
        for(int j = 1; j < v[i].size(); j++)
        {
            if(v[i][j]!=dig)
            {
                cnt[ccnt]++;
                dig=v[i][j];
                ccnt=1;
            }
            else
            {
                ccnt++;
            }
        }
        cnt[ccnt]++;
    }
    for(int i = 1; i <= n; i++)
    {
        cout << cnt[i] << " ";
    }
}