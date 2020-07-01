#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
using namespace std;
const int N=1e5+3, INF=1e9;
int n, m;
signed main()
{
    cin >> n >> m;
    cout << n*(n-1)/2 + m*(m-1)/2;
}