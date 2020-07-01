#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

const int N=1e5+5;

int t, n, m, k;
string a, b;
int mat[27][27], suff[27][N], ans, vis[27][27];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> t;
	while(t--)
	{
		ans=0;
		memset(vis, 0, sizeof(vis));
		memset(mat, 0, sizeof(mat));
		memset(suff, 0, sizeof(suff));
		cin >> n >> m >> k;
		cin >> a >> b;
		for(int i = 0; i < 26; i++)
		{
			suff[i][m]=0;
			for(int j = m-1; j >= 0; j--)
			{
				suff[i][j]=suff[i][j+1] + (b[j]==('a'+i));
			}
		}
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < 26; j++)
			{
				mat[b[i]-'a'][j]+=suff[j][i];
			}
		}
		/*for(int i = 0; i < 26; i++)
		{
			for(int j = 0; j < 26; j++)
			{
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}*/
		for(int i = 0; i+k-1<n; i++)
		{
			if(!vis[a[i]-'a'][a[i+k-1]-'a']) ans+=mat[a[i]-'a'][a[i+k-1]-'a'];
			vis[a[i]-'a'][a[i+k-1]-'a']=1;
		}
		cout << ans << endl;
	}
}