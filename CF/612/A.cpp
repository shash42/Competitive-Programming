#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int, int>

using namespace std;

const int N=1e5+5;
int n;
string s;
signed main()
{
	int t = 1;
	cin >> t;
	while(t--)
	{
		cin >> n;
		cin >> s;
		s+='A';
		int curr=0, pos=1e6;
		for(int i = 0; i <= n; i++)
		{
			if(s[i]=='A')
			{
				curr=max(curr, i-pos-1);
				pos=i;
			}
		}
		cout << curr << endl;
	}	
}