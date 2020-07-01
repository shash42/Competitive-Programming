#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
const int N=5e5+5, INF=1e9;
using namespace std;
int n, D, q, b[N], ans = 0, d[N], pref[N];
signed main()
{
    cin >> n >> D;
    for(int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    pref[0]=D;
    for(int i = 1; i <= n; i++)
    {
        if(pref[i-1]>d[i]) pref[i] = pref[i-1] - d[i];
        else if(2*pref[i-1] > d[i]) pref[i] = abs(pref[i-1] - d[i]);
        else pref[i]=pref[i-1];
    }
    b[n]=1;
    for(int i = n-1; i >= 1; i--)
    {
        if(d[i+1]>=2*b[i+1])
        {
            b[i]=b[i+1];
        }
        else
        {
            b[i]=b[i+1]+d[i+1];
        }
        
    }
    /*for(int i = 1; i <= n; i++)
    {
        cout << pref[i] << " - " << b[i] << endl;
    }*/
    cin >> q;
    for(int i = 1; i <= q; i++)
    {
        int x;
        cin >> x;
        if(pref[x-1] >= b[x]) cout << "YES\n";
        else cout << "NO\n";
    }
}