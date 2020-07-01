#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define F first
#define S second

using namespace std;

const int N=2e5+5, b2 = 499122177;

int h[N], mod = 998244353, p2[N], pk[N], pk2[N], C[N], C2[N];

int modpow(int x, int y)
{
    if(y==0)
        return 1LL;
    if(y==1)
        return x;
    int ret=modpow(x, y/2);
    ret=ret*ret;
    ret%=mod;
    if(y%2)
        ret*=x;
    ret%=mod;
    return ret;
}

signed main()
{
    int n, k, ans=1, tans=0;
    cin >> n >> k;
    if(k==1)
    {
        cout << 0;
        return 0;
    }
    p2[0]=1, pk[0]=1, pk2[0]=1;
    for(int i = 1; i < N; i++) p2[i]=(p2[i-1]*2)%mod, pk[i]=(pk[i-1]*k)%mod, pk2[i]=(pk2[i-1]*(k-2))%mod;
    C[2] = 2;
    for(int i = 4; i < N; i+=2)     C[i]= (((((C[i-2] * (i-1))%mod) * i)%mod) * ((modpow(i/2, mod-2) * modpow(i/2, mod-2))%mod))%mod;
    for(int i = 0; i < n; i++)      cin >> h[i];
    int cnteq=0;
    for(int i = 0; i < n; i++)      if(h[i]==h[(i+1)%n]) cnteq++;
    ans=pk[cnteq];
    int y = n-cnteq;
    C2[0]=1;
    for(int i = 1; i < y; i++)      C2[i] = (((C2[i-1] * modpow(i, mod-2))%mod) * (y-i+1))%mod;
    for(int i = 0; i < y; i++)
    {
        int x = y-i;
        if(x%2)
        {
            tans+=(((p2[x-1]*pk2[i])%mod)*C2[i])%mod;
            tans%=mod;
        }
        else
        {
            tans+=((((p2[x-1]-(C[x]*b2)%mod + mod)*pk2[i])%mod)*C2[i])%mod;
            tans%=mod;
        }
    }
    ans*=tans;
    ans%=mod;
    cout << ans;
}