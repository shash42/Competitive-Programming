#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define pf push_front
#define f first
#define int long long
#define lint long long
#define mp make_pair
#define pii pair<int, int>
#define pll pair<lint, lint>
#define ld long double
#define inlld(x) scanf("%lld", &x)
#define ind(x) scanf("%d", &x)
#define vi vector<int>

const int N=1e5+5;
const int MOD=1e9+7;
const lint INF=1e18;

lint _add(lint x, lint y)
{
    lint ret=x+y;
    while(ret<0LL)
        ret+=MOD;
    return ret;
}

lint _mult(lint x, lint y)
{
    x%=MOD;
    y%=MOD;
    lint ret=x*y;
    ret%=MOD;
    while(ret<0LL)
        ret+=MOD;
    return ret;
}

using namespace std;
using namespace __gnu_pbds;

template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n, b, g, out, prefb[N], prefg[N], cntb[N], cntg[N];
string s;
deque<char> ans;
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        out=0;
        bool swflag=false;
        cin >> s;
        b=g=0;
        while(ans.size()) ans.pop_front();
        n = s.length();
        for(int i = 0; i < n; i++)
        {
            if(s[i]=='b') b++;
            else g++;
        }
        if(g>b)
        {
            swflag=true;
            swap(b, g);
            for(int i = 0; i < n; i++)
            {
                if(s[i]=='b') s[i]='g';
                else s[i]='b';
            }
        }
        for(int i = 0; i < g; i++)
        {
            ans.pb('b');
            ans.pb('g');
        }
        b-=g;
        if(b!=0)
        {
            b--;
            ans.pb('b');
        }
        for(int i = 0; i < b; i++)
        {
            if(i%2) ans.pb('b');
            else ans.pf('b');
        }
        s="";
        for(int i = 0; i < n; i++)
        {
            s+=ans.front();
            ans.pop_front();
        }
      //  cout << s << endl;
        for(int i = 1; i <= n; i++)
        {
            cntb[i]=cntb[i-1]+(s[i-1]=='b');
            cntg[i]=cntg[i-1]+(s[i-1]=='g');
            prefb[i]=prefb[i-1]+(s[i-1]=='b')*i;
            prefg[i]=prefg[i-1]+(s[i-1]=='g')*i;
        }
        for(int i = 0; i < n; i++)
        {
            if(s[i]=='b')
            {
                out+=cntg[i]*(i+1) - prefg[i];
            }
            else
            {
                out+=cntb[i]*(i+1) - prefb[i];
            }
        }
        cout << out << endl;
    }   
	return 0;
}