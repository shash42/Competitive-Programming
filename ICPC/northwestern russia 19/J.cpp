#include<bits/stdc++.h>

using namespace std;

const int N = 505;

int n, mat[N][N], ans[N][N];
string inp[N];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> inp[i];
		for(int j = 0; j < n; j++)
		{
			mat[i][j]=inp[i][j]-'0';
		}
	}
	for(int i = n-2; i >= 0; i--)
	{
		for(int j = i+1; j < n; j++)
		{
			int currpaths=0;
			for(int k = i+1; k < j; k++)
			{
				if(ans[i][k]==1) currpaths+=mat[k][j];
				currpaths%=10;
			}
			if(currpaths==(mat[i][j]-1 + 10)%10)
			{
				ans[i][j]=1;
			}
			else if(currpaths!=mat[i][j])
			{
				//cout << i << " " << j << " - " << currpaths << endl; 
				return 7;
			}			
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << ans[i][j];
		}
		cout << endl;
	}
}