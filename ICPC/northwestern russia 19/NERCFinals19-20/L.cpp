#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define f first
#define lint long long
#define mp make_pair
#define pii pair<int, int>
#define pll pair<lint, lint>
#define ld long double
#define inlld(x) scanf("%lld", &x)
#define ind(x) scanf("%d", &x)
#define vi vector<int>

const int N=1e3+5;
const int MOD=1e9+7;
const lint INF=1e18;


using namespace std;
using namespace __gnu_pbds;

int n, l, k;
char s[N*N];
string ans[N];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> l >> k;
	for(int i = 0; i < n*l; i++)
	{
		cin >> s[i];
	}
	sort(s, s+n*l);
	int ptr=0, prev=0, pos=0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < l; j++)
		{
			ans[i]+="#";
		}
	}
	while(true)
	{
	//	cout << pos << " " << ptr << endl;
		if(pos==l) break;
		ans[prev][pos]=s[ptr];
		ptr++;
		for(int i = prev+1; i < k; i++)
		{
			if(s[ptr]!=s[ptr-1])
			{
				prev=i;
			}
			ans[i][pos]=s[ptr];
			ptr++;	
		}
		pos++;
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < l; j++)
		{
			if(ans[i][j]=='#')
			{
				ans[i][j]=s[ptr];
				ptr++;
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		cout << ans[i] << endl;
	}
}