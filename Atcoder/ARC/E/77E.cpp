#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
const int N=2e5+5, INF=1e9;
using namespace std;
int n, m, a[N], ans, cntg, cntl, helps, pos;
map< pii, int> Mtg, Mtl, Mtgh, Mtlh;
signed main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 2; i <= n; i++)
    {
        if(a[i] > a[i-1])
        {
            ans += (a[i] - a[i-1]);
            Mtgh[{a[i], 1}]+=a[i]-a[i-1]-1;
            Mtg[{a[i], 1}]++;
            Mtg[{a[i-1], 0}]++;
            cntg++;
        }
        else if(a[i-1] > a[i])
        {
            ans += m - (a[i-1] - a[i]);
            Mtlh[{a[i], 1}] += m - (a[i-1] - a[i]) - 1;
            Mtl[{a[i], 1}]++;
            Mtl[{a[i-1], 0}]++;
            helps += m-a[i-1]-1;
            pos++;
            cntl++;
        }
    }
    //cout << ans << endl;
    int mx = -1;
    for(int i = 1; i <= m; i++)
    {
        pos+=Mtg[{i-2, 0}];
        pos-=Mtg[{i-1, 1}];
        helps-=Mtgh[{i-1, 1}];
        pos-=Mtl[{i-1, 1}];
        helps-=Mtlh[{i-1, 1}];
        pos+=Mtl[{i-2, 0}];
        helps+=pos;
        //cout << i << " - " << pos << " " << helps << endl;
        mx = max(mx, helps);
    }
    cout << ans - mx;
}