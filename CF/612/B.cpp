#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int, int>

using namespace std;

const int N=1505, K=32;

int n, k;
string a[N];
set<string> s;
char sett[3] = {'S', 'E', 'T'};
signed main()
{
	int t = 1;
	while(t--)
	{
		int cnt=0;
		cin >> n >> k;
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
			s.insert(a[i]);
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = i+1; j < n; j++)
			{
				string srch="";
				for(int itk = 0; itk < k; itk++)
				{
					if(a[i][itk]==a[j][itk])
					{
						srch+=a[i][itk];
					}
					else
					{
						for(int lol = 0; lol < 3; lol++)
						{
							if(sett[lol]!=a[i][itk] && sett[lol]!=a[j][itk])
							{
								srch+=sett[lol];
							}
						}
					}
				}
				if(s.find(srch)!=s.end()) cnt++;
			}
		}
		cout << cnt/3 << endl;
	}	
}