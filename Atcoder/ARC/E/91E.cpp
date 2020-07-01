#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
const int N=3e5+5, INF=1e9;
using namespace std;
int n, a, b;
vector<int> v, rem;
signed main()
{
    cin >> n >> a >> b;
    if(a + b - 1 > n)
    {
        cout << -1;
        return 0;
    }
    if(a*b<n)
    {
        cout << -1;
        return 0;
    }

    for(int i = b; i >= 1; i--) //LDS
    {
        v.pb(i);
    }
    int curr = b;
    for(int i = 1; i < a; i++)
    {
        int currsz = (n - curr) / (a-i) + ((n - curr) % (a-i) != 0);
        for(int j = curr + currsz; j > curr; j--)
        {
            v.pb(j);
        }
        curr = curr+currsz;
    }
    for(auto it: v)
    {
        cout << it << " ";
    }
}   