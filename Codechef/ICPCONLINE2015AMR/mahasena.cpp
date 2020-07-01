#include<bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

int modpow(int base, int exp, int modulus) {
  base %= modulus;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

const int N=1e5+5, logN=20, M=1e9+7;
int t, n, arr[N], spf[N], cnt[N][logN], pref[N][logN];
vector<int> primes;
void spffunc()
{
	for(int i = 2; i < N; i++)
	{
		spf[i]=-1;
	}
	for(int i = 2; i < N; i++)
	{
		if(spf[i]!=-1) continue;
		primes.pb(i);
		for(int j = i; j < N; j+=i)
		{
			if(spf[j]==-1) spf[j]=i;
		}
	}
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	spffunc();
	cin >> t;
	while(t--)
	{
		int ans=1;
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < logN; j++)
			{
				pref[i][j]=cnt[i][j]=0;
			}
		}
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			cin >> arr[i];
			while(arr[i]!=1)
			{
				int cspf=spf[arr[i]], c=0;
				while(spf[arr[i]]==cspf)
				{
					arr[i]/=cspf;
					c++;
				}
				cnt[cspf][c]++;
			}
		}
		for(int i = 0; i < N; i++)
		{
			pref[i][logN-1]=0;
			for(int j = logN-2; j >= 0; j--)
			{
				pref[i][j]=pref[i][j+1];
				pref[i][j]+=cnt[i][j];
			}
		}
		for(int i = 0; i < N; i++)
		{
			for(int j = 1; j < logN; j++)
			{
				if(cnt[i][j]==0) continue;
				int multip1=modpow(2, cnt[i][j], M-1)-1;
				if(multip1<0) multip1+=M-1;
				int multip2=modpow(2, pref[i][j+1], M-1);
				ans*=modpow(i, (j*((multip1*multip2)%(M-1)))%(M-1), M);
				ans%=M;
			}
		}
		cout << ans << endl;
	}
}		