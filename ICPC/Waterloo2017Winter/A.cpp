#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;
const int N=2020;
int n;
string s;
char mat[5][N*3];
signed main()
{
	int n;
	cin >> n;
	cin >> s;

	for(int i = 0; i < 3*n; i++) mat[0][i]='*';
	
	for(int i = 0; i < n; i++)
	{
		if(s[i]=='A' || s[i]=='B' || s[i]=='D')
		{
			mat[1][i*3]=mat[1][i*3+2]='*';
			mat[1][i*3+1]='.';
		}
		else
		{
			mat[1][i*3+1]=mat[1][i*3+2]='.';
			mat[1][i*3]='*';
		}
	}

	for(int i = 0; i < n; i++)
	{
		if(s[i]=='A' || s[i]=='B' || s[i]=='E') mat[2][i*3]=mat[2][i*3+1]=mat[2][i*3+2]='*';
		else if(s[i]=='C')
		{
			mat[2][i*3+1]=mat[2][i*3+2]='.';
			mat[2][i*3]='*';
		}
		else
		{
			mat[2][i*3]=mat[2][i*3+2]='*';
			mat[2][i*3+1]='.';	
		}
	}	

	for(int i = 0; i < n; i++)
	{
		if(s[i]=='A' || s[i]=='B' || s[i]=='D')
		{
			mat[3][i*3]=mat[3][i*3+2]='*';
			mat[3][i*3+1]='.';
		}
		else
		{
			mat[3][i*3+1]=mat[3][i*3+2]='.';
			mat[3][i*3]='*';
		}
	}

	for(int i = 0; i < n; i++)
	{
		if(s[i]=='A') 
		{
			mat[4][i*3]=mat[4][i*3+2]='*';
			mat[4][i*3+1]='.';
		} 
		else mat[4][i*3]=mat[4][i*3+1]=mat[4][i*3+2]='*';
	}

	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 3*n; j++)
		{
			cout << mat[i][j];
		}
		cout << endl;
	}
}