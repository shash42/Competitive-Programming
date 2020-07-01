#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
const int N=1e5+5, INF=1e9;
using namespace std;
int n, ans = 0;
vector<int> v;
signed main()
{
    bool flag=false;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if(a!=b) flag=true;
        if(a<=b) ans+=b;
        else
        {
            v.pb(b);
        }
        
    }
    if(!flag)
    {
        cout << 0;
        return 0;
    }
    sort(v.begin(), v.end());
    for(int i = 1; i < v.size(); i++)
    {
        ans+=v[i];
    }
    cout << ans;
}