#include<bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

const int N=5e3+3;
int n, arr[N], prefpos[N][N], mx=-1e9, cnt=0, num=0;
signed main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			prefpos[i][j]=prefpos[i-1][j];
		}
		for(int j = arr[i-1]+1; j < n; j++)
		{
			prefpos[i][j]++;
		}
	}
	for(int i = 0; i < n; i++)
	{
		num += i - prefpos[i][arr[i]] + abs(arr[i] - prefpos[i][arr[i]]);
	}
	if(num%2) exit(7);
	num/=2;
	for(int i = 0; i < n; i++)
	{
		for(int j = i+1; j < n; j++)
		{
			int curri = i - prefpos[i][arr[i]] + abs(arr[i] - prefpos[i][arr[i]]);
			int currj = j - prefpos[j][arr[j]] + abs(arr[j] - prefpos[j][arr[j]]);
			int swapi = j - ( prefpos[j][arr[i]] + (arr[i]>arr[j]) ) + abs(arr[i] - ( prefpos[j][arr[i]] + (arr[i]>arr[j]) ) );
			int swapj = i - prefpos[i][arr[j]] + abs( arr[j] - prefpos[i][arr[j]] );
			int currr = curri + currj - (arr[i]>arr[j]);
			int swapp = swapi + swapj - (arr[j]>arr[i]);
 			int curval = currr - swapp;
 			//cout << i << " " << j << " - " << currr << " " << swapp << " " << curval << endl;
			if(curval > mx)
			{
				mx=curval;
				cnt=1;
			} 
			else if(curval==mx)
			{
				cnt++;	
			}
		}
	}
	int ans=num-mx;
	cout << ans << " " << cnt; 
}
