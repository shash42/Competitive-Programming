#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
const int N=1e3+5, MOD=1e9+7;
using namespace std;
int n, k, a[N], nck[N][N], ans=1;
signed main()
{
    for(int i = 0; i < N; i++)
    {
        nck[0][i]=0;
        nck[i][0]=1;
    }
    for(int i = 1; i < N; i++)
    {
        for(int j = 1; j < N; j++)
        {
            nck[i][j] = (nck[i-1][j] + nck[i-1][j-1])%MOD;
        }
    }
    cin >> k;
    int pref = 0;
    for(int i = 1; i <= k; i++)
    {
        cin >> a[i];
        pref+=1;
      //  if(a[i]==1) continue;
        ans*=nck[pref + a[i]-1 - 1][pref-1];
        //cout << i << " " << ans << endl;
        ans%=MOD;
        pref+=a[i]-1;
    }
    cout << ans;
}