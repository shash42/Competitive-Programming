#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
const int N=2e5+5, INF=1e9;
using namespace std;
int n, a[N], b[N];
signed main()
{
    int pref=0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
        a[i] = b[i] + pref;
        pref=max(pref, a[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
}