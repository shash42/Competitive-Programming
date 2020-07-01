#include<bits/stdc++.h>
#define int long long
#define pb push
#define mp make_pair
#define pii pair<int, int>
using namespace std;
const int N=102, inf=-1e18;
int n, m, w[N][N], ans=inf, rdsum[N][N], ldsum[N][N];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		ans=inf;
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				rdsum[i][j]=ldsum[i][j]=0;
			}
		}
		cin >> n >> m;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				cin >> w[i][j];
			}
		}
		//cout << endl;
		for(int i = 0; i < n; i++)
		{
			rdsum[i][0]=w[i][0];
			ldsum[i][m-1]=w[i][m-1];
		}
		for(int i = 0; i < m; i++)
		{
			rdsum[0][i]=ldsum[0][i]=w[0][i];
		}
		for(int i = 1; i < n; i++) //prefix sum on rd
		{
			for(int j = 1; j < m; j++)
			{
				rdsum[i][j]=rdsum[i-1][j-1]+w[i][j];
			}
		}
		for(int i = 1; i < n; i++) //prefix sum on ru
		{
			for(int j = m-2; j >= 0; j--)
			{
				ldsum[i][j]=ldsum[i-1][j+1]+w[i][j];
			}
		}	
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				for(int l = 1; l <= min(i, j); l+=1)
				{
					int i2=i, j2=j-l; 
					if(i2-l<0 || j2+l>=m)
					{
						break;	
					} 
					int curr;
					if(i-l==0 || j-l==0) curr=rdsum[i][j];
					else curr=rdsum[i][j]-rdsum[i-l-1][j-l-1];
				//	cout << curr << endl;
					if(i2-l==0 || j2+l==m-1) curr+=ldsum[i2][j2];
					else curr+=ldsum[i2][j2]-ldsum[i2-l-1][j2+l+1];
				//	cout << curr << endl;
					if(l%2==0) curr-=w[i-l/2][j-l/2];
			//		cout << i << " " << j << " " << l << " - " << curr << endl;
					ans=max(ans, curr);
				} 
			}
		}
		cout << ans << endl;
	}
}