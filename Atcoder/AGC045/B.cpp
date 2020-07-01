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
using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e6 + 5, MOD1 = 1e9 + 7, MOD2 = 998244353;
const lint INF = 1e18;

int n, pref[N], smn[N], smx[N], mnid[N], mxid[N];
string s;
pii func(int i, int x, int y)
{
    int tmp, tpp, iff;
    tmp = x - y;
    if(tmp>0)
    {
        tpp = 1;
        iff = x;
    }
    if(tmp<=0)
    {
        tpp = 0;
        iff = y;
    }
    if(tmp==0)
    {
        if(mxid[i] < mnid[i]) tpp = 1;
    }
    return {iff, tpp};
}
bool check(int x)
{
    int off=0, prmn, prmx;
    prmn = prmx = pref[0];
    for(int i = 1; i <= n; i++)
    {

        int smno = smn[i]+off, smxo = smx[i]+off, chng=0;
        if(pref[i]==pref[i-1])
        {
            int tpz, tpo, ifz, ifo;
            pii tmp = func( i, abs(prmn - (smxo - 1)), abs(prmx - (smno - 1)) );
            ifz = tmp.F; tpz = tmp.S;
            tmp = func( i, abs(prmn - (smxo + 1)), abs(prmx - (smno + 1)) );
            ifo = tmp.F; tpo = tmp.S;
            if(ifz<=x)
            {
                chng=-1;
            }
            else if(ifo<=x)
            {
                chng=1;
            }
            else
            {
                if(x==8) cout << "la" << endl;
                if(tpo==tpz)
                {
                    cout << "lala " << tpo << endl;
                    if(tpo==0) chng=1;
                    else chng=-1;
                }
                else
                {
                    if(mnid[i] <= mxid[i])  chng=1;
                    else      chng = -1;
                }
            }
            if(x==8) cout << i << " - " << chng << " " << off+chng << endl;
        }
        off+=chng;
        if(max(abs(prmn - (pref[i] + off)), abs(prmx - (pref[i] + off))) > x)
        {
            cout << "bhoot: " << pref[i] << endl;
            return false;
        }
        prmn = min(prmn, pref[i]+off);
        prmx = max(prmx, pref[i]+off);
    }
    return true;
}
signed main()
{
    fastio;
    cin >> s;
    n = s.length();
    pref[0] = 0;
    bool isq=false;
    for(int i = 1; i <= n; i++)
    {
        pref[i]=pref[i-1];
        if(s[i-1]=='0') pref[i]--;
        else if(s[i-1]=='1') pref[i]++;
        else isq=true;
        cout << i << " " << pref[i] << endl;
    }
    if(!isq)
    {
        int mn = MOD1, mx = -MOD1;
        for(int i = 0; i <= n; i++)
        {
            mn = min(mn, pref[i]);
            mx = max(mx, pref[i]);
        }
        cout << mx - mn;
        return 0;
    }
    smn[n] = smx[n] = pref[n];
    mnid[n] = mxid[n] = n;
    for(int i = n-1; i >= 0; i--)
    {
        smn[i] = smn[i+1]; smx[i] = smx[i+1];
        mnid[i] = mnid[i+1]; mxid[i] = mxid[i+1];
        if(pref[i] <= smn[i+1])
        {
            smn[i] = pref[i];
            mnid[i] = i;
        }
        if(pref[i] >= smx[i+1])
        {
            smx[i] = pref[i];
            mxid[i] = i;
        }
    }
    int lo = 1, hi = 1e6;
    while(true)
    {
        if(hi-lo<=1)
        {
            if(check(lo))
            {
                cout << lo;
            }
            else cout << hi;
            return 0;
        }
        int mid = (lo+hi)/2;
        if(check(mid))
        {
            hi = mid;
        }
        else
        {
            cout << mid << endl;
            lo = mid+1;
        }
    }
}