#include<bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
const int N=1e6+6, INF=1e9;
using namespace std;
char inp[N];
int a[N], b[N];
bool flag=false;
signed main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> inp[i];
        a[i] = inp[i]-'0';
    }
    for(int i = 1; i <= n-1; i++)
    {
        b[i]=abs(a[i] - a[i+1]);
        if(b[i]==1) flag=true;
    }
    if(flag)
    {
        for(int i = 1; i<= n; i++) b[i]%=2;
    }
    else
    {
        for(int i = 1; i<= n; i++) b[i]/=2;
    }
    int ans = b[n-1] ^ b[1];
    if(!flag) ans*=2;
    cout << ans;
}