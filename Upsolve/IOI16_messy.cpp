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

int n, b, cnt[7];
set<int> dont;
vi vec;
string tmp="";
signed main()
{
    cin >> n;
    for(int i = 1; i <= 7; i++)
    {
        int k = (1<<i);
        k--;
        dont.insert(n-1-k);
        if(k+1==n)
        {
            b = i;
            break;
        }
    }
    for(int i = 0; i < n; i++)
    {
        tmp+='0';
        if(dont.find(i)==dont.end()) vec.pb(i);
    }
    for(int i = b; i < n; i++)
    {
        string s = tmp;
        s[i]='1';
        for(int j = 0; j < b; j++)
        {
            if((i & (1<<j))!=0)
            {
                s[j]='1';
            }
            add_element(s);
            s[j]='0';
        }
    }
    for(int i = b; i < n; i++)
    {
        string s = tmp;
        s[i]='1';
        for(int j = 0; j < b; j++)
        {
            s[j]='1';
            
        }
    }
}