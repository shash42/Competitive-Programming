#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
const int N=1e5+5, INF=1e9;
using namespace std;
signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(n==1)
        {
            cout << -1 << endl;
            continue;
        }
        string ans = "";
        ans+='2';
        for(int i = 1; i < n; i++)
        {
            ans+='3';
        }
        cout << ans << endl;
    }
}